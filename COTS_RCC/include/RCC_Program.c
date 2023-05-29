/*
 * RCC_Program.c
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Configration.h"


void RCC_voidInitSysClk(void)
{
    #if RCC_SYSCLKSRC == HSE_CRYSTAL
    /*ENABLE HSE*/
    SET_BIT(RCC_CR,16);
    /*DISABLE BYBUS*/
    CLR_BIT(RCC_CR,18);
    /*SYS CLK SOURS*/
    SET_BIT(RCC_CR,0);
    CLR_BIT(RCC_CR,1);

    #elif RCC_SYSCLKSRC == HSE_RC
    /*ENABLE HSE*/
    SET_BIT(RCC_CR,16);
    /*ENABLE BYBUS*/
    SET_BIT(RCC_CR,18);
    /*SYS CLK SOURC*/
    SET_BIT(RCC_CR,0);
    CLR_BIT(RCC_CR,1);

    #elif RCC_SYSCLKSRC == HSI
    /*ENABLE HSI*/
    SET_BIT(RCC_CR,0);
    /*SYS CLK */
    CLR_BIT(RCC_CR,0);
    CLR_BIT(RCC_CR,1);

    #elif RCC_SYSCLKSRC == PLL
    /*TASK*/
        #error "Invalid Option for Clk Source"
    #endif
}

/*COPY_BUSID AHB1, AHB2, APB1, APB2, COPY_PERIPHRALID:0->31*/
void RCC_voidEnablePeriphral(u8 Copy_u8BusId, u8 Copy_u8PerphralId)
{
    /*INPUT VALIDATION*/
    if(Copy_u8PerphralId>31)
    {
        /*NOTHING*/
    }
    else
    {
        switch (Copy_u8BusId)
        {
        case AHB1:
            SET_BIT(RCC_AHB1ENR,Copy_u8PerphralId);
            break;
        case AHB2:
            SET_BIT(RCC_AHB1ENR,Copy_u8PerphralId);
            break;
        case APB1:
            SET_BIT(RCC_AHB1ENR,Copy_u8PerphralId);
            break;
        case APB2:
            SET_BIT(RCC_AHB1ENR,Copy_u8PerphralId);
            break;
        default:
            break;
        }
    }
}




