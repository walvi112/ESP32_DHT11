#ifndef DHT_SENSOR
#define DHT_SENSOR
#include "driver/gpio.h"
#include "esp_err.h"

typedef struct DHT11Struct
{
    gpio_config_t *SensorConf;
    uint8_t gpio_pin;
    float humidity;
    float temperature;
}DHT11Struct;

void DHT_Init(DHT11Struct *dht11);
esp_err_t DHTRead(DHT11Struct *dht11);

#endif