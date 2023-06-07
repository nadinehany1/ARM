#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"

/***********************************************************************/
/*                           Lower Layer Interfaces                    */
/***********************************************************************/


/***********************************************************************/
/*                            own Header Files                         */
/***********************************************************************/

#include"GPIO_Interface.h"
#include"GPIO_Private.h"
#include"GPIO_Config.h"


void GPIO_voidSetPinMode(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Mode)
{
	switch(Copy_u32Mode)
	{
		case OUTPUT:
			switch(Copy_u32PortID)
			{
				case GPIOA: SET_BIT(GPIOA_MODER,(Copy_u32PinID*2));  //Copy_u32PinID*2->number of first bit
			                CLR_BIT(GPIOA_MODER,((Copy_u32PinID*2) +1));
			                break;
			    case GPIOB: SET_BIT(GPIOB_MODER,(Copy_u32PinID*2));
			                CLR_BIT(GPIOB_MODER,((Copy_u32PinID*2) +1));
			                break;
			    case GPIOC: SET_BIT(GPIOC_MODER,(Copy_u32PinID*2));
			                CLR_BIT(GPIOC_MODER,((Copy_u32PinID*2) +1));
			                 break;
			                 default:    break;
			}
		break;

		case INPUT:
			switch(Copy_u32PortID)
			{
				case GPIOA: CLR_BIT(GPIOA_MODER,(Copy_u32PinID*2));
						    CLR_BIT(GPIOA_MODER,((Copy_u32PinID*2) +1));
						    break;
				case GPIOB: CLR_BIT(GPIOB_MODER,(Copy_u32PinID*2));
						    CLR_BIT(GPIOB_MODER,((Copy_u32PinID*2) +1));
						    break;
				case GPIOC: CLR_BIT(GPIOC_MODER,(Copy_u32PinID*2));
						    CLR_BIT(GPIOC_MODER,((Copy_u32PinID*2) +1));
						    break;
			    default:    break;
			}
		break;
		case ALTERNATIVE:
			 switch(Copy_u32PortID)
			 {
			    case GPIOA: CLR_BIT(GPIOA_MODER,(Copy_u32PinID*2));
			      	  	  	SET_BIT(GPIOA_MODER,((Copy_u32PinID*2) +1));
			                break;
			    case GPIOB: CLR_BIT(GPIOB_MODER,(Copy_u32PinID*2));
			                SET_BIT(GPIOB_MODER,((Copy_u32PinID*2) +1));
			                break;
			    case GPIOC: CLR_BIT(GPIOC_MODER,(Copy_u32PinID*2));
			                SET_BIT(GPIOC_MODER,((Copy_u32PinID*2) +1));
			                break;
			    default:    break;
			  }
			                break;
		case ANALOG:
			 switch(Copy_u32PortID)
			 {
			 	 case GPIOA: SET_BIT(GPIOA_MODER,(Copy_u32PinID*2));
			                 SET_BIT(GPIOA_MODER,((Copy_u32PinID*2) +1));
			                 break;
			     case GPIOB: SET_BIT(GPIOB_MODER,(Copy_u32PinID*2));
			                 SET_BIT(GPIOB_MODER,((Copy_u32PinID*2) +1));
			                 break;
			     case GPIOC: SET_BIT(GPIOC_MODER,(Copy_u32PinID*2));
			                 SET_BIT(GPIOC_MODER,((Copy_u32PinID*2) +1));
			                 break;
			      default:    break;
			  }
			  break;
		default:        break;

	}
}
void GPIO_voidSetPinOutType(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Type)
{
	switch(Copy_u32Type)
	    {
	        case OUTPUT_PP:
	            switch(Copy_u32PortID)
	            {
	                case GPIOA:
	                	CLR_BIT(GPIOA_OTYPER,Copy_u32PinID);
	                    break;
	                case GPIOB:
	                	CLR_BIT(GPIOB_OTYPER,Copy_u32PinID);
	                    break;
	                case GPIOC:
	                	CLR_BIT(GPIOC_OTYPER,Copy_u32PinID);
	                    break;
	                default:
	                    break;
	             }
	        break;
	        case OUTPUT_OD:
	            switch(Copy_u32PortID)
	            {
	                case GPIOA:
	                	SET_BIT(GPIOA_OTYPER,Copy_u32PinID);
	                     break;
	                case GPIOB:
	                	SET_BIT(GPIOB_OTYPER,Copy_u32PinID);
	                    break;
	                case GPIOC:
	                	SET_BIT(GPIOC_OTYPER,Copy_u32PinID);
	                    break;
	                default:
	                break;
	            }
	        break;
	        default:
	                break;
	    }
}
void GPIO_voidSetPinOutSpeed(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Speed)
{
	switch(Copy_u32Speed)
    {
        case OUTPUT_LS:
            switch(Copy_u32PortID)
            {
                case GPIOA: CLR_BIT(GPIOA_OSPEEDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOA_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOB: CLR_BIT(GPIOB_OSPEEDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOB_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOC: CLR_BIT(GPIOC_OSPEEDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOC_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                default:    break;
            }
        break;
        case OUTPUT_MS:
            switch(Copy_u32PortID)
            {
                case GPIOA: SET_BIT(GPIOA_OSPEEDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOA_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOB: SET_BIT(GPIOB_OSPEEDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOB_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOC: SET_BIT(GPIOC_OSPEEDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOC_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                default:    break;
            }
        break;
        case OUTPUT_HS:
            switch(Copy_u32PortID)
            {
                case GPIOA: CLR_BIT(GPIOA_OSPEEDR,(Copy_u32PinID*2));
                            SET_BIT(GPIOA_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOB: CLR_BIT(GPIOB_OSPEEDR,(Copy_u32PinID*2));
                            SET_BIT(GPIOB_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOC: CLR_BIT(GPIOC_OSPEEDR,(Copy_u32PinID*2));
                            SET_BIT(GPIOC_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                default:    break;
            }
        break;
        case OUTPUT_VHS:
            switch(Copy_u32PortID)
            {
                case GPIOA: SET_BIT(GPIOA_OSPEEDR,(Copy_u32PinID*2));
                            SET_BIT(GPIOA_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOB: SET_BIT(GPIOB_OSPEEDR,(Copy_u32PinID*2));
                            SET_BIT(GPIOB_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOC: SET_BIT(GPIOC_OSPEEDR,(Copy_u32PinID*2));
                            SET_BIT(GPIOC_OSPEEDR,((Copy_u32PinID*2) +1));
                            break;
                default:    break;
            }
            break;
        default:       
			 break;
    }
}
void GPIO_voidSetPinInpuType(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32InputType)
{
	switch(Copy_u32InputType)
    {
        case INPUT_NOPUNOPD:
            switch(Copy_u32PortID)
            {
                case GPIOA: CLR_BIT(GPIOA_PUPDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOA_PUPDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOB: CLR_BIT(GPIOB_PUPDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOB_PUPDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOC: CLR_BIT(GPIOC_PUPDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOC_PUPDR,((Copy_u32PinID*2) +1));
                            break;
                default:    break;
            }
            break;
        case INPUT_PU:
            switch(Copy_u32PortID)
            {
                case GPIOA: SET_BIT(GPIOA_PUPDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOA_PUPDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOB: SET_BIT(GPIOB_PUPDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOB_PUPDR,((Copy_u32PinID*2) +1));
                            break;
                case GPIOC: SET_BIT(GPIOC_PUPDR,(Copy_u32PinID*2));
                            CLR_BIT(GPIOC_PUPDR,((Copy_u32PinID*2) +1));
                            break;
                default:    break;
            }
            break;
        case INPUT_PD:
                        switch(Copy_u32PortID)
                        {
                            case GPIOA: CLR_BIT(GPIOA_PUPDR,(Copy_u32PinID*2));
                                        SET_BIT(GPIOA_PUPDR,((Copy_u32PinID*2) +1));
                                        break;
                            case GPIOB: CLR_BIT(GPIOB_PUPDR,(Copy_u32PinID*2));
                                        SET_BIT(GPIOB_PUPDR,((Copy_u32PinID*2) +1));
                                        break;
                            case GPIOC: CLR_BIT(GPIOC_PUPDR,(Copy_u32PinID*2));
                                        SET_BIT(GPIOC_PUPDR,((Copy_u32PinID*2) +1));
                                        break;
                            default:    break;
                        }
                        break;
        default:        break;
    }
}
void GPIO_voidSetPinValueNonAtumic(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Value)
{
	switch(Copy_u32Value)
    {
        case HIGH:
            switch(Copy_u32PortID)
            {
                case GPIOA: 
                            SET_BIT(GPIOA_ODR,Copy_u32PinID);
                            break;
                case GPIOB: 
                            SET_BIT(GPIOB_ODR,Copy_u32PinID);
                            break;
                case GPIOC: 
                            SET_BIT(GPIOC_ODR,Copy_u32PinID);
                            break;
                default:
                        break;
            }
            break;
        case LOW:
            switch(Copy_u32PortID)
            {
                case GPIOA: 
                            CLR_BIT(GPIOA_ODR,Copy_u32PinID);
                            break;
                case GPIOB: 
                            CLR_BIT(GPIOB_ODR,Copy_u32PinID);
                            break;
                case GPIOC: 
                            CLR_BIT(GPIOC_ODR,Copy_u32PinID);
                            break;
                default:
                        break;
            }
            break;
        default:
            break;
    }
}
u32 GPIO_u32getPinValue(u32 Copy_u32PortID, u32 Copy_u32PinID)
{
	u32 local_u32PinValue;
    switch(Copy_u32PortID)
    {
        case GPIOA: local_u32PinValue = GET_BIT(GPIOA_IDR,Copy_u32PinID);     break;
        case GPIOB: local_u32PinValue = GET_BIT(GPIOB_IDR,Copy_u32PinID);     break;
        case GPIOC: local_u32PinValue = GET_BIT(GPIOC_IDR,Copy_u32PinID);     break;
        default:                                                            break;
    }
    return local_u32PinValue;
}

void GPIO_voidSetPinValueAtomic(u32 Copy_u32PortID, u32 Copy_u32PinID, u32 Copy_u32Value)
{
	switch(Copy_u32Value)
    {
        case HIGH:
            switch(Copy_u32PortID)
            {
                case GPIOA: GPIOA_BSRR = (1 << Copy_u32PinID);   break;
                case GPIOB: GPIOB_BSRR = (1 << Copy_u32PinID);   break;
                case GPIOC: GPIOC_BSRR = (1 << Copy_u32PinID);   break;
                            break;
                default:
                        break;
            }
            break;
        case LOW:
            switch(Copy_u32PortID)
            {
                case GPIOA: GPIOA_BSRR = (1 << (Copy_u32PinID + 16));   break;
                case GPIOB: GPIOB_BSRR = (1 << (Copy_u32PinID + 16));   break;
                case GPIOC: GPIOC_BSRR = (1 << (Copy_u32PinID + 16));   break;
                            break;
                default:
                        break;
            }
            break;
        default:
            break;
    }
}

void GPIO_voidSetPortSpeed(u32 Copy_u32PortID , u32 Copy_u32Speed )
{
    for ( u32 Copy_u32PinID = 0 ; Copy_u32PinID < 16 ; Copy_u32PinID++ )
    {
        GPIO_voidSetPinSpeed( Copy_u32PortID , Copy_u32PortID , Copy_u32Speed );
    }  
}

void GPIO_voidSetPortMode(u32 Copy_u32PortID , u32 Copy_u32Mode )
{
    for ( u32 Copy_u32PinID = 0 ; Copy_u32PinID < 16 ; Copy_u32PinID++ )
    {
        GPIO_voidSetPinMode( Copy_u32PortID , Copy_u32PortID, Copy_u32Mode );
    }  
}

void GPIO_voidSetPortType(u32 Copy_u32PortID , u32 Copy_u32Type )
{
    for ( u32 Copy_u32PinID = 0 ; Copy_u32PinID < 16 ; Copy_u32PinID++ )
    {
        GPIO_voidSetPinType( Copy_u32PortID , Copy_u32PortID , Copy_u32Type );
    }  
}

void GPIO_u32SetPortValue(u32 Copy_u32PortID  , u32 Copy_u32Value )
{
	switch(Copy_u32Value)
    {
        case HIGH:
            switch(Copy_u32PortID)
            {
                case GPIOA: GPIOA_BSRR = 0xFFFFFFFF;  break;
                case GPIOB: GPIOB_BSRR = 0xFFFFFFFF;   break;
                case GPIOC: GPIOC_BSRR = 0xFFFFFFFF;   break;
                     break;
                default:
                    break;
            }
            break;
        case LOW:
            switch(Copy_u32PortID)
            {
                case GPIOA: GPIOA_BSRR = 0x00000000;   break;
                case GPIOB: GPIOB_BSRR = 0x00000000;   break;
                case GPIOC: GPIOC_BSRR = 0x00000000;   break;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void GPIO_u32SetPortValueManual(u32 Copy_u32PortID  , u32 Copy_u32Value )
{
	switch( Copy_u32PortID)
    {

                case GPIOA: GPIOA_BSRR = Copy_u32Value;  break;
                case GPIOB: GPIOB_BSRR = Copy_u32Value;   break;
                case GPIOC: GPIOC_BSRR = Copy_u32Value;   break;
                default:
                    break;

    }
}

