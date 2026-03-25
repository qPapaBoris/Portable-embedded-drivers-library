#ifndef PEDL_GPIO_TYPES_H
#define PEDL_GPIO_TYPES_H

#include <stdint.h>

typedef enum
{
    GPIO_INPUT = 0,
    GPIO_OUTPUT
} gpio_direction_t;

typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH
} gpio_level_t;

typedef uint8_t gpio_port_index_t;
typedef uint8_t gpio_pin_index_t;

typedef struct
{
    gpio_port_index_t port;
    gpio_pin_index_t pin;
} gpio_pin_t;

#endif
