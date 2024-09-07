// ESP32-C2, ESP8684 direct boot, bare metal.
// gpio.h
//
// GPIO routines.
//
// Copyright (C) 2023–2024 Ewan Parker.

#pragma once

void gpio_set_output(short gpio);
void gpio_write(short gpio, short val);
