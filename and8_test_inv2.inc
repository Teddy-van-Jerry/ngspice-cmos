* =============================================================================
* Circuit    : Test Circuit With Capicitor Load
* Description: 2 Inverters at the Input
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.subckt INV2_TEST gnd
+                 i1 i2 i3 i4 i5 i6 i7 i8
+                 t1 t2 t3 t4 t5 t6 t7 t8
+                 out vdd
  *        gnd i  o  vdd
  XInv_ss1 gnd i1 t1 vdd INV_SS
  XInv_ss2 gnd i2 t2 vdd INV_SS
  XInv_ss3 gnd i3 t3 vdd INV_SS
  XInv_ss4 gnd i4 t4 vdd INV_SS
  XInv_ss5 gnd i5 t5 vdd INV_SS
  XInv_ss6 gnd i6 t6 vdd INV_SS
  XInv_ss7 gnd i7 t7 vdd INV_SS
  XInv_ss8 gnd i8 t8 vdd INV_SS
  * Load
  CL out gnd 24fF
.ends INV2_TEST

.subckt INV_SS gnd i o vdd
  XInv_s1 gnd i t vdd INV_S
  XInv_s2 gnd t o vdd INV_S
.ends

* Inverter used in the test circuit
.subckt INV_S gnd i o vdd
  *  src  gate drain body type
  M1 vdd  i    o     vdd  PMOS_VTL W=0.75um L=0.25um
  M2 gnd  i    o     gnd  NMOS_VTL W=2.60um L=0.25um
.ends INV_S
