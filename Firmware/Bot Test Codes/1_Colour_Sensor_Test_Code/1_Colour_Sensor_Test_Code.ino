// This firmware was developed by the Development Team at Meritus AI, 2024.
#include <Wire.h>
#include <Adafruit_TCS34725.h>

///////////////////color sensor///////////////////

#define PCA9548A_ADDRESS 0x70  //mux address 0x70
#define TCS3414CS_ADDRESS 0x29 //ColorSensor address 0x29

// Initializing ColorSensor
Adafruit_TCS34725 tcs1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_4X); // Front Color Sensor
Adafruit_TCS34725 tcs2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_4X); // Back Color Sensor

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);       // Set ADC resolution to 12 bits (0-4095)
  analogSetAttenuation(ADC_0db);  // Set attenuation to 0dB (for full-scale voltage range)
}

// Assigning the channel for I2C Communication
void TCA9548A(uint8_t bus) {
  Wire.beginTransmission(PCA9548A_ADDRESS);
  Wire.write(1 << bus);
  Wire.endTransmission();
  // delay(100);
}



//ColorSensor Function
void front_colour_sensor() {
  TCA9548A(0);
  uint16_t r, g, b, c;
  tcs1.getRawData(&r, &g, &b, &c);
  uint16_t colorTemp1 = tcs1.calculateColorTemperature(r, g, b);
  Serial.println("CS-1 Color Temp: "+ String(colorTemp1));
  uint16_t lux = tcs1.calculateLux(r, g, b);
 // Serial.println("CS-1 : Red: "+ String(r)+", Green: "+String(g)+", Blue: "+String(b) +", Clear: "+String(c) +", Color Temp: "+ String(colorTemp1));
  //delay(100);
}

void back_colour_sensor() {

  TCA9548A(1);
  uint16_t r, g, b, c;
  tcs2.getRawData(&r, &g, &b, &c);
  uint16_t colorTemp2 = tcs2.calculateColorTemperature(r, g, b);
  Serial.println("CS-2 Color Temp: "+ String(colorTemp2));
  uint16_t lux = tcs2.calculateLux(r, g, b);
  //Serial.println("CS-2 : Red: "+ String(r)+", Green: "+String(g)+", Blue: "+String(b) +", Clear: "+String(c) +", Color Temp: "+ String(colorTemp2));

}

void loop() {
  front_colour_sensor();
  // back_colour_sensor();
}