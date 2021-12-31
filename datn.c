#include "pico/stdlib.h"
#include "cluster.h"
#include "adc.h"

uint32_t adc_channels[16];

int main() {
    stdio_init_all();
    datn_adc_init();

    cluster_obj_t test_cluster;
    cluster_cfg_t test_cluster_cfg;

    test_cluster_cfg.center_max_level = 1824;
    test_cluster_cfg.center_min_level = 1064;

    test_cluster_cfg.north_max_level = 3183;
    test_cluster_cfg.north_min_level = 2367;

    test_cluster_cfg.east_max_level = 3183;
    test_cluster_cfg.east_min_level = 2367;

    test_cluster_cfg.south_max_level = 3183;
    test_cluster_cfg.south_min_level = 2367;

    test_cluster_cfg.west_max_level = 3183;
    test_cluster_cfg.west_min_level = 2367;

    cluster_init(&test_cluster, &test_cluster_cfg);

    while (true) {
        datn_adc_sample(adc_channels, 16);
        uint32_t key = cluster_process(&test_cluster, adc_channels);
        /*
        for (uint32_t i = 0; i < 5; i++)
        {
            printf("%d;", adc_channels[i]);
        }
        printf("\n");
        */
        sleep_ms(1);
    }
}
