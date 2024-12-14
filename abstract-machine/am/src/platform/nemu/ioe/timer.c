#include <am.h>
#include <nemu.h>

static uint64_t boot_time = 0;

static uint64_t read_time() {
  uint32_t lo = *(volatile uint32_t *)(RTC_ADDR + 0);
  uint32_t hi = *(volatile uint32_t *)(RTC_ADDR + 4);
  uint64_t time = ((uint64_t)hi << 32) | lo;
  return time / 10;
}

void __am_timer_init() {
  boot_time = read_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = read_time() - boot_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 1;
  rtc->minute = 1;
  rtc->hour   = 1;
  rtc->day    = 1;
  rtc->month  = 1;
  rtc->year   = 1900;
}
