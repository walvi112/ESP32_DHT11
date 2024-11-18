#include <stdio.h>
#include "DHTSensor.h"
#include "rom/ets_sys.h"
#include "freertos/FreeRTOS.h"
#include "esp_log.h"

extern const char *TAG;

void DHT_Init(DHT11Struct *dht11)
{
    dht11->SensorConf->pin_bit_mask = (1ULL << (dht11->gpio_pin)),
    dht11->SensorConf->mode = GPIO_MODE_OUTPUT_OD;
    dht11->SensorConf->pull_down_en = GPIO_PULLDOWN_DISABLE,
    dht11->SensorConf->pull_up_en = GPIO_PULLUP_DISABLE,
    dht11->SensorConf->intr_type = GPIO_INTR_DISABLE,
    gpio_config(dht11->SensorConf);
    gpio_set_level(dht11->gpio_pin, 1);
}

void DHT_Read(DHT11Struct *dht11)
{
    uint64_t input = 0;
    gpio_set_direction(dht11->gpio_pin, GPIO_MODE_OUTPUT_OD);
    gpio_set_level(dht11->gpio_pin, 0);
    ets_delay_us(19000);
    gpio_set_level(dht11->gpio_pin, 1);
    gpio_set_direction(dht11->gpio_pin, GPIO_MODE_INPUT);
    ets_delay_us(40);
    if (gpio_get_level(dht11->gpio_pin))
    {
        ESP_LOGI(TAG, "Error2");
        return;
    }
    while(!gpio_get_level(dht11->gpio_pin));
    ets_delay_us(80);
    for(int i = 39; i >= 0; i--)
    {
        while(!gpio_get_level(dht11->gpio_pin));
        ets_delay_us(30);
        if(gpio_get_level(dht11->gpio_pin))
        {
            input |= (1UL<<i);
            ets_delay_us(50);
        }
    }
    ESP_LOGI(TAG, "%" PRIu64, input);
    return;
}