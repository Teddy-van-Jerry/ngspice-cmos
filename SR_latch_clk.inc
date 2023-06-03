* =============================================================================
* Circuit    : Clock Controlled SR Latch
* Description: 2 PMOS + 6 NMOS
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-03
* License    : MIT
* =============================================================================

* .param WL = 5
.subckt SR_LATCH_CLK gnd s r clk q qn vdd
  *  src  gate drain body type
  M1 qn   q    gnd   gnd  NMOS_VTL W=     90nm L=45nm
  M2 qn   q    vdd   vdd  PMOS_VTL W=    270nm L=45nm
  M3 q    qn   gnd   gnd  NMOS_VTL W=     90nm L=45nm
  M4 q    qn   vdd   vdd  PMOS_VTL W=    270nm L=45nm
  M5 ts   s    gnd   gnd  NMOS_VTL W={WL*45nm} L=45nm
  M6 qn   clk  ts    gnd  NMOS_VTL W={WL*45nm} L=45nm
  M7 tr   r    gnd   gnd  NMOS_VTL W={WL*45nm} L=45nm
  M8 q    clk  tr    gnd  NMOS_VTL W={WL*45nm} L=45nm
.ends SR_LATCH_CLK
