// ESP32-C2, ESP8684 direct boot, bare metal.
// blink.c
//
// Blink an LED.
//
// Copyright (C) 2023–2024 Ewan Parker.

#include "gpio.h"
#include "delay.h"
#include <stdint.h>

#define GPIO 2
#define MS 500

int main(void)
{
  gpio_set_output(GPIO);
  while (1)
  {
    gpio_write(GPIO, 1);
    delay_ms(MS);
    gpio_write(GPIO, 0);
    delay_ms(MS);
  }
  return 0;
}
