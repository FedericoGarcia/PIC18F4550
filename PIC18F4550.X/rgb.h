#include <xc.h>

#ifndef RGB_H
#define	RGB_H

#define LED_RED     LATBbits.LB0
#define LED_GREEN   LATBbits.LB1
#define LED_BLUE    LATBbits.LB2

void rgbIni(void);
void rgbPwm(unsigned char r, unsigned char g, unsigned char b, unsigned char pwmCount);
void rgbDemo(void);

#endif