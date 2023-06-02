* =============================================================================
* Script     : Measure AND8 Gate Static and Dynamic Power
* Description: Measure the power for device 'xand8'.
*
* Author     : Wuqiong Zhao (me@wqzhao.org)
* Date       : 2023-06-02
* License    : MIT
* =============================================================================

.probe P(XAND8)
.control
  * Total power
  let p_total   = mean(xand8:power)
  * Static power (average of high and low)
  let p_static  =
  + (
  +   mean(xand8:power[length(xand8:power) / 6, length(xand8:power) / 3]) +
  +   mean(xand8:power[length(xand8:power) / 2, length(xand8:power) / 1.5])
  + ) / 2
  * Dynamic power (difference of total power and static power)
  let p_dynamic = p_total - p_static
  print p_total
  print p_static
  print p_dynamic
.endc
