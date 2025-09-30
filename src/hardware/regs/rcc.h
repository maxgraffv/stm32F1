#ifndef HARDWARE_REGS_RCC_H
#define HARDWARE_REGS_RCC_H

/*
    RCC Base
*/
#define RCC_BASE 0x40021000


/*
    Clock Control Register
*/
#define RCC_CR 0x00

#define RCC_CR_PLLRDY 25
#define RCC_CR_PLLON 24
#define RCC_CR_CSSON 19
#define RCC_CR_HSEBYP 18
#define RCC_CR_HSERDY 17
#define RCC_CR_HSEON 16
#define RCC_CR_HSICAL 8 // [15:8]
#define RCC_CR_HSITRIM 3 // [7:3]
#define RCC_CR_HSIRDY 1
#define RCC_CR_HSION 0


/*
    Clock Configuration Register
*/
#define RCC_CFGR 0x04

#define RCC_CFGR_MCO 24 // [26:24]
#define RCC_CFGR_USBPRE 22
#define RCC_CFGR_PLLMUL 18 // [21:18]
#define RCC_CFGR_PLLXTPRE 17 
#define RCC_CFGR_PLLSRC 16 
#define RCC_CFGR_ADCPRE 14 // [15:14]
#define RCC_CFGR_PPRE2 11 // [13:11]
#define RCC_CFGR_PPRE1 8 // [10:8]
#define RCC_CFGR_HPRE 4 // [7:4]
#define RCC_CFGR_SWS 2 // [3:2]
#define RCC_CFGR_SW 0 // [1:0]


/*
    Clock Interrupt Register
*/
#define RCC_CIR 0x08




/*
    APB2 Peripheral Reset Register
*/
#define RCC_APB2RSTR 0x0C



/*
    APB1 Peripheral Reset Register
*/
#define RCC_APB1RSTR 0x10



/*
    AHB Peripheral Clock Enable Register
*/
#define RCC_AHBENR 0x14

#define RCC_AHBENR_SDIOEN 10
#define RCC_AHBENR_FSMCEN 8
#define RCC_AHBENR_CRCEN 6
#define RCC_AHBENR_FLITFEN 4
#define RCC_AHBENR_SRAMEN 2
#define RCC_AHBENR_DMA2EN 1
#define RCC_AHBENR_DMA1EN 0


/*
    APB2 Peripheral Clock Enable Register
*/
#define RCC_APB2ENR 0x18

#define RCC_APB2ENR_TIM11EN 21
#define RCC_APB2ENR_TIM10EN 20
#define RCC_APB2ENR_TIM9EN 19
#define RCC_APB2ENR_ADC3EN 15
#define RCC_APB2ENR_USART1EN 14
#define RCC_APB2ENR_TIM8EN 13
#define RCC_APB2ENR_SPI1EN 12
#define RCC_APB2ENR_TIM1EN 11
#define RCC_APB2ENR_ADC2EN 10
#define RCC_APB2ENR_ADC1EN 9
#define RCC_APB2ENR_IOPGEN 8
#define RCC_APB2ENR_IOPFEN 7
#define RCC_APB2ENR_IOPEEN 6
#define RCC_APB2ENR_IOPDEN 5
#define RCC_APB2ENR_IOPCEN 4
#define RCC_APB2ENR_IOPBEN 3
#define RCC_APB2ENR_IOPAEN 2
#define RCC_APB2ENR_AFIOEN 0


/*
    APB1 Peripheral Clock Enable Register
*/
#define RCC_APB1ENR 0x1C

#define RCC_APB1ENR_DACEN 29
#define RCC_APB1ENR_PWREN 28
#define RCC_APB1ENR_BKPEN 27
#define RCC_APB1ENR_CANEN 25
#define RCC_APB1ENR_USBEN 23
#define RCC_APB1ENR_I2C2EN 22
#define RCC_APB1ENR_I2C1EN 21
#define RCC_APB1ENR_UART5EN 20
#define RCC_APB1ENR_UART4EN 19
#define RCC_APB1ENR_USART3EN 18
#define RCC_APB1ENR_USART2EN 17
#define RCC_APB1ENR_SPI3EN 15
#define RCC_APB1ENR_SPI2EN 14
#define RCC_APB1ENR_WWDGEN 11
#define RCC_APB1ENR_TIM14EN 8
#define RCC_APB1ENR_TIM13EN 7
#define RCC_APB1ENR_TIM12EN 6
#define RCC_APB1ENR_TIM7EN 5
#define RCC_APB1ENR_TIM6EN 4
#define RCC_APB1ENR_TIM5EN 3
#define RCC_APB1ENR_TIM4EN 2
#define RCC_APB1ENR_TIM3EN 1
#define RCC_APB1ENR_TIM2EN 0

/*
    Backup Domain Control Register
*/
#define RCC_BDCR 0x20

/*
    Control/Status Register
*/
#define RCC_CSR 0x24


#endif