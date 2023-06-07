/*
 * GPIO_Program.c
 *
 *  Created on: 12/5/2023
 *      Author: Nadine Hany
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_Config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

/*Funcions GPIOA,APIOB,GPIOC*/
/*INPUT,OUT,ALTERNATIVE FUNC , ANALOG*/


/*Functions Prototypes*/
/****************************************************************************/
/***********  Func. Name: GPIO_voidSetPinOutputConfig                ********/
/***********  i/p arguments: Copy_u8PortId==> GPIOA, GPIOB, GPIOC    ********/
/***********  i/p arguments: Copy_u8PinId==> PIN0-->PIN15            ********/
/***********  i/p arguments: Copy_u8Type==> OUTPUT_PP, OUTPUT_OD     ********/
/*i/p arguments: Copy_u8Speed==> OUTPUT_LS, OUTPUT_MS, OUTPUT_HS, OUTPUT_VHS*/
/****************************return: Nothing*********************************/
/****************************************************************************/
void GPIO_voidSetPinOutputConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type, u8 Copy_u8Speed)
{
    /*i/p validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > 15))
    {

    }
    else
    {
        switch(Copy_u8PortId)
        {
            case GPIOA: switch(Copy_u8Type)
                        {
                            case OUTPUT_PP:     switch(Copy_u8Speed)
							{
								case OUTPUT_LS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Push Pull Type*/
												CLR_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select Low Speed = 8MHZ*/
												CLR_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								case OUTPUT_MS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Push Pull Type*/
												CLR_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select Mid Speed = 50MHZ*/
												SET_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								case OUTPUT_HS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Push Pull Type*/
												CLR_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select High Speed = 80MHZ*/
												CLR_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												SET_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								case OUTPUT_VHS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Push Pull Type*/
												CLR_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select Very high Speed = 180MHZ*/
												SET_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												SET_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								default:        break;
							}
                                                break;
                            case OUTPUT_OD:     switch(Copy_u8Speed)
							{
								case OUTPUT_LS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Open-Drain Type*/
												SET_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select Low Speed = 8MHZ*/
												CLR_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								case OUTPUT_MS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Open-Drain Type*/
												SET_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select Mid Speed = 50MHZ*/
												SET_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								case OUTPUT_HS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Open-Drain Type*/
												SET_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select High Speed = 80MHZ*/
												CLR_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												SET_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								case OUTPUT_VHS: /*Select O/P Mode*/
												SET_BIT(GPIOA_MODER,  Copy_u8PinId*2);
												CLR_BIT(GPIOA_MODER,  (((Copy_u8PinId*2)+1)));
												/*Select Open-Drain Type*/
												SET_BIT(GPIOA_OTYPER, Copy_u8PinId);
												/*Select Very High Speed = 180MHZ*/
												SET_BIT(GPIOA_OSPEEDR,  Copy_u8PinId*2);
												SET_BIT(GPIOA_OSPEEDR,  (((Copy_u8PinId*2)+1)));
												break;
								default:        break;
							}
							break;
		default:            break;
                        }
                        break;
            case GPIOB: switch(Copy_u8Type)
                        {
                            case OUTPUT_PP:     switch(Copy_u8Speed)
										{
											case OUTPUT_LS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Push Pull Type*/
															CLR_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select Low Speed = 8MHZ*/
															CLR_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											case OUTPUT_MS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Push Pull Type*/
															CLR_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select Mid Speed = 50MHZ*/
															SET_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											case OUTPUT_HS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Push Pull Type*/
															CLR_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select High Speed = 80MHZ*/
															CLR_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															SET_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											case OUTPUT_VHS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Push Pull Type*/
															CLR_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select Very high Speed = 180MHZ*/
															SET_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															SET_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											default:        break;
										}
										break;
					case OUTPUT_OD:     switch(Copy_u8Speed)
										{
											case OUTPUT_LS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Open-Drain Type*/
															SET_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select Low Speed = 8MHZ*/
															CLR_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											case OUTPUT_MS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Open-Drain Type*/
															SET_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select Mid Speed = 50MHZ*/
															SET_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											case OUTPUT_HS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Open-Drain Type*/
															SET_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select High Speed = 80MHZ*/
															CLR_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															SET_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											case OUTPUT_VHS: /*Select O/P Mode*/
															SET_BIT(GPIOB_MODER,  Copy_u8PinId*2);
															CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
															/*Select Open-Drain Type*/
															SET_BIT(GPIOB_OTYPER, Copy_u8PinId);
															/*Select Very High Speed = 180MHZ*/
															SET_BIT(GPIOB_OSPEEDR,  Copy_u8PinId*2);
															SET_BIT(GPIOB_OSPEEDR,  ((Copy_u8PinId*2)+1));
															break;
											default:        break;
										}
										break;
					default:            break;
                        }
                        break;
            case GPIOC: switch(Copy_u8Type)
                        {
                            case OUTPUT_PP:     switch(Copy_u8Speed)
                                                {
                                                    case OUTPUT_LS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Push Pull Type*/
                                                                    CLR_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select Low Speed = 8MHZ*/
                                                                    CLR_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    case OUTPUT_MS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Push Pull Type*/
                                                                    CLR_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select Mid Speed = 50MHZ*/
                                                                    SET_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    case OUTPUT_HS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Push Pull Type*/
                                                                    CLR_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select High Speed = 80MHZ*/
                                                                    CLR_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    SET_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    case OUTPUT_VHS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Push Pull Type*/
                                                                    CLR_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select Very high Speed = 180MHZ*/
                                                                    SET_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    SET_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    default:        break;
                                                }
                                                break;
                            case OUTPUT_OD:     switch(Copy_u8Speed)
                                                {
                                                    case OUTPUT_LS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Open-Drain Type*/
                                                                    SET_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select Low Speed = 8MHZ*/
                                                                    CLR_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    case OUTPUT_MS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Open-Drain Type*/
                                                                    SET_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select Mid Speed = 50MHZ*/
                                                                    SET_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    case OUTPUT_HS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Open-Drain Type*/
                                                                    SET_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select High Speed = 80MHZ*/
                                                                    CLR_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    SET_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    case OUTPUT_VHS: /*Select O/P Mode*/
                                                                    SET_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                                    /*Select Open-Drain Type*/
                                                                    SET_BIT(GPIOC_OTYPER, Copy_u8PinId);
                                                                    /*Select Very high Speed = 180MHZ*/
                                                                    SET_BIT(GPIOC_OSPEEDR,  Copy_u8PinId*2);
                                                                    SET_BIT(GPIOC_OSPEEDR,  ((Copy_u8PinId*2)+1));
                                                                    break;
                                                    default:        break;
                                                }
                                                break;
                            default:            break;
                        }
                        break;
            default:                            break;
        }
    }
}

/*****************************************************************************/
/***********  Func. Name: GPIO_voidSetPinOutputConfig                *********/
/***********  i/p arguments: Copy_u8PortId==> GPIOA, GPIOAB, GPIOC   *********/
/***********  i/p arguments: Copy_u8PinId==> PIN0-->PIN16            *********/
/***********  i/p arguments: Copy_u8Type==>INPUT_NOPUNOPD, INPUT_PU, INPUT_PD*/
/****************************return: Nothing**********************************/
/*****************************************************************************/
void GPIO_voidSetPinInputConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type)
{
    /*i/p validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > 15))
    {

    }
    else
    {
        switch(Copy_u8PortId)
        {
            case GPIOA: switch(Copy_u8Type)
                        {
                            case INPUT_NOPUNOPD:    /*Select i/p Mode*/
                                                    CLR_BIT(GPIOA_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOA_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select No Pull-Up No Pull-Down*/
                                                    CLR_BIT(GPIOA_PUPDR,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOA_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            case INPUT_PU:          /*Select i/p Mode*/
                                                    CLR_BIT(GPIOA_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOA_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select Pull-Up*/
                                                    SET_BIT(GPIOA_PUPDR,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOA_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            case INPUT_PD:          /*Select i/p Mode*/
                                                    CLR_BIT(GPIOA_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOA_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select Pull-Up*/
                                                    CLR_BIT(GPIOA_PUPDR,  Copy_u8PinId*2);
                                                    SET_BIT(GPIOA_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            default:            break;
                        }
                        break;
            case GPIOB: switch(Copy_u8Type)
                        {
                            case INPUT_NOPUNOPD:    /*Select i/p Mode*/
                                                    CLR_BIT(GPIOB_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select No Pull-Up No Pull-Down*/
                                                    CLR_BIT(GPIOB_PUPDR,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOB_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            case INPUT_PU:          /*Select i/p Mode*/
                                                    CLR_BIT(GPIOB_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select Pull-Up*/
                                                    SET_BIT(GPIOB_PUPDR,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOB_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            case INPUT_PD:          /*Select i/p Mode*/
                                                    CLR_BIT(GPIOB_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOB_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select Pull-Up*/
                                                    CLR_BIT(GPIOB_PUPDR,  Copy_u8PinId*2);
                                                    SET_BIT(GPIOB_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            default:            break;
                        }
                        break;
            case GPIOC: switch(Copy_u8Type)
                        {
                            case INPUT_NOPUNOPD:    /*Select i/p Mode*/
                                                    CLR_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select No Pull-Up No Pull-Down*/
                                                    CLR_BIT(GPIOC_PUPDR,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOC_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            case INPUT_PU:          /*Select i/p Mode*/
                                                    CLR_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select Pull-Up*/
                                                    SET_BIT(GPIOC_PUPDR,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOC_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            case INPUT_PD:          /*Select i/p Mode*/
                                                    CLR_BIT(GPIOC_MODER,  Copy_u8PinId*2);
                                                    CLR_BIT(GPIOC_MODER,  ((Copy_u8PinId*2)+1));
                                                    /*Select Pull-Up*/
                                                    CLR_BIT(GPIOC_PUPDR,  Copy_u8PinId*2);
                                                    SET_BIT(GPIOC_PUPDR,  ((Copy_u8PinId*2)+1));
                                                    break;
                            default:            break;
                        }
                        break;
            default:                            break;
        }
    }
}

/*Copy_u8PinValue: LOW, HIGH*/
void GPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
    /*i/p validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > 15))
    {

    }
    else
    {
        switch(Copy_u8PortId)
        {
            case GPIOA: switch(Copy_u8PinValue)
                        {
                            case LOW:   CLR_BIT(GPIOA_ODR,Copy_u8PinId);
                                        break;
                            case HIGH:  SET_BIT(GPIOA_ODR,Copy_u8PinId);
                                        break;
                        }
                        break;
            case GPIOB: switch(Copy_u8PinValue)
                        {
                            case LOW:   CLR_BIT(GPIOB_ODR,Copy_u8PinId);
                                        break;
                            case HIGH:  SET_BIT(GPIOB_ODR,Copy_u8PinId);
                                        break;
                        }
                        break;
            case GPIOC: switch(Copy_u8PinValue)
                        {
                            case LOW:   CLR_BIT(GPIOC_ODR,Copy_u8PinId);
                                        break;
                            case HIGH:  SET_BIT(GPIOC_ODR,Copy_u8PinId);
                                        break;
                        }
                        break;
            default:                            break;
        }
    }
}

/*Copy_u8Value: SET, RST*/
void GPIO_voidDirectSetResetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{
    /*i/p validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > 15))
    {

    }
    else
    {
        switch(Copy_u8PortId)
        {
            case GPIOA: switch(Copy_u8Value)
                        {
                            case SET:   GPIOA_BSRR = (1<<Copy_u8PinId);
                                        break;
                            case RST:   GPIOA_BSRR = (1<<(Copy_u8PinId+16));
                                        break;
                        }
                        break;
            case GPIOB: switch(Copy_u8Value)
                        {
                            case SET:   GPIOB_BSRR = (1<<Copy_u8PinId);
                                        break;
                            case RST:   GPIOB_BSRR = (1<<(Copy_u8PinId+16));
                                        break;
                        }
                        break;
            case GPIOC: switch(Copy_u8Value)
                        {
                            case SET:   GPIOC_BSRR = (1<<Copy_u8PinId);
                                        break;
                            case RST:   GPIOC_BSRR = (1<<(Copy_u8PinId+16));
                                        break;
                        }
                        break;
            default:                            break;
        }

    }
}

u8 GPIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 Local_u8PinValue = 0;
    /*i/p validation*/
    if((Copy_u8PortId > GPIOC) || (Copy_u8PinId > 15))
    {

    }
    else
    {
        switch(Copy_u8PortId)
        {
            case GPIOA: Local_u8PinValue = GET_BIT(GPIOA_IDR, Copy_u8PinId);
                        break;
            case GPIOB: Local_u8PinValue = GET_BIT(GPIOB_IDR, Copy_u8PinId);
                        break;
            case GPIOC: Local_u8PinValue = GET_BIT(GPIOC_IDR, Copy_u8PinId);
                        break;
            default:                            break;
        }
    }
    return Local_u8PinValue;
}
