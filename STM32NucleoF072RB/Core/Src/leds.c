#include "leds.h"

void leds_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(GPIOA, PA0_Pin|PA1_Pin|PA4_Pin|PA5_Pin
	                          |PA6_Pin|PA7_Pin|PA2_Pin|PA3_Pin, GPIO_PIN_RESET);

	  /*Configure GPIO pins : PA0_Pin PA1_Pin PA4_Pin PA5_Pin
	                           PA6_Pin PA7_Pin PA2_Pin PA3_Pin */
	  GPIO_InitStruct.Pin = PA0_Pin|PA1_Pin|PA4_Pin|PA5_Pin
	                          |PA6_Pin|PA7_Pin|PA2_Pin|PA3_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

void leds_OnAll(void){
	HAL_GPIO_WritePin(GPIOA, PA0_Pin|PA1_Pin|PA4_Pin|PA5_Pin
			                            |PA6_Pin|PA7_Pin|PA2_Pin|PA3_Pin, GPIO_PIN_SET);
}

void leds_OffAll(void){
	HAL_GPIO_WritePin(GPIOA, PA0_Pin|PA1_Pin|PA4_Pin|PA5_Pin
		                            |PA6_Pin|PA7_Pin|PA2_Pin|PA3_Pin, GPIO_PIN_RESET);
}

void leds_SetPinExclusive(int pinNumber){
	HAL_GPIO_WritePin(GPIOA, PA0_Pin|PA1_Pin|PA4_Pin|PA5_Pin
			                            |PA6_Pin|PA7_Pin|PA2_Pin|PA3_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(GPIOA, pinNumber, GPIO_PIN_SET);
}