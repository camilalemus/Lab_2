#include "ADC.h"

void ADC_init(uint8_t ADCSbit,uint8_t Channel, uint8_t Justified, uint8_t Vref){
    
    switch (ADCSbit){
        case 0:
            ADCON0bits.ADCS1 = 0; //ADC Convertion Clock Selected bits (Fosc/2)
            ADCON0bits.ADCS0 = 0;
            break;
        case 1:
            ADCON0bits.ADCS1 = 0; //ADC Convertion Clock Selected bits (Fosc/8)
            ADCON0bits.ADCS0 = 1;
            break;
        case 2:
            ADCON0bits.ADCS1 = 1; //ADC Convertion Clock Selected bits (Fosc/32)
            ADCON0bits.ADCS0 = 0;
            break;
        case 3:
            ADCON0bits.ADCS1 = 1; //ADC Convertion Clock Selected bits FRC
            ADCON0bits.ADCS0 = 1;
            break;
        default: 
            ADCON0bits.ADCS1 = 0; //ADC Convertion Clock Selected bits (Fosc/8)
            ADCON0bits.ADCS0 = 1; 
            break;
    }

    switch (Channel) {
        case 0:
            ADCON0bits.CHS = 0b0000; //Channel 0
            break;
        case 1:
            ADCON0bits.CHS = 0b0001; //Channel 1
            break;
        case 2:
            ADCON0bits.CHS = 0b0010; //Channel 2
            break;
        case 3:
            ADCON0bits.CHS = 0b0011; //Channel 3
            break;
        case 4:
            ADCON0bits.CHS = 0b0100; //Channel 4
            break;
        case 5:
            ADCON0bits.CHS = 0b0101; //Channel 5
            break;
        case 6:
            ADCON0bits.CHS = 0b0110; //Channel 6
            break;
        case 7:
            ADCON0bits.CHS = 0b0111; //Channel 7
            break;
        case 8:
            ADCON0bits.CHS = 0b1000; //Channel 8
            break;
        case 9:
            ADCON0bits.CHS = 0b1001; //Channel 9
            break;
        case 10:
            ADCON0bits.CHS = 0b1010; //Channel 10
            break;
        case 11:
            ADCON0bits.CHS = 0b1011; //Channel 11
            break;
        case 12:
            ADCON0bits.CHS = 0b1100; //Channel 12
            break;
        case 13:
            ADCON0bits.CHS = 0b1101; //Channel 13
            break;
        case 14:
            ADCON0bits.CHS = 0b1110; //CV REF
            break;
        case 15:
            ADCON0bits.CHS = 0b1111; //FIXED REF (0.6V fixed voltage reference)
            break;
        default:
            ADCON0bits.CHS = 0b0010; //Channel 2
            break;
    }
    
    switch (Justified){
        case 0:
            ADCON1bits.ADFM = 0; // (Left justified)
            break;
        case 1:
            ADCON1bits.ADFM = 1; // (Right justified)
            break;
        default:
            ADCON1bits.ADFM = 0; // (Left justified)
            break;
    }
    
    switch (Vref){
        case 1:
            ADCON1bits.VCFG1 = 0; //Voltage reference bit (VSS)
            ADCON1bits.VCFG0 = 0; //Voltage reference bit (VDD)
            break;
        case 2:
            ADCON1bits.VCFG1 = 0; //Voltage reference bit (VSS)
            ADCON1bits.VCFG0 = 1; //Vref+pin
            break;
        case 3:
            ADCON1bits.VCFG1 = 1; //Vref-pin
            ADCON1bits.VCFG0 = 0; //Voltage reference bit (VDD)
            break;
        case 4:
            ADCON1bits.VCFG1 = 1; //Vref-pin
            ADCON1bits.VCFG0 = 1; //Vref+pin
            break;
        default:
            ADCON1bits.VCFG1 = 0; //Voltage reference bit (VSS)
            ADCON1bits.VCFG0 = 0; //Voltage reference bit (VDD)
            break;
    }
    
    PIR1bits.ADIF = 0; //ADC interrupt flag cleared
    PIE1bits.ADIE = 1; //ADC interrupt enable ON
    ADCON0bits.ADON = 1; //ADC Enable bit
}
