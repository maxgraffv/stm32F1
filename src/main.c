
#include "stm32.h"
#include "drivers/rcc.h"
#include "drivers/serial.h"

int main()
{
    const stm32_hw *stm = &STM32;
    init_pll(stm);
    init_usart(stm);



    return 0;
}