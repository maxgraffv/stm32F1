#ifndef HARDWARE_STRUCTS_FLASH_H
#define HARDWARE_STRUCTS_FLASH_H


#include <stdint.h>
#include "hardware/regs/flash.h"

typedef struct
{
    volatile uint32_t acr;
    volatile uint32_t keyr;
    volatile uint32_t optkeyr;
    volatile uint32_t sr;
    volatile uint32_t cr;
    volatile uint32_t ar;
    volatile uint32_t _rsvd0; 
    volatile uint32_t obr;
    volatile uint32_t wrpr;
    volatile uint32_t _rsvd1[8]; 
    volatile uint32_t keyr2; 
    volatile uint32_t _rsvd2; 
    volatile uint32_t sr2;
    volatile uint32_t cr2;
    volatile uint32_t ar2;

} flash_hw_t;

#define flash_hw ((flash_hw_t*)FLASH_BASE)



#endif