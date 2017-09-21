#include <xc.h>
#include <stdio.h>
#include <pic18f4550.h>
#include "confbits.h"
#include "Tecnica1.h"
#include "pwm.h"
#include "rgb.h"

unsigned char rgb[] = {0, 0, 0};
unsigned char statusRgbDemo = 0;
unsigned char pwmCount = 0;
unsigned int adcValue = 0;
unsigned int flag1 = 0;

unsigned int GetADC10(void){
    unsigned char GuardoPorta, GuardoTrisa;
    GuardoPorta = PORTA;
    GuardoTrisa = TRISA;
    TRISAbits.RA0 = 1;
    ADCON1 = 0x0E;
    ADCON2 = 0x2E;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    ADCON0bits.ADON = 0;
    ADCON1 = 0x0F;
    LATA = GuardoPorta;
    TRISA = GuardoTrisa;
    return (ADRESH << 8) + ADRESL;
}

unsigned char GetADC8(void){
    unsigned char GuardoPorta, GuardoTrisa;
    GuardoPorta = PORTA;
    GuardoTrisa = TRISA;
    TRISAbits.RA0 = 1;
    ADCON1 = 0x0E;
    ADCON2 = 0x2E;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    ADCON0bits.ADON = 0;
    ADCON1 = 0x0F;
    LATA = GuardoPorta;
    TRISA = GuardoTrisa;
    return ADRESH;
}

void main(void){
    TIMER0_INI();
    TMR0ON = 1;
    INTCONbits.GIE = 1;
    rgbIni();
    while(1){
        if(adcValue < 512){
            LED_RED = pwm(0, pwmCount);
            LED_GREEN = pwm(adcValue/2, pwmCount);
            LED_BLUE = pwm(255-(adcValue/2), pwmCount);
        }else{
            LED_RED = pwm((adcValue/2)-255, pwmCount);
            LED_GREEN = pwm(255-(adcValue/2), pwmCount);
            LED_BLUE = pwm(0, pwmCount);
        }
        pwmCount++;
    }
}

void __interrupt myISR(void){
    if(TMR0IF){
        TMR0IF = 0;
        TMR0 = 0xFFD1;
        if(flag1 > 10){
            if(adcValue > 1023){
                adcValue = 0;
            }else{
                adcValue++;
            }
            flag1 = 0;
        }else{
            flag1++;
        }
    }
}