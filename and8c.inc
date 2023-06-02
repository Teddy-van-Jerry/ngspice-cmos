* =============================================================================
* Circuit    : CMOS AND8 Gate Type C
* Description: AND4B * 2 + AND2 * 1
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

* The following warning may be raised:
*
*   Warning: redefinition of .subckt nand2, ignored
*   Warning: redefinition of .subckt nand, ignored
*
* This is due to recursive .inc commands load the same .subckt.
* You can safely ignore these 2 warnings.

.subckt AND8C gnd i1 i2 i3 i4 i5 i6 i7 i8 o vdd
  *   src  gate drain body type
  XAND4B_1 gnd i1 i2 i3 i4 t1 vdd AND4B
  XAND4B_2 gnd i5 i6 i7 i8 t2 vdd AND4B
  XAND2    gnd t1 t2       o  vdd AND2
.ends AND8C

.inc ./and4b.inc
.inc ./and2.inc
