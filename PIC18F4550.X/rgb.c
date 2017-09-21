#include "rgb.h"

void rgbIni(void){
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    TRISBbits.RB2 = 0;
}
/*
void rgbPwm(unsigned char r, unsigned char g, unsigned char b, unsigned char pwmCount){
    LED_RED = pwm(r, pwmCount);
    LED_GREEN = pwm(g, pwmCount);
    LED_BLUE = pwm(b, pwmCount);
}
*/
void rgbDemo(void){
    extern unsigned char rgb[];
    extern unsigned char statusRgbDemo;
    switch(statusRgbDemo){
		case 0:
			if(rgb[0] != 255){
				rgb[0]++;
			}else{
				statusRgbDemo = 1;
			}
			break;
		case 1:
			if(rgb[1] != 255){
				rgb[1]++;
			}else{
				statusRgbDemo = 2;
			}
			break;
		case 2:
			if(rgb[0] != 0){
				rgb[0]--;
			}else{
				statusRgbDemo = 3;
			}
			break;
		case 3:
			if(rgb[2] != 255){
				rgb[2]++;
			}else{
				statusRgbDemo = 4;
			}
			break;
		case 4:
			if(rgb[1] != 0){
				rgb[1]--;
			}else{
				statusRgbDemo = 5;
			}
			break;
		case 5:
			if(rgb[0] != 255){
				rgb[0]++;
			}else{
				statusRgbDemo = 6;
			}
			break;
		case 6:
			if(rgb[2] != 0){
				rgb[2]--;
			}else{
				statusRgbDemo = 7;
			}
			break;
		case 7:
			if(rgb[0] != 0){
				rgb[0]--;
			}else{
				statusRgbDemo = 8;
			}
			break;
		case 8:
			if(rgb[0] != 255 && rgb[1] != 255 && rgb[2] != 255){
				rgb[0]++;
				rgb[1]++;
				rgb[2]++;
			}else{
				statusRgbDemo = 9;
			}
			break;
		case 9:
			if(rgb[0] != 0 && rgb[1] != 0 && rgb[2] != 0){
				rgb[0]--;
				rgb[1]--;
				rgb[2]--;
			}else{
				statusRgbDemo = 10;
			}
			break;
		case 10:
			if(rgb[0] != 255 && rgb[1] != 255){
				rgb[0]++;
				rgb[1]++;
			}else{
				statusRgbDemo = 11;
			}
			break;
		case 11:
			if(rgb[0] != 0 && rgb[1] != 0){
				rgb[0]--;
				rgb[1]--;
			}else{
				statusRgbDemo = 12;
			}
			break;
		case 12:
			if(rgb[1] != 255 && rgb[2] != 255){
				rgb[1]++;
				rgb[2]++;
			}else{
				statusRgbDemo = 13;
			}
			break;
		case 13:
			if(rgb[1] != 0 && rgb[2] != 0){
				rgb[1]--;
				rgb[2]--;
			}else{
				statusRgbDemo = 14;
			}
			break;
		case 14:
			if(rgb[0] != 255 && rgb[2] != 255){
				rgb[0]++;
				rgb[2]++;
			}else{
				statusRgbDemo = 15;
			}
			break;
		case 15:
			if(rgb[0] != 0 && rgb[2] != 0){
				rgb[0]--;
				rgb[2]--;
			}else{
				statusRgbDemo = 16;
			}
			break;
		case 16:
			if(rgb[0] != 255){
				rgb[0]++;
			}else{
				statusRgbDemo = 17;
			}
			break;
		case 17:
			if(rgb[1] != 255 && rgb[2] != 255){
				rgb[0] = 255;
				rgb[1]++;
				rgb[2]++;
			}else{
				statusRgbDemo = 18;
			}
			break;
		case 18:
			if(rgb[0] != 0 && rgb[1] != 0 && rgb[2] != 0){
				rgb[0]--;
				rgb[1]--;
				rgb[2]--;
			}else{
				statusRgbDemo = 19;
			}
			break;
		case 19:
			if(rgb[0] != 255 && rgb[2] != 255){
				rgb[1] = 255;
				rgb[0]++;
				rgb[2]++;
			}else{
				statusRgbDemo = 20;
			}
			break;
		case 20:
			if(rgb[0] != 0 && rgb[1] != 0 && rgb[2] != 0){
				rgb[0]--;
				rgb[1]--;
				rgb[2]--;
			}else{
				statusRgbDemo = 21;
			}
			break;
		case 21:
			if(rgb[0] != 255 && rgb[1] != 255){
				rgb[2] = 255;
				rgb[0]++;
				rgb[1]++;
			}else{
				statusRgbDemo = 22;
			}
			break;
		case 22:
			if(rgb[0] != 0 && rgb[1] != 0 && rgb[2] != 0){
				rgb[0]--;
				rgb[1]--;
				rgb[2]--;
			}else{
				statusRgbDemo = 0;
			}
			break;
		default:
			rgb[0] = 0;
			rgb[1] = 0;
			rgb[2] = 0;
			statusRgbDemo = 0;
			break;
    }
}