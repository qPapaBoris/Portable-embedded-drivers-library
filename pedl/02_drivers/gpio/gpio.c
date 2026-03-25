#include "gpio.h"

void gpio_init(gpio_pin_t pin, gpio_direction_t dir)
{
#if PEDL_ENABLE_ASSERT
    if (gpio_valid_pin(pin) == false)
        return;
#endif

    gpio_platform_set_direction(pin, dir);
}

void gpio_write(gpio_pin_t pin, gpio_level_t level)
{
#if PEDL_ENABLE_ASSERT
    if (gpio_valid_pin(pin) == false)
        return;
#endif

    if (level == GPIO_HIGH)
        gpio_platform_set(pin);
    else
        gpio_platform_clear(pin);
}

void gpio_toggle(gpio_pin_t pin)
{
#if PEDL_ENABLE_ASSERT
    if (gpio_valid_pin(pin) == false)
        return;
#endif

    gpio_platform_toggle(pin);
}

gpio_level_t gpio_read(gpio_pin_t pin)
{
#if PEDL_ENABLE_ASSERT
    if (gpio_valid_pin(pin) == false)
        return 0;
#endif

    return gpio_platform_read(pin);
}