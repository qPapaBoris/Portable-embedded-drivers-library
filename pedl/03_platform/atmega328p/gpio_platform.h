#ifndef PEDL_GPIO_HW_H
#define PEDL_GPIO_HW_H

#include <stdint.h>
#include <avr/io.h>
#include <stdbool.h>
#include "pedl_gpio_types.h"

#define AVR_GPIO_PORT_B 0
#define AVR_GPIO_PORT_C 1
#define AVR_GPIO_PORT_D 2

static inline void gpio_platform_set_direction(gpio_pin_t pin, gpio_direction_t dir);
static inline void gpio_platform_set(gpio_pin_t pin);
static inline void gpio_platform_clear(gpio_pin_t pin);
static inline void gpio_platform_toggle(gpio_pin_t pin);
static inline uint8_t gpio_platform_read(gpio_pin_t pin);

static volatile uint8_t *const gpio_port_reg[] =
    {
        &PORTB,
        &PORTC,
        &PORTD
    };

static volatile uint8_t *const gpio_ddr_reg[] =
    {
        &DDRB,
        &DDRC,
        &DDRD
    };

static volatile uint8_t *const gpio_pin_reg[] =
    {
        &PINB,
        &PINC,
        &PIND
    };

static inline void gpio_platform_set_direction(gpio_pin_t pin, gpio_direction_t dir)
{
    if (dir == GPIO_OUTPUT)
        *gpio_ddr_reg[pin.port] |= (1 << pin.pin);
    else
        *gpio_ddr_reg[pin.port] &= ~(1 << pin.pin);
}

static inline void gpio_platform_set(gpio_pin_t pin)
{
    *gpio_port_reg[pin.port] |= (1 << pin.pin);
}

static inline void gpio_platform_clear(gpio_pin_t pin)
{
    *gpio_port_reg[pin.port] &= ~(1 << pin.pin);
}

static inline void gpio_platform_toggle(gpio_pin_t pin)
{
    *gpio_pin_reg[pin.port] = (1 << pin.pin);
}

static inline uint8_t gpio_platform_read(gpio_pin_t pin)
{
    return ((*gpio_pin_reg[pin.port] & (1 << pin.pin)) != 0);
}

#endif