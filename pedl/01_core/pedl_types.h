#ifndef PEDL_TYPES_H
#define PEDL_TYPES_H

#include <stdint.h>

/* Platform selection*/
#if PEDL_PLATFORM_AVR

typedef uint8_t pedl_port_t;
typedef uint8_t pedl_pin_index_t;

#else
#error "Platform not defined"

#endif

#endif