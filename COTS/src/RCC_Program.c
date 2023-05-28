#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_Interface.h"
#include "../include/RCC_Private.h"
#include "../include/RCC_Config.h"

void RCC_voidInitSysClk(void)
{
    #if   RCC_SYSCLKSRC == HSE_CRYSTAL
        /*Enable HSE*/
        SET_BIT(RCC_CR, 16);
        /*Disable Bybass*/
        CLR_BIT(RCC_CR, 18);
        /*Sys Clk Source ==> HSE*/
        SET_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    #elif RCC_SYSCLKSRC == HSE_RC
        /*Enable HSE*/
        SET_BIT(RCC_CR, 16);
        /*Enable Bybass*/
        SET_BIT(RCC_CR, 18);
        /*Sys Clk Source ==> HSE*/
        SET_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    #elif RCC_SYSCLKSRC == HSI
        /*Enable HSI*/
        SET_BIT(RCC_CR, 0);
        /*Sys Clk Source ==> HSI*/
        CLR_BIT(RCC_CFGR, 0);
        CLR_BIT(RCC_CFGR, 1);
    #elif RCC_SYSCLKSRC == PLL
        /**/
        //#if PLL_CLK_INPUT == HSI

    #else
        #error "Invalid Option for Clk Source"
    #endif
}

/*Enable GPIOA, RCC_voidEnablePeripheralClk(AHB1, 0)*/
/*Copy_u8BusId: AHB1, AHB2, APB1, APB2, Copy_u8PeripheralId: 0->31*/
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    /*Input Validation*/
    if(Copy_u8PeripheralId > 31)
    {
        /*Nothing to be done*/
    }
    else
    {
        switch(Copy_u8BusId)
        {
            case AHB1:   SET_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);    break;
            case AHB2:   SET_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);    break;
            case APB1:   SET_BIT(RCC_APB1ENR, Copy_u8PeripheralId);    break;
            case APB2:   SET_BIT(RCC_APB2ENR, Copy_u8PeripheralId);    break;
            default  :                                                 break;
        }
    }
}

void RCC_voidDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
    /*Input Validation*/
    if(Copy_u8PeripheralId > 31)
    {
        /*Nothing to be done*/
    }
    else
    {
        switch(Copy_u8BusId)
        {
            case AHB1:   CLR_BIT(RCC_AHB1ENR, Copy_u8PeripheralId);    break;
            case AHB2:   CLR_BIT(RCC_AHB2ENR, Copy_u8PeripheralId);    break;
            case APB1:   CLR_BIT(RCC_APB1ENR, Copy_u8PeripheralId);    break;
            case APB2:   CLR_BIT(RCC_APB2ENR, Copy_u8PeripheralId);    break;
            default  :                                                 break;
        }
    }
}
