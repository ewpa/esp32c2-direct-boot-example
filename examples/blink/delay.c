// ESP32-C2, ESP8684 direct boot, bare metal.
// delay.c
//
// Time delay routines.
//
// Copyright (C) 2023–2024 Ewan Parker.

#include "delay.h"
#include <stdint.h>

static inline void nop(volatile unsigned long count)
{
  while (count--) asm volatile("nop");
}

void delay_ms(int ms)
{
  uint32_t x = ms;
  while (--x) nop(3220); // Just an approximation.
}
