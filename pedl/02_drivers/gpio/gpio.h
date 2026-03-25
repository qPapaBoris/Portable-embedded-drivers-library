#ifndef PEDL_GPIO_H
#define PEDL_GPIO_H

#include "../../01_core/pedl_types.h"
#include "../../01_core/pedl_config.h"
#include "../../01_core/pedl_gpio_types.h"
#include "../../03_platform/atmega328p/gpio_platform.h"


#define GPIO_PIN(port, pin) ((gpio_pin_t){port, pin})

static inline bool gpio_valid_pin(gpio_pin_t pin);
void gpio_init(gpio_pin_t pin, gpio_direction_t dir);
void gpio_write(gpio_pin_t pin, gpio_level_t level);
void gpio_toggle(gpio_pin_t pin);
gpio_level_t gpio_read(gpio_pin_t pin);

static inline bool gpio_valid_pin(gpio_pin_t pin)
{
    if (pin.port >= PEDL_GPIO_PORT_COUNT)
        return false;
    if (pin.pin >= PEDL_GPIO_PINS_PER_PORT)
        return false;
    return true;
}

#endif
