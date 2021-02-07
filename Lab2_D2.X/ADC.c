#include "ADC.h"

void ADC_init(){
    
    PIR1bits.ADIF = 0; //ADC interrupt flag cleared
    PIE1bits.ADIE = 1; //ADC interrupt enable ON
    ADCON0bits.ADON = 1; //ADC Enable bit
    ADCON0bits.ADCS1 = 0; //ADC Convertion Clock Selected bits (Fosc/8)
    ADCON0bits.ADCS0 = 1;
    ADCON0bits.CHS = 0010; //Channel 2
    ADCON1bits.ADFM = 0; //A/D Conversion Result Select bit (Left justified)
    ADCON1bits.VCFG1 = 0; //Voltage reference bit (VSS)
    ADCON1bits.VCFG0 = 0; //Voltage reference bit (VDD)
    
}
