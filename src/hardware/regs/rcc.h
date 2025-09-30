#ifndef HARDWARE_REGS_RCC_H
#define HARDWARE_REGS_RCC_H

#define RCC_BASE 0x40021000

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




#endif