* =============================================================================
* Circuit    : CMOS Inverter
* Description: 1 PMOS + 1 NMOS
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt INV gnd i o vdd
  *  src  gate drain body type
  M1 vdd  i    o     vdd  PMOS_VTL W=360nm L=45nm
  M2 gnd  i    o     gnd  NMOS_VTL W=225nm L=45nm
.ends INV

.subckt NOT gnd i o vdd
  *  src  gate drain body type
  M1 vdd  i    o     vdd  PMOS_VTL W=360nm L=45nm
  M2 gnd  i    o     gnd  NMOS_VTL W=225nm L=45nm
.ends NOT
