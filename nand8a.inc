* =============================================================================
* Circuit    : CMOS NAND8 Gate Type A
* Description: 8 PMOS + 8 NMOS (Symmetrical Design)
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt NAND8A gnd i1 i2 i3 i4 i5 i6 i7 i8 o vdd
  *   src  gate drain body type
  Mp1 vdd  i1   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp2 vdd  i2   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp3 vdd  i3   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp4 vdd  i4   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp5 vdd  i5   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp6 vdd  i6   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp7 vdd  i7   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp8 vdd  i8   o     vdd  PMOS_VTL W=360nm L=45nm
  Mn1 t1   i1   o     gnd  NMOS_VTL W=1.8um L=45nm
  Mn2 t2   i2   t1    gnd  NMOS_VTL W=1.8um L=45nm
  Mn3 t3   i3   t2    gnd  NMOS_VTL W=1.8um L=45nm
  Mn4 t4   i4   t3    gnd  NMOS_VTL W=1.8um L=45nm
  Mn5 t5   i5   t4    gnd  NMOS_VTL W=1.8um L=45nm
  Mn6 t6   i6   t5    gnd  NMOS_VTL W=1.8um L=45nm
  Mn7 t7   i7   t6    gnd  NMOS_VTL W=1.8um L=45nm
  Mn8 gnd  i8   t7    gnd  NMOS_VTL W=1.8um L=45nm
.ends NAND8A
