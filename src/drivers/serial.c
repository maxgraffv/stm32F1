#include "serial.h"

#define APB1_Hz 36000000
#define BAUD 115200

int init_usart(stm32_hw* stm)
{
    stm->rcc->apb2enr |= (1 << RCC_APB2ENR_IOPAEN);
    stm->rcc->apb2enr |= (1 << RCC_APB2ENR_AFIOEN);
    stm->rcc->apb1enr |= (1 << RCC_APB1ENR_USART2EN);

    // GPIOA HERE !!!!


    stm->usart2->brr = usart_brr_ov16(APB1_Hz, BAUD);
    stm->usart2->cr1 |= (1 << USART_CR1_TE);
    stm->usart2->cr1 |= (1 << USART_CR1_RE);
    
    

    stm->usart2->cr2 = 0x00;
    stm->usart2->cr3 = 0x00;

    stm->usart2->cr1 |= (1 << USART_CR1_UE);



}
