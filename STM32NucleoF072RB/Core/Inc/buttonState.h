/*
 * buttonState.h
 *
 *  Created on: Jun 5, 2024
 *      Author: jlue4
 */

#ifndef INC_BUTTONSTATE_H_
#define INC_BUTTONSTATE_H_

#include "leds.h"

typedef enum ButtonStatusEnum{
	ButtonStatus_Off,
	ButtonStatus_On,
	ButtonStatus_Blink,
	ButtonStatus_Roll,
	ButtonStatus_HalfRoll
} ButtonStatusEnum;

typedef struct buttonState{
	int ticks;
	ButtonStatusEnum state;
} buttonState;

void buttonStateInit(buttonState* self);

void buttonStateNext(buttonState* self);

void buttonStateHandleTick(buttonState* self);


#endif /* INC_BUTTONSTATE_H_ */
