#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

//GPIOA Base Address --> 0x40020000 
//GPIOB Base Address --> 0x40020400 
//GPIOC Base Address --> 0x40020800 

/*Registers Description for GPIOA*/
#define GPIOA_MODER               *((volatile u32*)0x40020000)  
#define GPIOA_OTYPER              *((volatile u32*)0x40020004)   
#define GPIOA_OSPEEDR             *((volatile u32*)0x40020008)   
#define GPIOA_ODR                 *((volatile u32*)0x40020014)
#define GPIOA_BSRR                *((volatile u32*)0x40020018) 
#define GPIOA_IDR                 *((volatile u32*)0x40020010)
#define GPIOA_PUPDR               *((volatile u32*)0x4002000C)  

/*Registers Description for GPIOB*/
#define GPIOB_MODER               *((volatile u32*)0x40020400)  
#define GPIOB_OTYPER              *((volatile u32*)0x40020404)   
#define GPIOB_OSPEEDR             *((volatile u32*)0x40020408)   
#define GPIOB_ODR                 *((volatile u32*)0x40020414)
#define GPIOB_BSRR                *((volatile u32*)0x40020418) 
#define GPIOB_IDR                 *((volatile u32*)0x40020410)
#define GPIOB_PUPDR               *((volatile u32*)0x4002040C)  

/*Registers Description for GPIOC*/
#define GPIOC_MODER               *((volatile u32*)0x40020800)  
#define GPIOC_OTYPER              *((volatile u32*)0x40020804)   
#define GPIOC_OSPEEDR             *((volatile u32*)0x40020808)   
#define GPIOC_ODR                 *((volatile u32*)0x40020814)
#define GPIOC_BSRR                *((volatile u32*)0x40020818) 
#define GPIOC_IDR                 *((volatile u32*)0x40020810)
#define GPIOC_PUPDR               *((volatile u32*)0x4002080C) 

#define GPIOA                     0
#define GPIOB                     1
#define GPIOC                     2

#define PIN0                      0
#define PIN1                      1
#define PIN2                      2
#define PIN3                      3
#define PIN4                      4
#define PIN5                      5
#define PIN6                      6
#define PIN7                      7
#define PIN8                      8
#define PIN9                      9
#define PIN10                     10
#define PIN11                     11
#define PIN12                     12
#define PIN13                     13
#define PIN14                     14
#define PIN15                     15

#define INPUT					  0
#define OUTPUT					  1

#define OUTPUT_PP                 0
#define OUTPUT_OD                 1

#define OUTPUT_LS                 1 
#define OUTPUT_MS                 2 
#define OUTPUT_HS                 3 
#define OUTPUT_VHS                4 

#define INPUT_NOPUNOPD            0
#define INPUT_PU                  1
#define INPUT_PD                  2

#define SET                       0
#define RST                       1

#define LOW                       0
#define HIGH                      1

#endif
