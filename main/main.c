#include <stdio.h>
#include "driver/gpio.h"
#include "DHTSensor.h"

#define GPIO_PIN    13

void app_main(void)
{
    gpio_config_t sensorConf;

    DHT11Struct dht11 = {
        .SensorConf = &sensorConf,
        .gpio_pin = GPIO_PIN,
        .humidity = 0,
        .temperature = 0,
    };

    DHT_Init(&dht11);

}
