* =============================================================================
* Circuit    : CMOS AND8 Gate Type A
* Description: 8 PMOS + 8 NMOS (Symmetrical Design) + 1 Inv
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt AND8A gnd i1 i2 i3 i4 i5 i6 i7 i8 o vdd
  XNAND8a gnd i1 i2 i3 i4 i5 i6 i7 i8 o_inv vdd NAND8A
  Xinv gnd o_inv o vdd INV
.ends AND8A

.inc ./nand8a.inc
.inc ./inv.inc
