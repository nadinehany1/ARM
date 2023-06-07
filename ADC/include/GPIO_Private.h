/*
 * GPIO_Private.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

//typedef struct GPIO
//{
//	volatile u32 MODER;
//	volatile u32 OTYPER;
//	volatile u32 OSPEEDR;
//	volatile u32 PUPDR;
//
//	volatile u32 IDR;
//	volatile u32 ODR;
//	volatile u32 BSRR;
//	volatile u32 LCKR;
//
//	volatile u32 AFRL;
//	volatile u32 AFRH;
//}GPIOx_t;
//
//#define GPIOA ((GPIOx_t*)0x40020000)

/*REGISTER DISCRIBTIONS*/
#define BASE_ADDRESSA       	0x40020000
#define GPIOA_MODER	            *((volatile u32*)(BASE_ADDRESSA+0x00))
#define GPIOA_OTYPER            *((volatile u32*)(BASE_ADDRESSA+0x04))
#define GPIOA_OSPEEDR           *((volatile u32*)(BASE_ADDRESSA+0x08))

#define GPIOA_PUPDR             *((volatile u32*)(BASE_ADDRESSA+0X0C))
#define GPIOA_IDR         	    *((volatile u32*)(BASE_ADDRESSA+0X10))
#define GPIOA_ODR               *((volatile u32*)(BASE_ADDRESSA+0X14))
#define GPIOA_BSRR              *((volatile u32*)(BASE_ADDRESSA+0x18))
#define GPIOA_LCKR              *((volatile u32*)(BASE_ADDRESSA+0X1C))
#define GPIOA_AFRL        	    *((volatile u32*)(BASE_ADDRESSA+0X20))
#define GPIOA_AFRH              *((volatile u32*)(BASE_ADDRESSA+0X24))

#define BASE_ADDRESSB       	0x40020400
#define GPIOB_MODER	            *((volatile u32*)(BASE_ADDRESSB+0x00))
#define GPIOB_OTYPER            *((volatile u32*)(BASE_ADDRESSB+0x04))
#define GPIOB_OSPEEDR           *((volatile u32*)(BASE_ADDRESSB+0x08))
#define GPIOB_PUPDR             *((volatile u32*)(BASE_ADDRESSB+0X0C))
#define GPIOB_IDR         	    *((volatile u32*)(BASE_ADDRESSB+0X10))
#define GPIOB_ODR               *((volatile u32*)(BASE_ADDRESSB+0X14))
#define GPIOB_BSRR              *((volatile u32*)(BASE_ADDRESSB+0x18))
#define GPIOB_LCKR              *((volatile u32*)(BASE_ADDRESSB+0X1C))
#define GPIOB_AFRL        	    *((volatile u32*)(BASE_ADDRESSB+0X20))
#define GPIOB_AFRH              *((volatile u32*)(BASE_ADDRESSB+0X24))

#define BASE_ADDRESSC       	0x40020800
#define GPIOC_MODER	            *((volatile u32*)(BASE_ADDRESSC+0x00))
#define GPIOC_OTYPER            *((volatile u32*)(BASE_ADDRESSC+0x04))
#define GPIOC_OSPEEDR           *((volatile u32*)(BASE_ADDRESSC+0x08))
#define GPIOC_PUPDR             *((volatile u32*)(BASE_ADDRESSC+0X0C))
#define GPIOC_IDR         	    *((volatile u32*)(BASE_ADDRESSC+0X10))
#define GPIOC_ODR               *((volatile u32*)(BASE_ADDRESSC+0X14))
#define GPIOC_BSRR              *((volatile u32*)(BASE_ADDRESSC+0x18))
#define GPIOC_LCKR              *((volatile u32*)(BASE_ADDRESSC+0X1C))
#define GPIOC_AFRL        	    *((volatile u32*)(BASE_ADDRESSC+0X20))
#define GPIOC_AFRH              *((volatile u32*)(BASE_ADDRESSC+0X24))

#define HSE_CRYSTAL    			1U
#define HSI			 			2U
#define PLL             		3U



#endif /* GPIO_PRIVATE_H_ */
