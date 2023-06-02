* =============================================================================
* Circuit    : CMOS NOR2 Gate
* Description: 2 PMOS + 2 NMOS
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-01
* License    : MIT
* =============================================================================

.subckt NOR2 gnd i1 i2 o vdd
  *   src  gate drain body type
  Mp1 t1   i1   o     vdd  PMOS_VTL W=720nm L=45nm
  Mp2 vdd  i2   t1    vdd  PMOS_VTL W=720nm L=45nm
  Mn1 gnd  i1   o     gnd  NMOS_VTL W=225nm L=45nm
  Mn2 gnd  i2   o     gnd  NMOS_VTL W=225nm L=45nm
.ends NOR2

.subckt NOR gnd i1 i2 o vdd
  *   src  gate drain body type
  Mp1 t1   i1   o     vdd  PMOS_VTL W=720nm L=45nm
  Mp2 vdd  i2   t1    vdd  PMOS_VTL W=720nm L=45nm
  Mn1 gnd  i1   o     gnd  NMOS_VTL W=225nm L=45nm
  Mn2 gnd  i2   o     gnd  NMOS_VTL W=225nm L=45nm
.ends NOR
