#include "cluster.h"
#include "key.h"

typedef enum {
    CLUSTER_PASSIVE = 0,
    CLUSTER_ACTIVE
} cluster_state_t;

struct {
    key_t keys[CLUSTER_NUM_OF];
    cluster_state_t state;
    cluster_key_t current_key;
} internal = {0};


void cluster_init(cluster_cfg_t *cfg) {
    internal.keys[CLUSTER_CENTER].max_level = cfg->center_max_level;
    internal.keys[CLUSTER_CENTER].min_level = cfg->center_min_level;

    internal.keys[CLUSTER_NORTH].max_level = cfg->north_max_level;
    internal.keys[CLUSTER_NORTH].min_level = cfg->north_min_level;

    internal.keys[CLUSTER_EAST].max_level = cfg->east_max_level;
    internal.keys[CLUSTER_EAST].min_level = cfg->east_min_level;

    internal.keys[CLUSTER_SOUTH].max_level = cfg->south_max_level;
    internal.keys[CLUSTER_SOUTH].min_level = cfg->south_min_level;

    internal.keys[CLUSTER_WEST].max_level = cfg->west_max_level;
    internal.keys[CLUSTER_WEST].min_level = cfg->west_min_level;

    for (int i = 0; i < CLUSTER_NUM_OF; i++)
    {
        key_init(&internal.keys[i]);
    }

    internal.state = CLUSTER_PASSIVE;
}

int cluster_process(int *adc_readings) {
    int ret;
    int key_found = 0;

    for (int i = 0; i < CLUSTER_NUM_OF; i++)
    {
        key_process(adc_readings+i, &internal.keys[i]);
        if (internal.keys[i].state == KEY_ACTIVE) {
            key_found = 1;
            if (internal.state == CLUSTER_PASSIVE) {
                internal.state = CLUSTER_ACTIVE;
                internal.current_key = (cluster_key_t)i;
            }
        }

    }

    if (!key_found) {
        internal.state = CLUSTER_PASSIVE;
        ret = -1;
    }
    else {
        ret = internal.current_key;
    }
    return ret;
}
