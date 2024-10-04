/*
 * St7735Adapter.cpp
 *
 *  Created on: Oct 4, 2024
 *      Author: jb23
 */

#include "St7735Adapter.h"
#include "st7735.h"
#include "fonts.h"
#include "stdio.h"
#include <math.h>

namespace ST7735Adapter
{

St7735Adapter::St7735Adapter()
{
  // TODO Auto-generated constructor stub

}

St7735Adapter::~St7735Adapter()
{
  // TODO Auto-generated destructor stub
}

void St7735Adapter::init(uint8_t r, uint8_t g, uint8_t b)
{
  ST7735_Init();
  ST7735_FillScreen(ST7735_COLOR565(r, g, b));
}

void St7735Adapter::drawCoordSystem(bool bold)
{
  for (int y = 0; y < 128; y++)
  {
    ST7735_DrawPixel(128 / 2, y, ST7735_COLOR565(254, 254, 58));
    if (bold)
    {
      ST7735_DrawPixel(128 / 2 - 1, y, ST7735_COLOR565(254, 254, 58));
      ST7735_DrawPixel(128 / 2 + 1, y, ST7735_COLOR565(254, 254, 58));
    }
  }

  for (int x = 0; x < 128; x++)
  {
    ST7735_DrawPixel(x, 128 / 2, ST7735_COLOR565(254, 254, 58));
    if (bold)
    {
      ST7735_DrawPixel(x, 128 / 2 - 1, ST7735_COLOR565(254, 254, 58));
      ST7735_DrawPixel(x, 128 / 2 + 1, ST7735_COLOR565(254, 254, 58));
    }
  }
}

void St7735Adapter::drawSine(bool bold)
{
  //     0 .. 180
  // x   64 .. 128
  //->   (x-64)/64*180
  for (int x = 0; x < 128; x++)
  {
    double rad = (x - 64.0) / 64.0 * 180.0 * 3.1415927 / 180;
    double sinVal = sin(rad);
    ST7735_DrawPixel(x, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(254, 254, 58));
    if (bold)
    {
      ST7735_DrawPixel(x + 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(254, 254, 58));
      ST7735_DrawPixel(x - 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(254, 254, 58));
    }
  }
}

void St7735Adapter::drawCosine(bool bold)
{
  //     0 .. 180
  // x   64 .. 128
  //->   (x-64)/64*180
  for (int x = 0; x < 128; x++)
  {
    double rad = (x - 64.0) / 64.0 * 180.0 * 3.1415927 / 180;
    double sinVal = cos(rad);
    ST7735_DrawPixel(x, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(254, 254, 58));
    if (bold)
    {
      ST7735_DrawPixel(x + 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(254, 254, 58));
      ST7735_DrawPixel(x - 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(254, 254, 58));
    }
  }
}

void St7735Adapter::drawLine(Coordinate start, Coordinate end)
{
}

void St7735Adapter::drawCircle(Coordinate center, uint16_t radius)
{
}

} /* namespace ST7735Adapter */
