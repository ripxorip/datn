#include "key.h"

void key_init(key_t *self){
    /* FIXME trig and retract may be variable in the future? */
    self->trig_level = self->min_level + (uint32_t)((float)(self->max_level - self->min_level)*0.50f);
    self->retract_level = self->min_level + (uint32_t)((float)(self->max_level - self->min_level)*0.25f);
    self->state = KEY_PASSIVE;
}

void key_process(uint32_t *input, key_t *self) {
    switch (self->state)
    {
        case KEY_PASSIVE:
            if (*input > self->trig_level)
            {
                self->state = KEY_ACTIVE;
            }
            break;
        case KEY_ACTIVE:
            if (*input < self->retract_level)
            {
                self->state = KEY_PASSIVE;
            }
            break;
    default:
        break;
    }

}
