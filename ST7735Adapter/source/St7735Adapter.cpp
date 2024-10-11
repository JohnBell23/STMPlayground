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
    ST7735_DrawPixel(128 / 2, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    if (bold)
    {
      ST7735_DrawPixel(128 / 2 - 1, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
      ST7735_DrawPixel(128 / 2 + 1, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    }
  }

  for (int x = 0; x < 128; x++)
  {
    ST7735_DrawPixel(x, 128 / 2, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    if (bold)
    {
      ST7735_DrawPixel(x, 128 / 2 - 1, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
      ST7735_DrawPixel(x, 128 / 2 + 1, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
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
    ST7735_DrawPixel(x, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    if (bold)
    {
      ST7735_DrawPixel(x + 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
      ST7735_DrawPixel(x - 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
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
    ST7735_DrawPixel(x, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    if (bold)
    {
      ST7735_DrawPixel(x + 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
      ST7735_DrawPixel(x - 1, (int) (sinVal * -64.0 + 64), ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    }
  }
}

void St7735Adapter::drawLine(Coordinate start, Coordinate end)
{
  double x1 = start.x;
  double y1 = start.y;
  double x2 = end.x;
  double y2 = end.y;

  double a = (y2 - y1) / (x2 - x1);
  double b = y2 - a * x2;

  for (uint16_t xs = static_cast<uint16_t>(x1); xs <= static_cast<uint16_t>(x2);
      xs++)
  {
    uint16_t ys = static_cast<uint16_t>(a * xs + b);
    ST7735_DrawPixel(xs, ys, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
  }

}

void St7735Adapter::drawCircle(Coordinate center, uint16_t radius, bool bold)
{
  double x0 = center.x;
  double y0 = center.y;

  int numPoints = 40;

  for (int i = 0; i < numPoints; ++i)
  {
    double theta = 2.0 * M_PI * i / numPoints;

    double x = x0 + radius * cos(theta);
    double y = y0 + radius * sin(theta);

    ST7735_DrawPixel(x, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    if (bold)
    {
      ST7735_DrawPixel(x + 1, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
      ST7735_DrawPixel(x - 1, y, ST7735_COLOR565(m_drawingColor.r, m_drawingColor.g, m_drawingColor.b));
    }
  }
}

void St7735Adapter::setDrawingColor(uint8_t r, uint8_t g, uint8_t b)
{
  m_drawingColor.r = r;
  m_drawingColor.g = g;
  m_drawingColor.b = b;
}

void St7735Adapter::drawMatrix(Coordinate start, bool matrix[MATRIX_LENGTH][MATRIX_LENGTH], uint16_t blockSize)
{
  Coordinate topLeftCorner = start;

  for (int col = 0; col < MATRIX_LENGTH; col++)
  {
    for (int row = 0; row < MATRIX_LENGTH; row++)
    {
      if (matrix[col][row])
      {
        for (uint16_t line = 0; line < blockSize; line++)
        {
          Coordinate left
          { topLeftCorner.x, (uint16_t) (topLeftCorner.y + line) };
          Coordinate right
          { (uint16_t) (topLeftCorner.x + blockSize),
              (uint16_t) (topLeftCorner.y + line) };

          drawLine(left, right);
        }
      }

      topLeftCorner.x += blockSize;
    }
    topLeftCorner.x = start.x;
    topLeftCorner.y += blockSize;
  }
}

} /* namespace ST7735Adapter */
