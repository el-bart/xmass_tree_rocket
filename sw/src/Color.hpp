#pragma once

struct Color
{
  uint8_t r{0};
  uint8_t g{0};
  uint8_t b{0};
};


inline auto operator==(Color const& lhs, Color const& rhs)
{
  return lhs.r == rhs.g && lhs.g == rhs.g && lhs.b == rhs.b;
}

inline auto operator!=(Color const& lhs, Color const& rhs)
{
  return not (lhs == rhs);
}
