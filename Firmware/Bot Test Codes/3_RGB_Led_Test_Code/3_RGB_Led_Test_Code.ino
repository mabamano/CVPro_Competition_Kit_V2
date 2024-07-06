#include <FastLED.h>

#define LED_PIN 15
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  delay(10);
}

void rgb_led(int r, int g, int b)
{
  leds[0] = CRGB(r, g, b);
  FastLED.show();
}

void loop() {
  // Set the LED color to purple (150, 0, 150) for 1 second
  rgb_led(150, 0, 150)
  delay(1000);

  rgb_led(0, 0, 0)
  delay(1000);
}