#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

auto const g_led_count = 4;
auto const g_led_pin = D4;

Adafruit_NeoPixel g_pixels{g_led_count, g_led_pin, NEO_GRB | NEO_KHZ800};

struct Color
{
  uint8_t r{0};
  uint8_t g{0};
  uint8_t b{0};
};


auto randomize_color()
{
  Color c;
  c = Color{255, 0, 255};
  // TODO: random fire stuff
  return c;
}


auto randomize_brightness()
{
  uint8_t b{10};
  return b;
}


void update_leds()
{
  g_pixels.clear();

  auto const c = randomize_color();
  for(auto i=0; i<g_led_count; ++i)
    g_pixels.setPixelColor(i, c.r, c.g, c.b);

  auto const b = randomize_brightness();
  g_pixels.setBrightness(b);

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
