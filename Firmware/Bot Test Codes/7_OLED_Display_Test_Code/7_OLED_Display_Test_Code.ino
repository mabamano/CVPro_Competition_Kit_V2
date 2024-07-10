// Kindly Check whether the Library Files are installed in Library Manager.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.display();

}

void loop() {
      display.setTextSize(1);
      display.setTextColor(SSD1306_WHITE);
       //(x, y) (128, 64)

      display.setCursor(0, 1);
      display.println("Hello");

      display.setCursor(0, 16);
      display.println("1");

      display.setCursor(0, 35);
      display.println("2");

      display.setCursor(0, 55);
      display.println("3");

      display.display();
      delay(5);
      display.clearDisplay();

}
