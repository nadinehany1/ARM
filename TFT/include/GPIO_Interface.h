
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_
/***********************************************************************/


void GPIO_voidSetPinMode(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u8Mode);
void GPIO_voidSetPinOutType(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Type);
void GPIO_voidSetPinOutSpeed(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Speed);
void GPIO_voidSetPinInpuType(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32InputType);
u32 GPIO_u32getPinValue(u32 Copy_u32PortID, u32 Copy_u32PinID);
void GPIO_voidSetPinValueNonAtumic(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Value);
void GPIO_voidSetPinValueAtomic(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Value);
void GPIO_voidSetPortSpeed(u32 Copy_u32PortID , u32 Copy_u32Speed );
void GPIO_voidSetPortMode(u32 Copy_u32PortID , u32 Copy_u32Mode );
void GPIO_voidSetPortType(u32 Copy_u32PortID , u32 Copy_u32Type );
void GPIO_u32SetPortValue(u32 Copy_u32PortID  , u32 Copy_u32Value );
void GPIO_u32SetPortValueManual(u32 Copy_u32PortID  , u32 Copy_u32Value );

#endif
