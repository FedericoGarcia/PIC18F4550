#include "pwm.h"

unsigned char pwm(unsigned char pulseWidth, unsigned char pwmCount){
    if(pwmCount < pulseWidth){
        return 1;
    }else{
        return 0;
    }
}