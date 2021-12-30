/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "adc.h"

uint16_t adc_channels[16];

int main() {
    stdio_init_all();
    datn_adc_init();

    while (true) {
        datn_adc_sample(adc_channels, 16);
        for (uint32_t i = 0; i < 5; i++)
        {
            printf("%d;", adc_channels[i]);
        }
        printf("\n");
        sleep_ms(1);
    }
}
