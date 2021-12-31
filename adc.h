#ifndef ADC_H_
#define ADC_H_

#include "pico/stdlib.h"

void datn_adc_init();

/* 32 channels at maximum */
void datn_adc_sample(uint32_t *channels, uint32_t channels_to_sample);

#endif // ADC_H_
