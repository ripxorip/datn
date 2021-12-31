#include "cluster.h"

void cluster_init(cluster_obj_t *self, cluster_cfg_t *cfg) {
    self->keys[CLUSTER_CENTER].max_level = cfg->center_max_level;
    self->keys[CLUSTER_CENTER].min_level = cfg->center_min_level;

    self->keys[CLUSTER_NORTH].max_level = cfg->north_max_level;
    self->keys[CLUSTER_NORTH].min_level = cfg->north_min_level;

    self->keys[CLUSTER_EAST].max_level = cfg->east_max_level;
    self->keys[CLUSTER_EAST].min_level = cfg->east_min_level;

    self->keys[CLUSTER_SOUTH].max_level = cfg->south_max_level;
    self->keys[CLUSTER_SOUTH].min_level = cfg->south_min_level;

    self->keys[CLUSTER_WEST].max_level = cfg->west_max_level;
    self->keys[CLUSTER_WEST].min_level = cfg->west_min_level;

    for (int i = 0; i < CLUSTER_NUM_OF; i++)
    {
        key_init(&self->keys[i]);
    }

    self->state = CLUSTER_PASSIVE;
}

int cluster_process(cluster_obj_t *self, uint32_t *adc_readings) {
    int ret;
    int key_found = 0;

    for (int i = 0; i < CLUSTER_NUM_OF; i++)
    {
        key_process(adc_readings+i, &self->keys[i]);
        if (self->keys[i].state == KEY_ACTIVE) {
            key_found = 1;
            if (self->state == CLUSTER_PASSIVE) {
                self->state = CLUSTER_ACTIVE;
                self->current_key = (cluster_key_t)i;
            }
        }

    }

    if (!key_found) {
        self->state = CLUSTER_PASSIVE;
        ret = -1;
    }
    else {
        ret = self->current_key;
    }
    return ret;
}
