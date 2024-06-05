/*
 * buttonState.c
 *
 *  Created on: Jun 5, 2024
 *      Author: jlue4
 */

#include "buttonState.h"

ButtonState MyButtonState=0;


void nextButtonState(){
	MyButtonState++;
	if (MyButtonState > ButtonStatus_HalfRoll){
		MyButtonState = ButtonStatus_Off;
	}
}
