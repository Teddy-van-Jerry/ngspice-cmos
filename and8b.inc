* =============================================================================
* Circuit    : CMOS AND8 Gate Type B
* Description: NAND4A * 2 + NOR2 * 1
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt AND8B gnd i1 i2 i3 i4 i5 i6 i7 i8 o vdd
  *   src  gate drain body type
  XNAND4A_1 gnd i1 i2 i3 i4 t1 vdd NAND4A
  XNAND4A_2 gnd i5 i6 i7 i8 t2 vdd NAND4A
  XNOR2     gnd t1 t2       o  vdd NOR2
.ends AND8B

.inc ./nand4a.inc
.inc ./nor2.inc
