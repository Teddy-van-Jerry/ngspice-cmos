* =============================================================================
* Circuit    : CMOS NAND4 Gate Type 
* Description: 4 PMOS + 4 NMOS (Symmetrical Design)
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt NAND4A gnd i1 i2 i3 i4 o vdd
  *   src  gate drain body type
  Mp1 vdd  i1   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp2 vdd  i2   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp3 vdd  i3   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp4 vdd  i4   o     vdd  PMOS_VTL W=360nm L=45nm
  Mn1 t1   i1   o     gnd  NMOS_VTL W=900nm L=45nm
  Mn2 t2   i2   t1    gnd  NMOS_VTL W=900nm L=45nm
  Mn3 t3   i3   t2    gnd  NMOS_VTL W=900nm L=45nm
  Mn4 gnd  i4   t3    gnd  NMOS_VTL W=900nm L=45nm
.ends NAND4A
