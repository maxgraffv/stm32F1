#ifndef HARDWARE_STM32
#define HARDWARE_STM32

#include "hardware/structs/flash.h"
#include "hardware/structs/rcc.h"
#include "hardware/structs/serial.h"

typedef struct stm32_hw
{
    rcc_hw_t volatile * const rcc;
    flash_hw_t volatile * const flash;
    usart2_hw_t volatile * const usart2;

} stm32_hw;

extern const stm32_hw STM32;


#endif