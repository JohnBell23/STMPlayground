#ifndef INC_LEDS_H_
#define INC_LEDS_H_

#include "stm32f0xx_hal.h"

#define PA0_Pin GPIO_PIN_0
#define PA0_GPIO_Port GPIOA
#define PA1_Pin GPIO_PIN_1
#define PA1_GPIO_Port GPIOA
#define PA4_Pin GPIO_PIN_4
#define PA4_GPIO_Port GPIOA
#define PA5_Pin GPIO_PIN_5
#define PA5_GPIO_Port GPIOA
#define PA6_Pin GPIO_PIN_6
#define PA6_GPIO_Port GPIOA
#define PA7_Pin GPIO_PIN_7
#define PA7_GPIO_Port GPIOA
#define PA2_Pin GPIO_PIN_8
#define PA2_GPIO_Port GPIOA
#define PA3_Pin GPIO_PIN_9
#define PA3_GPIO_Port GPIOA

void leds_Init(void);

void leds_OnAll(void);
void leds_OffAll(void);
void leds_SetPinExclusive(int pinNumber);

#endif /* INC_LEDS_H_ */
