#ifndef HARDWARE_STRUCTS_RCC_H
#define HARDWARE_STRUCTS_RCC_H

#include "hardware/regs/rcc.h"
#include <stdint.h>


typedef struct
{
    volatile uint32_t cr;
    volatile uint32_t cfgr;
    volatile uint32_t cir;
    volatile uint32_t apb2rstr;
    volatile uint32_t apb1rstr;
    volatile uint32_t ahbenr;
    volatile uint32_t apb2enr;
    volatile uint32_t apb1enr;
    volatile uint32_t bdcr;
    volatile uint32_t csr;


} rcc_hw_t;


#define rcc_hw ((rcc_hw_t*)RCC_BASE)


#endif