#include <Arduino.h>
#include "../02_drivers/gpio/gpio.h"

gpio_pin_t led = GPIO_PIN(AVR_GPIO_PORT_B, 5);

void setup()
{
    gpio_init(led, GPIO_OUTPUT);
}

void loop()
{
    gpio_write(led, GPIO_HIGH);
    delay(500);

    gpio_write(led, GPIO_LOW);
    delay(500);
}