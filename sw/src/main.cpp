#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

auto const g_led_count = 4;
auto const g_led_pin = D7;

Adafruit_NeoPixel g_pixels{g_led_count, g_led_pin, NEO_GRB + NEO_KHZ800};  // TODO: | ??

struct Color
{
  uint8_t r{0};
  uint8_t g{0};
  uint8_t b{0};
};


auto randomize_color()
{
  Color c;
  // TODO: random fire stuff
  return c;
}


void update_leds()
{
  for(auto i=0; i<g_led_count; ++i)
  {
    auto const c = randomize_color();
    g_pixels.setPixelColor(i, c.r, c.g, c.b);
  }

  g_pixels.clear();
  g_pixels.show();
}


void setup()
{
  wdt_enable(WDTO_1S);
  g_pixels.begin();
  g_pixels.clear();
}


void loop()
{
  wdt_reset();
  update_leds();
  delay(10);  // [ms]
}
