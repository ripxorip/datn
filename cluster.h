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

// The adc_readings array must be ordered
// according to the enum
int cluster_process(int *adc_readings);

#endif // CLUSTER_H_
