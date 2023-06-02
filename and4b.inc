* =============================================================================
* Circuit    : CMOS AND4 Gate Type B
* Description: NAND2 * 2 + NOR * 1
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt AND4B gnd i1 i2 i3 i4 o vdd
  *   src  gate drain body type
  XNAND2_1 gnd i1 i2 t1 vdd NAND2
  XNAND2_2 gnd i3 i4 t2 vdd NAND2
  XNOR     gnd t1 t2 o  vdd NOR2
.ends AND4B

.inc ./nand2.inc
.inc ./nor2.inc
