#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

//RCC -> AHB1 
//base address 0xE000E010
#define RCC_BASE_ADDRESS 0xE000E010

#define  STK_CTRL      *((volatile u32*)(RCC_BASE_ADDRESS+0x00))
#define  STK_LOAD       *((volatile u32*)(RCC_BASE_ADDRESS+0x04))
#define  STK_VAL        *((volatile u32*)(RCC_BASE_ADDRESS+0x08))
#define  STK_CALIB      *((volatile u32*)(RCC_BASE_ADDRESS+0x0C))

//select system clock
#define AHB/8  0
#define AHB   1


// select mode interval
#define STK_SINGLE_INTERVAL     0
#define STK_PERIODIC_INTERVAL   1

#define STK_CLOCK_SOURCE    AHB/8
#endif
