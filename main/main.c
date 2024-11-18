#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "DHTSensor.h"

#define GPIO_PIN    13

const char *TAG = "DHT";

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
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    ESP_LOGI(TAG, "Init");
    DHT_Read(&dht11);
    while(1);

}
