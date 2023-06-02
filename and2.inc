* =============================================================================
* Circuit    : CMOS AND2 Gate
* Description: NMOS2 + Inverter (3 PMOS + 3 NMOS)
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt AND2 gnd i1 i2 o vdd
  XNAND gnd i1 i2 o1 vdd NAND2
  XInv  gnd o1     o vdd INV
.ends AND2

.subckt AND gnd i1 i2 o vdd
  XNAND gnd i1 i2 o1 vdd NAND2
  XInv  gnd o1     o vdd INV
.ends AND

.inc ./nand2.inc
.inc ./inv.inc
