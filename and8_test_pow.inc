* =============================================================================
* Script     : Measure AND8 Gate Static and Dynamic Power
* Description: Measure the power for devie xand8.
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.probe P(XAND8)
.control
  * Total power
  let p_total   = mean(xand8:power)
  * Static power (from 0 to 1 ns)
  let p_static  = mean(xand8:power[1, length(xand8:power) / 3])
  * Dynamic power (difference of total power and static power)
  let p_dynamic = p_total - p_static
  print p_total
  print p_static
  print p_dynamic
.endc
