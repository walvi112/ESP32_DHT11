#include <stdio.h>
#include "DHTSensor.h"
#include "rom/ets_sys.h"

void DHT_Init(DHT11Struct *dht11)
{
    dht11->SensorConf->pin_bit_mask = (1ULL << (dht11->gpio_pin)),
    dht11->SensorConf->mode = GPIO_MODE_INPUT_OUTPUT_OD;
    dht11->SensorConf->pull_down_en = GPIO_PULLDOWN_DISABLE,
    dht11->SensorConf->pull_up_en = GPIO_PULLUP_ENABLE,
    dht11->SensorConf->intr_type = GPIO_INTR_DISABLE,
    gpio_config(dht11->SensorConf);
    gpio_set_level(dht11->gpio_pin, 1);
}

esp_err_t DHT_Read(DHT11Struct *dht11)
{
    if (!gpio_get_level(dht11->gpio_pin))
        return ESP_FAIL;
    gpio_set_level(dht11->gpio_pin, 0);
    ets_delay_us(20);
    gpio_set_level(dht11->gpio_pin, 1);
    ets_delay_us(20);
}