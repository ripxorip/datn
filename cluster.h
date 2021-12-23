#ifndef CLUSTER_H_
#define CLUSTER_H_

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
    int center_min_level;
    int center_max_level;

    int north_min_level;
    int north_max_level;

    int east_min_level;
    int east_max_level;

    int south_min_level;
    int south_max_level;

    int west_min_level;
    int west_max_level;
} cluster_cfg_t;

void cluster_init(cluster_cfg_t *cfg);

// The adc_readings array must be ordered
// according to the enum
// returns -1 when no key is detected
int cluster_process(int *adc_readings);

#endif // CLUSTER_H_
