/* 
 * File:   ADC.h
 * Author: Camila Lemus
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef __ADC_H_
#define	__ADC_H_

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

//******************************************************************************
//This routine initializes PIC’s internal ADC module.
//First parameter: A/D Conversion Clock Select bits
//Second parameter: Channel
//Third parameter: Justistified
//Fourth parameter: Voltage Reference bit
//Look page 104 and 105 for more information.
//Read ADC.c comments
//******************************************************************************

void ADC_init(uint8_t ADCSbit,uint8_t Channel, uint8_t Justified, uint8_t Vref);


#endif	/* __ADC_H_ */

