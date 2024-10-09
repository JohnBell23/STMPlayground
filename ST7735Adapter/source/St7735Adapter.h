/*
 * St7735Adapter.h
 *
 *  Created on: Oct 4, 2024
 *      Author: jlue4
 */

#include "stdint.h"

#pragma once

namespace ST7735Adapter
{

class St7735Adapter
{
protected:
  struct DrawingColor
  {
    uint8_t r;
    uint8_t g;
    uint8_t b;
  };
  DrawingColor m_drawingColor
  { 0xFF, 0xFF, 0xFF };
public:
  struct Coordinate
  {
    uint16_t x;
    uint16_t y;
  };

  const uint16_t MAX_EXCLUSIVE = 128;
  const uint16_t MIN_INCLUSIVE = 0;

public:
  St7735Adapter();
  virtual ~St7735Adapter();
  void init(uint8_t r, uint8_t g, uint8_t b);
  void setDrawingColor(uint8_t r, uint8_t g, uint8_t b);
  void drawCoordSystem(bool bold = true);
  void drawSine(bool bold = true);
  void drawCosine(bool bold = true);
  void drawLine(Coordinate start, Coordinate end);
  void drawCircle(Coordinate center, uint16_t radius, bool bold = true);
};

} /* namespace ST7735Adapter */

