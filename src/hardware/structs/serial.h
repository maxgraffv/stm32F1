#ifndef HARDWARE_STRUCTS_SERIAL_H
#define HARDWARE_STRUCTS_SERIAL_H

#include <stdint.h>
#include "hardware/regs/serial.h"

typedef struct usart2_hw_t
{
    volatile uint32_t sr;
    volatile uint32_t dr;
    volatile uint32_t brr;
    volatile uint32_t cr1;
    volatile uint32_t cr2;
    volatile uint32_t cr3;
    volatile uint32_t gtpr;
} usart2_hw_t;
  
#define serial_hw ((usart2_hw_t*)USART2_BASE)





#endif