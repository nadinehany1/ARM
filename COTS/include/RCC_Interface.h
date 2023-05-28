/*File Gaurd*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Functions Prototypes*/
void RCC_voidInitSysClk(void);  //Select System Clk
/*AHB1, AHB2, APB1, APB2*/
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8PeripheralId);


#endif