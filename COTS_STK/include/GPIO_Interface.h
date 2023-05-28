/*
 * GPIO_Interface.h
 *
 *  Created on: 12/5/2023
 *      Author: Nadine Hany
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*Macros as PortId options*/
#define GPIOA              0
#define GPIOB              1
#define GPIOC              2

/*Macros as PinId options*/
#define PIN0               0
#define PIN1               1
#define PIN2               2
#define PIN3               3
#define PIN4               4
#define PIN5               5
#define PIN6               6
#define PIN7               7
#define PIN8			   8
#define PIN9			   9
#define PIN10			  10
#define PIN11			  11
#define PIN12			  12
#define PIN13			  13
#define PIN14			  14
#define PIN15			  15
/* */

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
/*Funcions */
/*Functions Prototypes*/
/****************************************************************************/
/***********  Func. Name: GPIO_voidSetPinOutputConfig                ********/
/***********  i/p arguments: Copy_u8PortId==> GPIOA, GPIOB, GPIOC    ********/
/***********  i/p arguments: Copy_u8PinId==> PIN0-->PIN15            ********/
/***********  i/p arguments: Copy_u8Type==> OUTPUT_PP, OUTPUT_OD     ********/
/*i/p arguments: Copy_u8Speed==> OUTPUT_LS, OUTPUT_MS, OUTPUT_HS, OUTPUT_VHS*/
/****************************return: Nothing*********************************/
/****************************************************************************/
void GPIO_voidSetPinOutputConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type, u8 Copy_u8Speed);
/*****************************************************************************/
/***********  Func. Name: GPIO_voidSetPinOutputConfig                *********/
/***********  i/p arguments: Copy_u8PortId==> GPIOA, GPIOAB, GPIOC   *********/
/***********  i/p arguments: Copy_u8PinId==> PIN0-->PIN16            *********/
/***********  i/p arguments: Copy_u8Type==>INPUT_NOPUNOPD, INPUT_PU, INPUT_PD*/
/****************************return: Nothing**********************************/
/*****************************************************************************/
void GPIO_voidSetPinInputConfig(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Type);
/*Copy_u8PinValue: LOW, HIGH*/
void GPIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);
/*Copy_u8Value: SET, RST*/
void GPIO_voidDirectSetResetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);
u8 GPIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);
void GPIO_voidSetPortValue(u8 Copy_u8PortId, u32 Copy_u8PortValue);
u32 GPIO_voidGetPortValue(u8 Copy_u8PortId);



#endif /* GPIO_INTERFACE_H_ */
