/*
 * main.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: jb23
 */

#include "main.h"
#include "St7735Adapter.h"

extern "C" void cpp_main();

void cpp_main(void)
{

  ST7735Adapter::St7735Adapter screen;
  screen.init(27, 30, 250);
  screen.setDrawingColor(0xFF, 0xFF, 0xFF);

//  screen.drawCoordSystem(true);
//  screen.drawSine(true);
//  screen.drawCosine(true);

  screen.drawLine(
  { 0, 0 },
  { 120, 50 });

  uint32_t counter = 0;
  while (1)
  {
    if (counter++ % 3 == 0)
    {
      HAL_GPIO_TogglePin(GPIOA, LD2_Pin);  // toggle LED
    }

    HAL_Delay(50);

  }
}
