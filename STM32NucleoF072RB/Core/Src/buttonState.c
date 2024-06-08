/*
 * buttonState.c
 *
 *  Created on: Jun 5, 2024
 *      Author: jlue4
 */

#include "buttonState.h"


void buttonStateInit(buttonState* self){
	self->state=ButtonStatus_Off;
	self->ticks=0;
	ledsOffAll();
}

void buttonStateNext(buttonState* self){
	self->state++;
	if (self->state > ButtonStatus_HalfRoll){
		self->state = ButtonStatus_Off;
	}
	self->ticks=0;

	switch(self->state){
	case ButtonStatus_Off:
		ledsOffAll();
		break;
	case ButtonStatus_On:
		ledsOnAll();
		break;
	case ButtonStatus_Blink:
		ledsOffAll();
		break;
	case ButtonStatus_Roll:
		break;
	case ButtonStatus_HalfRoll:
		break;
	}
}

void buttonStateHandleTick(buttonState* self){
	self->ticks++;

	switch(self->state){
	case ButtonStatus_Off:
		break;
	case ButtonStatus_On:
		break;
	case ButtonStatus_Blink:
		if (self->ticks > 2000){
			ledsOnAll();
			self->ticks=0;
		}else if (self->ticks > 1000){
			ledsOffAll();
		}
		break;
	case ButtonStatus_Roll:
		break;
	case ButtonStatus_HalfRoll:
		break;
	}
}
