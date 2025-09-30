#include "rcc.h"


int init_pll(stm32_hw* stm32)
{
    stm32->rcc->cr |= (1 << RCC_CR_HSEON);
    while (!(stm32->rcc->cr & RCC_CR_HSERDY)) {}

    stm32->flash->acr |= (1 << FLASH_ACR_PRFTBE) | (2 << FLASH_ACR_LATENCY);

    uint32_t cfgr = 0x00;
    cfgr |= (0 << 4); // AHB prescaler = 0
    cfgr |= (0b100 << 8); // APB low prescaler = div by 2
    cfgr |= (0 << 11); // APB high not divided
    cfgr |= (1 << RCC_CFGR_PLLSRC); // HSE as PLL source
    cfgr |= (1 << RCC_CFGR_PLLSRC); // HSE as PLL source
    cfgr |= (0b0111 << RCC_CFGR_PLLMUL); // PLL mul factor = 9

    stm32->rcc->cfgr = cfgr;

    stm32->rcc->cr |= (1 << RCC_CR_PLLON);
    while(stm32->rcc->cr & RCC_CR_PLLRDY) {}

    stm32->rcc->cfgr = (stm32->rcc->cfgr & ~0x3u) | (0b10 << RCC_CFGR_SWS);
    while (((stm32->rcc->cfgr >> 2) & 0x3u) != (0b10)) { }



}
