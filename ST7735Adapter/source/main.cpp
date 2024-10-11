/*
 * main.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: jb23
 */

#include "main.h"
#include "St7735Adapter.h"

extern "C" void cpp_main();

# define t true
# define f false

void cpp_main(void)
{

  ST7735Adapter::St7735Adapter screen;
  screen.init(0xFF, 0xFF, 0xFF);
  screen.setDrawingColor(0x00, 0x00, 0x00);

//  screen.drawCoordSystem(true);
//  screen.drawSine(true);
//  screen.drawCosine(true);

//  screen.drawLine(
//  { 0, 0 },
//  { 120, 50 });

//  screen.drawCircle(
//  { 20, 20 }, 10);
//  screen.drawCircle(
//  { 100, 20 }, 10);
//  screen.drawCircle(
//  { 20, 100 }, 10);
//  screen.drawCircle(
//  { 100, 100 }, 10);

  bool matrix[MATRIX_LENGTH][MATRIX_LENGTH] =
  {
  { f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f }, // leer
  { f, t, t, t, t, t, t, t, f, t, t, t, f, t, f, f, t, t, f, t, f, f, f, t, t, t, t, t, t, t, f }, // 1
  { f, t, f, f, f, f, f, t, f, t, f, t, f, f, t, f, f, f, t, f, f, f, f, t, f, f, f, f, f, t, f }, // 2
  { f, t, f, t, t, t, f, t, f, t, f, t, f, t, t, f, f, t, f, f, f, f, f, t, f, t, t, t, f, t, f }, // 3
  { f, t, f, t, t, t, f, t, f, f, t, t, f, f, f, f, t, t, t, t, t, t, f, t, f, t, t, t, f, t, f }, // 4
  { f, t, f, t, t, t, f, t, f, f, f, t, t, f, t, f, f, t, t, t, t, t, f, t, f, t, t, t, f, t, f }, // 5
  { f, t, f, f, f, f, f, t, f, t, f, f, f, t, f, f, f, t, t, f, f, t, f, t, f, f, f, f, f, t, f }, // 6
  { f, t, t, t, t, t, t, t, f, t, f, t, f, t, f, t, f, t, f, t, f, t, f, t, t, t, t, t, t, t, f }, // 7
  { f, f, f, f, f, f, f, f, f, t, f, t, f, t, t, f, f, f, t, t, t, t, f, f, f, f, f, f, f, f, f }, // 8
  { f, f, f, t, t, t, f, t, f, t, t, t, t, t, f, t, f, f, f, f, f, f, t, t, t, f, f, t, t, t, f }, // 9
  { f, f, f, t, f, t, t, f, t, t, t, f, f, f, t, t, f, t, f, t, t, t, f, t, t, t, t, f, f, t, f }, // 10
  { f, t, t, t, f, t, f, t, f, f, f, t, t, f, t, t, t, f, f, f, f, t, t, t, f, t, t, f, f, f, f }, // 11
  { f, t, t, f, t, f, f, f, f, f, f, t, t, f, f, f, f, t, f, f, t, f, t, t, t, t, t, f, t, f, f }, // 12
  { f, f, f, f, f, t, f, t, t, t, f, f, t, t, f, f, f, t, f, f, f, t, t, f, t, f, t, t, t, t, f }, // 13
  { f, f, t, f, f, f, t, f, t, t, f, f, f, f, f, t, f, f, t, t, t, t, t, t, f, t, t, f, t, t, f }, // 14
  { f, f, t, f, t, t, t, t, f, t, f, f, t, f, t, f, t, f, t, t, f, t, f, f, t, f, f, f, f, f, f }, // 15
  { f, f, f, f, f, t, f, f, f, f, t, t, t, f, f, f, f, f, f, t, t, t, t, f, f, t, t, f, t, t, f }, // 16
  { f, f, t, t, f, t, f, t, f, t, t, f, t, f, f, f, f, t, f, t, f, f, t, f, t, f, t, t, f, t, f }, // 17
  { f, t, f, f, t, t, f, f, f, t, f, t, t, f, t, f, f, f, f, f, t, t, f, t, t, t, t, f, t, t, f }, // 18
  { f, t, f, t, t, f, f, t, f, t, t, f, t, t, f, f, f, f, f, f, f, f, f, t, t, t, t, f, f, f, f }, // 19
  { f, t, f, t, t, f, t, f, t, t, t, f, t, f, f, f, t, f, t, f, t, t, f, t, f, t, t, f, f, t, f }, // 20
  { f, t, f, t, t, f, t, t, t, f, t, f, f, t, f, f, f, f, t, f, t, t, t, t, t, t, f, t, f, f, f }, // 21
  { f, f, f, f, f, f, f, f, f, t, t, t, t, t, f, t, t, f, t, f, t, t, f, f, f, t, t, f, t, t, f }, // 22
  { f, t, t, t, t, t, t, t, f, f, f, t, f, t, f, t, f, t, f, f, t, t, f, t, f, t, f, f, f, f, f }, // 23
  { f, t, f, f, f, f, f, t, f, f, f, t, t, t, t, t, t, t, f, f, t, t, f, f, f, t, t, f, t, t, f }, // 24
  { f, t, f, t, t, t, f, t, f, t, t, f, f, f, t, f, t, f, t, t, f, t, t, t, t, t, t, t, f, t, f }, // 25
  { f, t, f, t, t, t, f, t, f, t, t, f, t, f, f, f, f, t, t, t, t, t, t, f, t, f, t, t, f, f, f }, // 26
  { f, t, f, t, t, t, f, t, f, t, t, f, t, t, t, t, t, t, f, f, t, t, t, t, t, t, t, f, t, f, f }, // 27
  { f, t, f, f, f, f, f, t, f, f, f, t, t, t, t, f, f, t, t, t, f, t, t, f, f, t, t, f, t, f, f }, // 28
  { f, t, t, t, t, t, t, t, f, f, t, f, f, t, t, t, t, t, f, t, f, f, f, f, f, t, f, t, f, f, f }, // 29
  { f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f } };

  screen.drawMatrix(
  { 0, 0 }, matrix, 4);

  uint32_t counter = 0;

  while (1)
  {
    if (counter++ % 3 == 0)
    {
      HAL_GPIO_TogglePin(GPIOA, LD2_Pin);  // toggle LED
    }

    HAL_Delay(100);

  }
}
