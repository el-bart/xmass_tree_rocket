#pragma once
#include "Color.hpp"
#include <algorithm>


struct ColorRandomizer
{
  auto randomize()
  {
    /*
    if(current_ == target_ || transition_ == 0)
    {
      auto constexpr colors = sizeof(palette_) / sizeof(palette_[0]);
      state_ = (state_ + 1) % colors;
      target_ = palette_[state_];
      transition_ = 3;
    }

    current_ = offset(current_, target_, transition_);
    transition_ -= 1;

    return current_;
    */

    auto constexpr colors = sizeof(palette_) / sizeof(palette_[0]);
    state_ = (state_ + 1) % colors;
    return palette_[state_];
  }

private:
  uint8_t offset_channel(int16_t const a, int16_t const b, int16_t const n)
  {
    auto const res = a + (b-a)/n;
    if(res <= 0)
      return 0;
    if(res >= 0xff)
      return 0xff;
    return res;
  }

  Color offset(Color const a, Color const b, uint8_t const n)
  {
    Color out{
      offset_channel(a.r, b.r, n),
      offset_channel(a.g, b.g, n),
      offset_channel(a.b, b.b, n),
    };
    return out;
  }

  Color const palette_[7] = {

    //{0xff, 0xfb, 0xf5},
    //{0xff, 0xb7, 0x50},
    {0xb7, 0x5b, 0x01},

    //{0xf9, 0xce, 0x79},
    //{0xf7, 0xb7, 0x54},
    {0xce, 0x73, 0x02},

    //{0xff, 0xa9, 0x3c},
    //{0xfd, 0xc4, 0x5f}
    //{0xfd, 0xcc, 0x70}

    {0xb6, 0x5a, 0x00},
    {0xc6, 0x69, 0x04},

    {0xce, 0x72, 0x08},
    {0xdc, 0x75, 0x08},
    {0xdb, 0x80, 0x0d}

  };

  uint16_t state_{0};

  Color current_{palette_[0]};
  Color target_{palette_[1]};
  uint8_t transition_{0};
};
