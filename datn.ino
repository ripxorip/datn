#include <Arduino.h>
#include <HID-Project.h>
#include "cluster.h"

void setup() {
    Serial.begin(9600);

    Keyboard.begin();

    cluster_cfg_t cfg;

    cfg.center_max_level = 442;
    cfg.center_min_level = 193;

    cfg.north_max_level = 839;
    cfg.north_min_level = 574;

    cfg.east_max_level = 839;
    cfg.east_min_level = 574;

    cfg.south_max_level = 839;
    cfg.south_min_level = 574;

    cfg.west_max_level = 839;
    cfg.west_min_level = 574;

    cluster_init(&cfg);
}

void loop() {
    static bool key_active = false;
    int adc_readings[CLUSTER_NUM_OF];
    adc_readings[CLUSTER_CENTER] = analogRead(A0);
    adc_readings[CLUSTER_NORTH] = analogRead(A3);
    adc_readings[CLUSTER_EAST] = analogRead(A2);
    adc_readings[CLUSTER_SOUTH] = analogRead(A1);
    adc_readings[CLUSTER_WEST] = analogRead(A10);

    int key = cluster_process(adc_readings);

    if (key_active) {
        if (key < 0) {
            key_active = false;
            Keyboard.releaseAll();
        }
    }
    else {
        if (key >= 0)
        {
            key_active = true;
            Serial.println(key);

            if (key == CLUSTER_CENTER)
            {
                Keyboard.press(KEY_A);
            }
            else if (key == CLUSTER_NORTH)
            {
                Keyboard.press(KEY_B);
            }
            else if (key == CLUSTER_EAST)
            {
                Keyboard.press(KEY_C);
            }
            else if (key == CLUSTER_SOUTH)
            {
                Keyboard.press(KEY_D);
            }
            else if (key == CLUSTER_WEST)
            {
                Keyboard.press(KEY_E);
            }
        }
    }
}
