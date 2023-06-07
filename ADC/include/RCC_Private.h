#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*REGISTER DISCRIBTIONS*/
#define RCC_BASE_ADDRESS         0x40023800 
#define RCC_CR		            *((volatile u32*)(RCC_BASE_ADDRESS+0x00))
#define RCC_PLLCFGR             *((volatile u32*)(RCC_BASE_ADDRESS+0x04))
#define RCC_CFGR                *((volatile u32*)(RCC_BASE_ADDRESS+0x08))
#define RCC_AHB1ENR             *((volatile u32*)(RCC_BASE_ADDRESS+0X30))
#define RCC_AHB2ENR             *((volatile u32*)(RCC_BASE_ADDRESS+0X34))
#define RCC_APB1ENR             *((volatile u32*)(RCC_BASE_ADDRESS+0X40))
#define RCC_APB2ENR             *((volatile u32*)(RCC_BASE_ADDRESS+0X44))                *((volatile u32*)RCC_BASE_ADDRESS+0X30)


// High Speed External
#define HSE_CRYSTAL     1U //MICRO RC
// High Speed Internal	   // RC
#define HSI			    2U
// Phase Locked Loop
#define PLL             3U

#endif
