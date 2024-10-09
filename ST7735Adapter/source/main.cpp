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

//  screen.drawLine(
//  { 0, 0 },
//  { 120, 50 });

  screen.drawCircle(
  { 20, 20 }, 10);
  screen.drawCircle(
  { 100, 20 }, 10);
  screen.drawCircle(
  { 20, 100 }, 10);
  screen.drawCircle(
  { 100, 100 }, 10);

  uint32_t counter = 0;

  bool up = true;
  uint16_t yc = 10;

  while (1)
  {
    if (counter++ % 50 == 0)
    {
      HAL_GPIO_TogglePin(GPIOA, LD2_Pin);  // toggle LED
    }

    if (counter % 2 == 0)
    {
      screen.setDrawingColor(27, 30, 250);
      screen.drawCircle(
      { 70, up ? (yc - 1) : (yc + 1) }, 10);
      screen.setDrawingColor(0xFF, 0xFF, 0xFF);
      screen.drawCircle(
      { 70, yc }, 10);
      if (up)
      {
        yc++;
        if (yc >= 118)
        {
          yc--;
          up = false;
        }
      }
      else
      {
        yc--;
        if (yc <= 10)
        {
          yc++;
          up = true;
        }
      }
    }

    HAL_Delay(1);

  }
}
