#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "DHTSensor.h"

#define GPIO_PIN    GPIO_NUM_14
const char *TAG = "DHT";

gpio_config_t sensorConf;

DHT11Struct dht11;

void sensor_read_task(void *arg)
{
    while(1)
    {
        vTaskDelay(500 / portTICK_PERIOD_MS);
        DHT_Read(&dht11);
        ESP_LOGI(TAG, "Temperature is : %f", dht11.temperature);
        ESP_LOGI(TAG, "Temperature is : %f", dht11.humidity);  
    }
}

void app_main(void)
{
    DHT_Init(&dht11, &sensorConf, GPIO_PIN);
    xTaskCreatePinnedToCore(sensor_read_task, "DHT11 Read", 2048, NULL, 10, NULL, 0);
}
