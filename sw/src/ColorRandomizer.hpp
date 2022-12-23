#pragma once
#include "Color.hpp"
#include <algorithm>


struct ColorRandomizer
{
  auto randomize()
  {
    auto constexpr n = sizeof(palette_) / sizeof(palette_[0]);
    state_ = (state_ + 1) % n;
    return palette_[state_];
  }

private:
  Color const palette_[7] = {
    {0xb7, 0x5b, 0x01},
    {0xce, 0x73, 0x02},
    {0xb6, 0x5a, 0x00},
    {0xc6, 0x69, 0x04},

    {0xce, 0x72, 0x08},
    {0xdc, 0x75, 0x08},
    {0xdb, 0x80, 0x0d}
  };

  uint16_t state_{0};
};
