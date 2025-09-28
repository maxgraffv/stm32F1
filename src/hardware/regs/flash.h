#ifndef HARDWARE_REGS_FLASH_H
#define HARDWARE_REGS_FLASH_H


/**************************************
    FLASH
***************************************/
#define FLASH_BASE 0x40022000


/*
    FLASH_ACR - Flash access control register

    offset 0x00
    reset 0x00000030
*/
#define FLASH_ACR 0x00



#define FLASH_ACR_PRFTBS 5
/*
    0: prefetch buffer disabled
    1: prefetch buffer enabled
*/

#define FLASH_ACR_PRFTBE 4
/*
    0: prefetch disabled
    1: prefetch enabled
*/

#define FLASH_ACR_HLFCYA 3
/*
    0: half cycle disabled
    1: half cycle enabled
*/

#define FLASH_ACR_LATENCY 0
/*
    000: 0 < SYSCLK <= 24MHZ
    001: 24 < SYSCLK <= 48MHz
    010: 48 < SYSCLK <= 78MHz
*/


#endif