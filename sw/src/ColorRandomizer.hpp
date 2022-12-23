#pragma once
#include "Color.hpp"

struct ColorRandomizer
{
  auto randomize()
  {
    auto constexpr colors = sizeof(palette_) / sizeof(palette_[0]);
    state_ = (state_ + 3) % colors;
    return palette_[state_];
  }

private:
  Color const palette_[7] = {

    //{0xff, 0xfb, 0xf5},
    {0xff, 0xb7, 0x50},
    {0xb7, 0x5b, 0x01},

    //{0xf9, 0xce, 0x79},
    {0xf7, 0xb7, 0x54},
    {0xce, 0x73, 0x02},

    {0xff, 0xa9, 0x3c},
    {0xfd, 0xc4, 0x5f},
    {0xfd, 0xcc, 0x70}

  };

  uint32_t state_{0};

  Color current_{palette_[0]};
  Color target_{palette_[1]};
};
