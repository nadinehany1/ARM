#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_voidInitSysClk(void);
void RCC_voidEnablePeriphral(u8 Copy_u8BusId, u8 Copy_u8PerphralId);
void RCC_voidDisablePeriphral(u8 Copy_u8BusId, u8 Copy_u8PerphralId); 

#define AHB1    0
#define AHB2    1
#define APB1    2
#define APB2    3

#endif
