#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

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

#endif
