/*
 * buttonState.c
 *
 *  Created on: Jun 5, 2024
 *      Author: jlue4
 */

#include "ledMode.h"

const int BLINK_INTERVAL = 200;
const int ROLL_INTERVAL = 100;

void handleTick_LedMode_Off(ledMode *self);
void handleTick_LedMode_On(ledMode *self);
void handleTick_LedMode_Blink(ledMode *self);
void handleTick_LedMode_Roll(ledMode *self);
void handleTick_LedMode_HalfRoll(ledMode *self);

void ledMode_Init(ledMode *self)
{
	self->state = LedMode_Off;
	self->ticks = 0;
	self->currentEnabledPin = LEDS_NONE;
	self->rollingUp = 1;
	self->halfRollState = 0;
	leds_OffAll();
	self->handleTickPointer = handleTick_LedMode_Off;
	self->onEntryPointer = NULL;
	self->onExitPointer = NULL;
}

void ledMode_Next(ledMode *self)
{
	self->state++;
	if (self->state > LedMode_HalfRoll)
	{
		self->state = LedMode_Off;
	}
	self->ticks = 0;

	if (self->onExitPointer)
	{
		self->onExitPointer(self);
	}

	switch (self->state)
	{
	case LedMode_Off:
		self->handleTickPointer = handleTick_LedMode_Off;
		leds_OffAll();
		break;
	case LedMode_On:
		self->handleTickPointer = handleTick_LedMode_On;
		leds_OnAll();
		break;
	case LedMode_Blink:
		self->handleTickPointer = handleTick_LedMode_Blink;
		leds_OffAll();
		break;
	case LedMode_Roll:
		self->handleTickPointer = handleTick_LedMode_Roll;
		self->currentEnabledPin = LEDS_NONE;
		leds_OffAll();
		break;
	case LedMode_HalfRoll:
		self->handleTickPointer = handleTick_LedMode_HalfRoll;
		self->currentEnabledPin = LEDS_NONE;
		self->halfRollState = 0;
		leds_OffAll();
		break;
	}

	if (self->onEntryPointer)
	{
		self->onEntryPointer(self);
	}
}

void ledMode_HandleTick(ledMode *self)
{
	self->ticks++;

	self->handleTickPointer(self);
}

void handleTick_LedMode_Off(ledMode *self)
{
	// nothing to do
}

void handleTick_LedMode_On(ledMode *self)
{
	// nothing to do
}

void handleTick_LedMode_Blink(ledMode *self)
{
	if (self->ticks > (BLINK_INTERVAL * 2))
	{
		leds_OnAll();
		self->ticks = 0;
	}
	else if (self->ticks > BLINK_INTERVAL)
	{
		leds_OffAll();
	}
}

void handleTick_LedMode_Roll(ledMode *self)
{
	if (self->ticks > ROLL_INTERVAL)
	{
		self->ticks = 0;

		if (self->rollingUp)
		{

			switch (self->currentEnabledPin)
			{
			case LEDS_NONE:
				self->currentEnabledPin = PA0_Pin;
				break;
			case PA0_Pin:
				self->currentEnabledPin = PA1_Pin;
				break;
			case PA1_Pin:
				self->currentEnabledPin = PA2_Pin;
				break;
			case PA2_Pin:
				self->currentEnabledPin = PA3_Pin;
				break;
			case PA3_Pin:
				self->currentEnabledPin = PA4_Pin;
				break;
			case PA4_Pin:
				self->currentEnabledPin = PA5_Pin;
				break;
			case PA5_Pin:
				self->currentEnabledPin = PA6_Pin;
				break;
			case PA6_Pin:
				self->currentEnabledPin = PA7_Pin;
				break;
			case PA7_Pin:
				self->currentEnabledPin = PA6_Pin;
				self->rollingUp = 0;
				break;
			}
		}
		else
		{

			switch (self->currentEnabledPin)
			{
			case LEDS_NONE:
				self->currentEnabledPin = PA0_Pin;
				break;
			case PA0_Pin:
				self->currentEnabledPin = PA1_Pin;
				self->rollingUp = 1;
				break;
			case PA1_Pin:
				self->currentEnabledPin = PA0_Pin;
				break;
			case PA2_Pin:
				self->currentEnabledPin = PA1_Pin;
				break;
			case PA3_Pin:
				self->currentEnabledPin = PA2_Pin;
				break;
			case PA4_Pin:
				self->currentEnabledPin = PA3_Pin;
				break;
			case PA5_Pin:
				self->currentEnabledPin = PA4_Pin;
				break;
			case PA6_Pin:
				self->currentEnabledPin = PA5_Pin;
				break;
			case PA7_Pin:
				self->currentEnabledPin = PA6_Pin;
				break;
			}
		}

		leds_SetPinExclusive(self->currentEnabledPin);
	}
}

void handleTick_LedMode_HalfRoll(ledMode *self)
{
	if (self->ticks > ROLL_INTERVAL)
	{
		self->ticks = 0;

		switch (self->halfRollState)
		{
		case 0:
			leds_SetPinExclusive(PA0_Pin | PA7_Pin);
			self->halfRollState = 1;
			break;
		case 1:
			leds_SetPinExclusive(PA1_Pin | PA6_Pin);
			self->halfRollState = 2;
			break;
		case 2:
			leds_SetPinExclusive(PA2_Pin | PA5_Pin);
			self->halfRollState = 3;
			break;
		case 3:
			leds_SetPinExclusive(PA3_Pin | PA4_Pin);
			self->halfRollState = 4;
			break;
		case 4:
			leds_SetPinExclusive(PA2_Pin | PA5_Pin);
			self->halfRollState = 5;
			break;
		case 5:
			leds_SetPinExclusive(PA1_Pin | PA6_Pin);
			self->halfRollState = 0;
			break;
		}
	}
}
