#ifndef HARDWARE_REGS_SERIAL_H
#define HARDWARE_REGS_SERIAL_H

#define USART1_BASE 0x40013800
#define USART2_BASE 0x40004400
#define USART3_BASE 0x40004800
#define UART4_BASE 0x40004400


#define USART_SR 0x00
#define USART_SR_CTS 9
#define USART_SR_LBD 8
#define USART_SR_TXE 7
#define USART_SR_TC 6
#define USART_SR_RXNE 5
#define USART_SR_IDLE 4
#define USART_SR_ORE 3
#define USART_SR_NE 2
#define USART_SR_FE 1
#define USART_SR_PE 0



#define USART_DR 0x04 //Data Register - 9bits [8:0]


#define USART_BRR 0x08
#define USART_BRR_DIV_Mantissa 4 // 12bits - [15:4]
#define USART_BRR_DIV_Fraction 0 // 4bits - [3:0]



#define USART_CR1 0x0C

#define USART_CR1_UE 13
#define USART_CR1_M 12
#define USART_CR1_WAKE 11
#define USART_CR1_PCE 10
#define USART_CR1_PS 9
#define USART_CR1_PEIE 8
#define USART_CR1_TXEIE 7
#define USART_CR1_TCIE 6
#define USART_CR1_RXNEIE 5
#define USART_CR1_IDLEIE 4
#define USART_CR1_TE 3
#define USART_CR1_RE 2
#define USART_CR1_RWU 1
#define USART_CR1_SBK 0




#define USART_CR2 0x10

#define USART_CR2_LINEN 14
#define USART_CR2_STOP 12 // [13:12]
#define USART_CR2_CLKEN 11
#define USART_CR2_CPOL 10
#define USART_CR2_CPHA 9
#define USART_CR2_LBCL 8
#define USART_CR2_LBDIE 6
#define USART_CR2_LBDL 5
#define USART_CR2_ADD 0 // [3:0]



#define USART_CR3 0x14

#define USART_CR3_CTSIE 10
#define USART_CR3_CTSE 9
#define USART_CR3_RTSE 8
#define USART_CR3_DMAT 7
#define USART_CR3_DMAR 6
#define USART_CR3_SCEN 5
#define USART_CR3_NACK 4
#define USART_CR3_HDSEL 3
#define USART_CR3_IRLP 2
#define USART_CR3_IREN 1
#define USART_CR3_EIE 0



#define USART_GTPR 0x18

#define USART_GTPR_GT 8 // [15:8]
#define USART_GTPR_PSC 0 // [7:0]




#endif