#include <Wire.h>
#include <FastLED.h>
#include <NewPing.h>
#include <ESP32Servo.h>
#include <Adafruit_TCS34725.h>

// ### Declaration & Function ##################################################################################################
// ###  DPDT Push Button ###//
#define DPDT_Push_Button_Pin 34
// ### Color Sensor ###//
#define TCS3414CS_ADDRESS 0x29
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_2_4MS, TCS34725_GAIN_4X);
//### RGB Led ###//
#define LED_PIN 15
#define NUM_LEDS 1
CRGB leds[NUM_LEDS];
//### DC Motor ###//
const int motorPin1 = 32; 
const int motorPin2 = 33; 
const int chan1 = 2; 
const int chan2 = 3; 
const int nslp = 13; 
const int frequency = 5000;
//### Servo Motor ###//
#define SERVO_PIN 27 
Servo servo;
//### Ultrasonic Sensor ###//
#define FRONT_TRIGGER 12 
#define FRONT_ECHO  4  
#define FRONT1_TRIGGER 16
#define FRONT1_ECHO 14
#define FRONT2_TRIGGER 25 
#define FRONT2_ECHO  26  
#define BACK_TRIGGER 17
#define BACK_ECHO 19
#define LEFT_TRIGGER  2
#define LEFT_ECHO  23
#define RIGHT_TRIGGER 5
#define RIGHT_ECHO  18
#define MAX_DISTANCE 200 //(min, max) = (2, 400) Range
NewPing sonar1(FRONT_TRIGGER, FRONT_ECHO, MAX_DISTANCE); 
NewPing sonar5(FRONT1_TRIGGER, FRONT1_ECHO, MAX_DISTANCE); 
NewPing sonar6(FRONT2_TRIGGER, FRONT2_ECHO, MAX_DISTANCE); 
NewPing sonar2(BACK_TRIGGER, BACK_ECHO, MAX_DISTANCE); 
NewPing sonar3(LEFT_TRIGGER, LEFT_ECHO, MAX_DISTANCE);
NewPing sonar4(RIGHT_TRIGGER, RIGHT_ECHO, MAX_DISTANCE); 
//### Ultrasonic Sensor ###//
// ### Function ##################################################################################################
int get_CS_Value() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  uint16_t colorTemp = tcs.calculateColorTemperature(r, g, b);
  return colorTemp;
}

int get_US_Value(String sensorName)
{
  int fus = sonar1.ping_cm();
  int f1us = sonar5.ping_cm();
  int f2us = sonar6.ping_cm();
  int bus = sonar2.ping_cm(); 
  int lus = sonar3.ping_cm(); 
  int rus = sonar4.ping_cm(); 

  if (sensorName == "FUS")
    return fus;
  else if (sensorName == "F1US")
    return f1us;
  else if (sensorName == "F2US")
    return f2us;
  else if (sensorName == "BUS")
    return bus;
  else if (sensorName == "LUS")
    return lus;
  else if (sensorName == "RUS")
    return rus;
  else
    return -1; // default case for invalid input
}

void rgb_led(int r, int g, int b)
{
  leds[0] = CRGB(r, g, b);
  FastLED.show();
}

void motor_forward(int speed) // Speed Value (0 - 255)
{ 
  ledcWrite(chan1, speed);
  ledcWrite(chan2, 0);
}

void motor_backward(int speed) // Speed Value (0 - 255)
{ 
  ledcWrite(chan1, 0);
  ledcWrite(chan2, speed);
}

void motor_stop() {
  ledcWrite(chan1, 0);
  ledcWrite(chan2, 0);
}

void set_servo_to(int angle) {
  angle = constrain(angle, 75, 125); // Constrain the angle between 70 and 130 degrees
  servo.write(angle);               // Move the servo to the specified angle
}

int get_PushButton_Value()
{
  int pbval = digitalRead(DPDT_Push_Button_Pin);
  return pbval;
}

void CS_Setup() 
{
  analogReadResolution(12);    
  analogSetAttenuation(ADC_0db); 
}

void RGB_Led_Setup() 
{
  //######### RGB Led Setup ###########//
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
  FastLED.clear();
  FastLED.show();
  delay(10);
}

void DC_Motor_Setup() 
{
  //######### DC Motor Setup ###########//
  ledcSetup(chan1, frequency, 8);
  ledcSetup(chan2, frequency, 8);
  ledcAttachPin(motorPin1, 2);
  ledcAttachPin(motorPin2, 3);
  pinMode(nslp, OUTPUT);
  digitalWrite(nslp, HIGH);
}

void Servo_Motor_Setup() 
{
  servo.attach(SERVO_PIN, 500, 2400);
  //initial servo angle
  set_servo_to(100);
  delay(500);
}

void PB_Setup() {
  pinMode(DPDT_Push_Button_Pin, INPUT);
}

// ### Setup ##################################################################################################
void setup() 
{
  Serial.begin(115200);
  // Note : Do not shuffle this order
  PB_Setup();
  CS_Setup();
  RGB_Led_Setup();
  DC_Motor_Setup();
  Servo_Motor_Setup();
}