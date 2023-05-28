/*File Gaurd*/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

//RCC --> AHB1 Bus
//RCC Base Address is 0x40023800
#define RCC_BASE_ADDRESS    0x40023800

/*Register Desc.*/
#define RCC_CR           *((volatile u32*)0x40023800)
#define RCC_PLLCFGR      *((volatile u32*)0x40023804)
#define RCC_CFGR         *((volatile u32*)0x40023808)
#define RCC_AHB1ENR      *((volatile u32*)0x40023830)
#define RCC_AHB2ENR      *((volatile u32*)0x40023834)
#define RCC_APB1ENR      *((volatile u32*)0x40023840)
#define RCC_APB2ENR      *((volatile u32*)0x40023844)

#define AHB1             0
#define AHB2             1
#define APB1             2
#define APB2             3

#define HSE_CRYSTAL      0
#define HSE_RC           1
#define HSI              2
#define PLL              3

#endif
