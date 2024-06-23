/*
 * buttonState.h
 *
 *  Created on: Jun 5, 2024
 *      Author: jlue4
 */

#ifndef INC_LEDMODE_H_
#define INC_LEDMODE_H_

#include "leds.h"

#define LEDS_NONE -1

typedef enum LedModeEnum
{
	LedMode_Off,
	LedMode_On,
	LedMode_Blink,
	LedMode_Roll,
	LedMode_HalfRoll
} LedModeEnum;

typedef struct ledModeType
{
	int currentEnabledPin;
	int ticks;
	LedModeEnum state;
	int rollingUp;
	int halfRollState;
	void (*handleTickPointer)(struct ledModeType *self);
	void (*onEntryPointer)(struct ledModeType *self);
	void (*onExitPointer)(struct ledModeType *self);
} ledMode;

void ledMode_Init(ledMode *self);

void ledMode_Next(ledMode *self);

void ledMode_HandleTick(ledMode *self);

#endif /* INC_LEDMODE_H_ */
