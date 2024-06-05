/*
 * buttonState.h
 *
 *  Created on: Jun 5, 2024
 *      Author: jlue4
 */

#ifndef INC_BUTTONSTATE_H_
#define INC_BUTTONSTATE_H_

typedef enum ButtonStatus{
	ButtonStatus_Off,
	ButtonStatus_On,
	ButtonStatus_Blink,
	ButtonStatus_Roll,
	ButtonStatus_HalfRoll
} ButtonState;

void nextButtonState();


#endif /* INC_BUTTONSTATE_H_ */
