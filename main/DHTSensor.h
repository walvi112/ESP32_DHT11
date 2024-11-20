#ifndef DHT_SENSOR
#define DHT_SENSOR
#include "driver/gpio.h"

typedef struct DHT11Struct
{
    gpio_config_t *SensorConf;
    uint8_t gpio_pin;
    float humidity;
    float temperature;
}DHT11Struct;

void DHT_Init(DHT11Struct *dht11);
bool DHT_Read(DHT11Struct *dht11);

#endif