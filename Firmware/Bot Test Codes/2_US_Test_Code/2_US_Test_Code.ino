// This firmware was developed by the Development Team at Meritus AI, 2024.

#include <NewPing.h>

#define FRONT_TRIGGER 12 
#define FRONT_ECHO  4  

#define BACK_TRIGGER 17
#define BACK_ECHO 19

#define LEFT_TRIGGER  2
#define LEFT_ECHO  23

#define RIGHT_TRIGGER 5
#define RIGHT_ECHO  18

#define MAX_DISTANCE 400

NewPing sonar1(FRONT_TRIGGER, FRONT_ECHO, MAX_DISTANCE); 
NewPing sonar2(BACK_TRIGGER, BACK_ECHO, MAX_DISTANCE); 
NewPing sonar3(LEFT_TRIGGER, LEFT_ECHO, MAX_DISTANCE);
NewPing sonar4(RIGHT_TRIGGER, RIGHT_ECHO, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200); 
}

void loop() {

  unsigned int frontSensorValue = sonar1.ping_cm(); 
  unsigned int backSensorValue = sonar2.ping_cm(); 
  unsigned int leftSensorValue = sonar3.ping_cm(); 
  unsigned int rightSensorValue = sonar4.ping_cm();

  String f_us = String(frontSensorValue);
  String b_us = String(backSensorValue);
  String l_us = String(leftSensorValue);
  String r_us = String(rightSensorValue);
  
  Serial.println("US - F : "+f_us+" | B : "+b_us+" | L : "+l_us+" | R : "+r_us);
  //delay(100);

}
