#pragma once
#include "Color.hpp"
#include <algorithm>


struct ColorRandomizer
{
  auto randomize()
  {
    current_ = smooth_to_next();
    smoothed_ += 1;

    if(smoothing_ == smoothed_)
    {
      auto constexpr n = sizeof(palette_) / sizeof(palette_[0]);
      state_ = (state_ + 3) % n;
      target_ = palette_[state_];
      smoothed_ = 0;
    }

    return current_;
  }

private:
  uint8_t smooth_to_next(uint8_t a, uint8_t b) const
  {
    auto const x = ( a * (smoothing_ - smoothed_) ) / smoothing_;
    auto const y = ( b * smoothed_ ) / smoothing_;
    auto const out = x + y;
    if(out < 0)
      return 0;
    if(out > 0xff)
      return 0xff;
    return static_cast<uint8_t>(out);
  }

  Color smooth_to_next() const
  {
    return Color{
      smooth_to_next(current_.r, target_.r),
      smooth_to_next(current_.g, target_.g),
      smooth_to_next(current_.b, target_.b),
    };
  }

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

  Color current_{palette_[0]};
  Color target_{palette_[1]};
  int16_t const smoothing_{3};
  int16_t smoothed_{0};
};
