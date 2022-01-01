#ifndef COM_H_
#define COM_H_

#include <stdint.h>

void com_init();

void com_send(uint8_t *buf, uint32_t len);

#endif // COM_H_
