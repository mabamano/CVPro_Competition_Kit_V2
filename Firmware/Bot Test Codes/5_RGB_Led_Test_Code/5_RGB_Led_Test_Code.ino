// This firmware was developed by the Development Team at Meritus AI, 2024.
#include <FastLED.h>

#define LED_PIN 15
#define NUM_LEDS 1

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  //delay(10);
}

void loop() {
  // Set the LED color to purple (150, 0, 150) for 1 second
  leds[0] = CRGB(150, 0, 150); // CRGB(R, G, B) Values
  FastLED.show();
  delay(1000);

  leds[0] = CRGB(0, 0, 0); // CRGB(R, G, B) Values
  FastLED.show();
  delay(1000);
}