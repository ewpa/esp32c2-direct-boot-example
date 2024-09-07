// ESP32-C2, ESP8684 direct boot, bare metal. 
// gpio.c
//
// GPIO routines.
//
// Copyright (C) 2023–2024 Ewan Parker.

/*
esp8684_technical_reference_manual_en.pdf
=========================================

5.5.3 Simple GPIO Output
------------------------
GPIO matrix can also be used for simple GPIO output. For this case, one GPIO
pin can be configured to directly output desired value, without routing any
peripheral output signal to this pin. This can be done as below:

  - Set GPIO matrix GPIO_FUNCn_OUT_SEL with a special peripheral
    index 128 (0x80);

  - Set the corresponding bit in GPIO_OUT_REG register to the desired GPIO
    output value.

Note:

  - GPIO_OUT_REG[0] ~ GPIO_OUT_REG[20] correspond to GPIO0 ~ GPIO20,
    respectively. GPIO_OUT_REG[24:21] are invalid.

  - Recommended operation: use corresponding W1TS and W1TC registers, such as
    GPIO_OUT_W1TS/GPIO_OUT_ W1TC to set or clear the registers GPIO_OUT_REG.
*/

#include "gpio.h"
#include <stdint.h>

#define BIT(x) (1UL << (x))
#define REG(x) ((volatile uint32_t *) (x))

void gpio_set_output(short gpio)
{
  // GPIO_FUNC[gpio]_OUT_SEL_CFG_REG: GPIO_FUNC[gpio]_OUT_SEL = 0x80;
  REG(0x60004000 + 0x0554 + 4*gpio)[0] = 0x80;
}

void gpio_write(short gpio, short val)
{
  if (val)
    REG(0x60004024)[0] |= BIT(gpio);
  else
    REG(0x60004028)[0] |= BIT(gpio);
}
