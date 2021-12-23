#ifndef KEY_H_
#define KEY_H_


typedef enum {
    KEY_PASSIVE = 0,
    KEY_ACTIVE
} key_state_t;

typedef struct {
    int min_level;
    int max_level;
    int trig_level;
    int retract_level;
    key_state_t state;
} key_t;

void key_process(int *input, key_t *self);
void key_init(key_t *self);


#endif // KEY_H_
