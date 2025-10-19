#include "stm32.h"



const stm32_hw STM32 = {
    .rcc = (rcc_hw_t*) RCC_BASE,
    .flash = (flash_hw_t*) FLASH_BASE,
    .usart2 = (usart2_hw_t*) USART2_BASE,
};