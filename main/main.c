#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_timer.h"
#include "DHTSensor.h"

#define GPIO_PIN    GPIO_NUM_14
const char *TAG = "DHT";

gpio_config_t sensorConf;

DHT11Struct dht11 = {
    .SensorConf = &sensorConf,
    .gpio_pin = GPIO_PIN,
    .humidity = 0,
    .temperature = 0,
};


void sensor_read_task(void *arg)
{
    DHT_Read(&dht11);
    ESP_LOGI(TAG, "Temperature is : %f", dht11.temperature);
    ESP_LOGI(TAG, "Temperature is : %f", dht11.humidity);  
}

void app_main(void)
{
    esp_timer_handle_t sensorReadTimer;
    esp_timer_create_args_t timerConf = {
            .arg = NULL,
            .callback = &sensor_read_task,
            .name = "Periodic DHT11 read"};
    DHT_Init(&dht11);
    esp_timer_create(&timerConf, &sensorReadTimer);
    esp_timer_start_periodic(sensorReadTimer, 500000);
}
