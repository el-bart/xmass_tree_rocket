#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "ColorRandomizer.hpp"

auto const g_led_count = 4;
auto const g_led_pin = D4;
auto const g_color_delay_ms = 29;

Adafruit_NeoPixel g_pixels{g_led_count, g_led_pin, NEO_GRB | NEO_KHZ800};
ColorRandomizer g_colRand;


void update_leds()
{
  g_pixels.clear();

  auto const c = g_colRand.randomize();
  for(auto i=0; i<g_led_count; ++i)
    g_pixels.setPixelColor(i, c.r, c.g, c.b);

  g_pixels.setBrightness(0xff);

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
  delay(g_color_delay_ms);
}
