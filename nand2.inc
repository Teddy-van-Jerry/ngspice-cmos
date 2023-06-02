* =============================================================================
* Circuit    : CMOS NAND2 Gate
* Description: 2 PMOS + 2 NMOS
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-01
* License    : MIT
* =============================================================================

.subckt NAND2 gnd i1 i2 o vdd
  *   src  gate drain body type
  Mp1 vdd  i1   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp2 vdd  i2   o     vdd  PMOS_VTL W=360nm L=45nm
  Mn1 t1   i1   o     gnd  NMOS_VTL W=450nm L=45nm
  Mn2 gnd  i2   t1    gnd  NMOS_VTL W=450nm L=45nm
.ends NAND2

.subckt NAND gnd i1 i2 o vdd
  *   src  gate drain body type
  Mp1 vdd  i1   o     vdd  PMOS_VTL W=360nm L=45nm
  Mp2 vdd  i2   o     vdd  PMOS_VTL W=360nm L=45nm
  Mn1 t1   i1   o     gnd  NMOS_VTL W=450nm L=45nm
  Mn2 gnd  i2   t1    gnd  NMOS_VTL W=450nm L=45nm
.ends NAND
