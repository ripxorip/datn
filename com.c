#include "com.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#define SLAVE_ADDRESS 0x5

void com_init() {
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(0, GPIO_FUNC_I2C);
    gpio_set_function(1, GPIO_FUNC_I2C);
    bi_decl(bi_2pins_with_func(0, 1, GPIO_FUNC_I2C));
}


void com_send(uint8_t *buf, uint32_t len) {
    /* The first byte shall be the register start address */
    i2c_write_blocking(i2c0, SLAVE_ADDRESS, buf, len, true);
}
