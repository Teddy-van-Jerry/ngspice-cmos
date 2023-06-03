# NGSPICE Simulation of CMOS Circuits <!-- omit in toc -->

- GitHub: [Teddy-van-Jerry/ngspice-cmos](https://github.com/Teddy-van-Jerry/ngspice-cmos)
- Website: [spice.tvj.one](https://spice.tvj.one)
- PDF Report: [`NGSPICE_CMOS_Report.pdf`](report/NGSPICE_CMOS_Report.pdf)

**Table of Contents**
- [Summary](#summary)
- [Environments](#environments)
  - [Preparation](#preparation)
  - [Settings](#settings)
  - [Development](#development)
- [Sources](#sources)
  - [`FreePDK45/`](#freepdk45)
  - [Inverter](#inverter)
    - [Design](#design)
    - [Simulation](#simulation)
  - [NAND2](#nand2)
    - [Design](#design-1)
    - [Simulation](#simulation-1)
  - [AND2](#and2)
  - [NOR2](#nor2)
  - [NAND8](#nand8)
  - [AND8](#and8)
    - [AND8a (Symmetrical Design)](#and8a-symmetrical-design)
    - [AND8b (NAND4A \* 2 + NOR2 \* 1)](#and8b-nand4a--2--nor2--1)
    - [AND8c (AND4B \* 2 + AND2 \* 1)](#and8c-and4b--2--and2--1)
  - [Clock Controlled SR Latch](#clock-controlled-sr-latch)
    - [Schematic Design](#schematic-design)
    - [MOS W/L Design](#mos-wl-design)
    - [Simulation](#simulation-2)
- [License](#license)

## Summary
SPICE simulation of CMOS Circuits using open-source NGSPICE.

> **Note** This is the course project of *Fundamentals of VLSI Design*, Southeast University, 2023 Spring.

## Environments
### Preparation
Install [NGSPICE](https://ngspice.sourceforge.io/) CLI app.

### Settings
NGSPICE is set to be compatible with HSPICE (see [`.spiceinit`](.spiceinit)).

### Development
My development environments:
- macOS 13 (Ventura) with M1 chip
- NGSPICE 40 (Homebrew version)

> **Warning** There is *no* guarantee that the provided code can run on other platforms or other SPICE tools.
> Make changes if appropriate.

## Sources
### `FreePDK45/`
This is a 45nm CMOS library.
See [README](FreePDK45/README) for more information.

### Inverter
Inverter with 1 PMOS and 1 NMOS.
(Design Requirement: tr = tf when CL = 24fF)

- [`inv.inc`](inv.inc) is the `subckt` design;
- [`inv.cir`](inv.cir) is the CMOS inverter simulation.

#### Design

**Schematic**

![CMOS Inverter Schematic](fig/inv_schematic.svg)

**Designed MOS Parameters**

|  MOS  |   W   |   L   |
| :---: | :---: | :---: |
| PMOS  | 360nm | 45nm  |
| NMOS  | 225nm | 45nm  |

tr = 119ps, tf = 120ps, tpdr = 60ps, tpdf = 64ps, tpd = 62ps.

**Source** [`inv.inc`](inv.inc)

```spice
.subckt INV gnd i o vdd
  *  src  gate drain body type
  M1 vdd  i    o     vdd  PMOS_VTL W=360nm L=45nm
  M2 gnd  i    o     gnd  NMOS_VTL W=225nm L=45nm
.ends INV
```

#### Simulation

Simulate with
```shell
ngspice inv.cir
```

**Response**

![CMOS Inverter Response](fig/plot_inv_t.svg)

### NAND2

#### Design
The CMOS NAND2 gate is symmetrically designed with parameters for the worst case.

**Designed MOS Parameters**

|  MOS  | Num |   W   |   L   |
| :---: | :-: | :---: | :---: |
| PMOS  |  2  | 360nm | 45nm  |
| NMOS  |  2  | 450nm | 45nm  |

**Source** [`nand2.inc`](nand2.inc)

```spice
.subckt NAND2 gnd i1 i2 o vdd
  *   src  gate drain body type
  Mp1 vdd  i1   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp2 vdd  i2   o     vdd  PMOS_VTL W=360nm L=45nm
  Mn1 t1   i1   o     gnd  NMOS_VTL W=450nm L=45nm
  Mn2 gnd  i2   t1    gnd  NMOS_VTL W=450nm L=45nm
.ends NAND2
```

#### Simulation

The worst case is simulated. Simulate with
```shell
ngspice nand2.cir
```

**Response**
![CMOS NAND2 Response](fig/plot_nand2_t.svg)

### AND2

**Response**
![CMOS AND2 Response](fig/plot_and2_t.svg)

### NOR2

**Response**
![CMOS NOR2 Response](fig/plot_nor2_t.svg)

### NAND8

### AND8

#### AND8a (Symmetrical Design)

- Latency = 90.5ps
- P_static = 0.662uW
- P_dynamic = 2.99uW

**Response**

![CMOS AND8a Response](fig/plot_and8a_t.svg)

#### AND8b (NAND4A * 2 + NOR2 * 1)

- Latency = 63.6ps
- P_static = 0.358uW
- P_dynamic = 3.59uW

**Response**

![CMOS AND8b Response](fig/plot_and8b_t.svg)

#### AND8c (AND4B * 2 + AND2 * 1)

- Latency = 66.1ps
- P_static = 0.856uW
- P_dynamic = 5.69uW

**Response**

![CMOS AND8c Response](fig/plot_and8c_t.svg)


### Clock Controlled SR Latch

#### Schematic Design

2 PMOS + 6 NMOS

**Source** [`SR_latch_clk.inc`](SR_latch_clk.inc)
```
* .param WL = 5
.subckt SR_LATCH_CLK gnd s r clk q qn vdd
  *  src  gate drain body type
  M1 qn   q    gnd   gnd  NMOS_VTL W=     90nm L=45nm
  M2 qn   q    vdd   vdd  PMOS_VTL W=    270nm L=45nm
  M3 q    qn   gnd   gnd  NMOS_VTL W=     90nm L=45nm
  M4 q    qn   vdd   vdd  PMOS_VTL W=    270nm L=45nm
  M5 ts   s    gnd   gnd  NMOS_VTL W={WL*45nm} L=45nm
  M6 qn   clk  ts    gnd  NMOS_VTL W={WL*45nm} L=45nm
  M7 tr   r    gnd   gnd  NMOS_VTL W={WL*45nm} L=45nm
  M8 q    clk  tr    gnd  NMOS_VTL W={WL*45nm} L=45nm
.ends SR_LATCH_CLK
```
You need to specify the parameter `WL`, for example `.param WL = 5`.

#### MOS W/L Design

Using a sweep, implemented by `alterparam` within a `foreach` loop,
we can obtain the following graph.

![Clock Controlled SR Latch with Different W/L](fig/plot_sr_latch_wl_t.svg)

Clearly, we need W/L > 4.5 (at least 4.2) for the latch to work properly.

#### Simulation

```sh
ngspice ./SR_latch_clk.cir
```

**Response**

![Clock Controlled SR Latch](fig/plot_sr_latch_t.svg)

## License
Copyright (C) 2023 Wuqiong Zhao (me@wqzhao.org)

This project is distributed by an [MIT license](LICENSE).
