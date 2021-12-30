#include "adc.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

const int channel_truth_table[16][4] = {
  // s0, s1, s2, s3     channel
    {0,  0,  0,  0}, // 0
    {1,  0,  0,  0}, // 1
    {0,  1,  0,  0}, // 2
    {1,  1,  0,  0}, // 3
    {0,  0,  1,  0}, // 4
    {1,  0,  1,  0}, // 5
    {0,  1,  1,  0}, // 6
    {1,  1,  1,  0}, // 7
    {0,  0,  0,  1}, // 8
    {1,  0,  0,  1}, // 9
    {0,  1,  0,  1}, // 10
    {1,  1,  0,  1}, // 11
    {0,  0,  1,  1}, // 12
    {1,  0,  1,  1}, // 13
    {0,  1,  1,  1}, // 14
    {1,  1,  1,  1}  // 15
};

static void select_channel(uint32_t channel) {
    gpio_put(2, channel_truth_table[channel][0]);
    gpio_put(3, channel_truth_table[channel][1]);
    gpio_put(4, channel_truth_table[channel][2]);
    gpio_put(5, channel_truth_table[channel][3]);
}

void datn_adc_init(){
    gpio_init(2);
    gpio_init(3);
    gpio_init(4);
    gpio_init(5);
    gpio_init(21);

    gpio_set_dir(2, GPIO_OUT);
    gpio_set_dir(3, GPIO_OUT);
    gpio_set_dir(4, GPIO_OUT);
    gpio_set_dir(5, GPIO_OUT);

    /* Set the en pin */
    gpio_set_dir(21, GPIO_OUT);
    /* Make it on all the time */
    gpio_put(21, 0);

    adc_init();
    adc_gpio_init(26);
    adc_select_input(0);
}

/* 32 channels at maximum */
void datn_adc_sample(uint16_t *channels, uint32_t channels_to_sample) {
    for (uint32_t i = 0; i < channels_to_sample; i++)
    {
        select_channel(i);
        sleep_us(1); // Not sure if this is needed since 6ns is needed according to datasheet
        channels[i] = adc_read();
    }
}
