#ifndef CLUSTER_H_
#define CLUSTER_H_

#include <stdint.h>
#include "key.h"

typedef enum {
    CLUSTER_CENTER = 0,
    CLUSTER_NORTH,
    CLUSTER_EAST,
    CLUSTER_SOUTH,
    CLUSTER_WEST,
    CLUSTER_NUM_OF
} cluster_key_t;

typedef struct
{
    uint32_t center_min_level;
    uint32_t center_max_level;

    uint32_t north_min_level;
    uint32_t north_max_level;

    uint32_t east_min_level;
    uint32_t east_max_level;

    uint32_t south_min_level;
    uint32_t south_max_level;

    uint32_t west_min_level;
    uint32_t west_max_level;
} cluster_cfg_t;

typedef enum {
    CLUSTER_PASSIVE = 0,
    CLUSTER_ACTIVE
} cluster_state_t;

typedef struct {
    key_t keys[CLUSTER_NUM_OF];
    cluster_state_t state;
    cluster_key_t current_key;
} cluster_obj_t;

void cluster_init(cluster_obj_t *self, cluster_cfg_t *cfg);

// The adc_readings array must be ordered
// according to the enum
// returns -1 when no key is detected
int cluster_process(cluster_obj_t *self, uint32_t *adc_readings);

#endif // CLUSTER_H_
