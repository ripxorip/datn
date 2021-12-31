#ifndef KEY_H_
#define KEY_H_

#include <stdint.h>

typedef enum {
    KEY_PASSIVE = 0,
    KEY_ACTIVE
} key_state_t;

typedef struct {
    uint32_t min_level;
    uint32_t max_level;
    uint32_t trig_level;
    uint32_t retract_level;
    key_state_t state;
} key_t;

void key_process(uint32_t *input, key_t *self);
void key_init(key_t *self);


#endif // KEY_H_
