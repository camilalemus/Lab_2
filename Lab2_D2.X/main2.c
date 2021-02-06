/*
 * File:   main2.c
 * Author: camila
 *
 * Created on January 31, 2021, 9:31 PM
 */

//******************************************************************************
//                          Configuration Bits
//******************************************************************************

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

//******************************************************************************
//                                  VARIABLES
//******************************************************************************

int DebounceCounter1 = 0;

//******************************************************************************
//                           INSTANCIAR FUNCIONES
//******************************************************************************
void setup(void);

//******************************************************************************
//                              CICLO PRINCIPAL
//******************************************************************************
void main(void) {
    setup ();
    return;
}

//******************************************************************************
//                                  SETUP
//******************************************************************************

void setup(void) {
    
    INTCONbits.GIE = 1;             //Set Global interrupts enable
    INTCONbits.TMR0IE = 1;          //Enable Timer0 Interrupts
    OPTION_REGbits.PSA = 0;         //Set Prescaler to Timer0
    OPTION_REGbits.T0CS = 0;        //Internal clock
    OPTION_REGbits.INTEDG = 0;      //Interrupt occurs on the falling edge

    OPTION_REGbits.PS0 = 1;         //Prescaler 1:32
    OPTION_REGbits.PS1 = 0;
    OPTION_REGbits.PS2 = 0;
    OPTION_REGbits.nRBPU = 0;       //Set PortB as pullups
    TMR0 = 0;                       //Set Timer0 start point
    TRISC = 0;                      //Set Port C and B are outputs
    TRISD = 0;
    PORTC = 0;                      // Turn off display and LEDs
    PORTD = 0;
    TRISBbits.TRISB1 = 1;           //Inputs B0 and B1 because of push buttons
    TRISBbits.TRISB0 = 1;
}

void __interrupt() isr(void) {
    if (INTCONbits.TMR0IF == 1) {  //When Timer 0 overflows
        if (PORTBbits.RB0 == 0) { //If the push button is pressed down, add to the Debounce Counter
            DebounceCounter1++;
        }
        else if (PORTBbits.RB1 == 0){
            DebounceCounter1--;
        }
        INTCONbits.TMR0IF = 0; //Turn off the interrupt flag
    }
}