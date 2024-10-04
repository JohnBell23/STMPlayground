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
public:
  struct Coordinate
  {
    uint16_t x;
    uint16_t y;
  };

public:
  St7735Adapter();
  virtual ~St7735Adapter();
  void init(uint8_t r, uint8_t g, uint8_t b);
  void drawCoordSystem(bool bold = true);
  void drawSine(bool bold = true);
  void drawCosine(bool bold = true);
  void drawLine(Coordinate start, Coordinate end);
  void drawCircle(Coordinate center, uint16_t radius);
};

} /* namespace ST7735Adapter */

