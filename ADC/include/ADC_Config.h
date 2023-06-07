/*
 * ADC_Config.h
 *
 *  Created on: ???/???/????
 *      Author: lenovo
 */

#ifndef HEADER_ADC_CONFIG_H_
#define HEADER_ADC_CONFIG_H_

/* Options:
			ADC_AREF
			ADC_AVCC
			ADC_INTERNAL
*/
#define	ADC_REFVOLT		ADC_AVCC

/* Options:
			ENABLE
            DISABLE
*/
#define	ADC_ADJUST_CTRL		 RIGHT

#define ADC_Time_Out    50000

#define ADC_PRESCALAR_VAL    ADC_PRESCALAR_BY_128

#endif /* HEADER_ADC_CONFIG_H_ */
