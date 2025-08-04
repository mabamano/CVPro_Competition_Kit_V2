// Function List // #######################################################################################//
/*
1. get_PushButton_Value(); - Function used to get the push button state. Returns either 0 (not pressed) or 1 (pressed).
2. get_CS_Value(); - Function used to retrieve the value from the color sensor.
3. get_US_Value("FUS"); - Function used to get the value from an ultrasonic sensor. Replace "FUS" with any of the following to access the respective sensor: "FUS", "F1US", "F2US", "BUS", "RUS", or "LUS".
4. rgb_led(150, 0, 150); - Function used to light up the RGB LED by specifying red, green, and blue intensity values.
5. motor_forward(220); - Function used to move the DC motor in the forward direction. Speed can be set between 190 and 255.
6. motor_backward(220); - Function used to move the DC motor in the backward direction. Speed can be set between 190 and 255.
7. motor_stop(); - Function used to stop the DC motor.
8. set_servo_to(100); - Function used to set the angle of the servo motor. Standard angles: Center = 100, Left = 80, Right = 120.
*/
//########################################################################################################//
bool DPDT_STATE = 0; 


void loop() {

  DPDT_STATE = get_PushButton_Value();
  //Serial.println("DPDT Button State : "+String(DPDT_STATE));

  if(DPDT_STATE) 
  {  
    rgb_led(150, 0, 150);
    motor_forward(200);
  }
  else
  {
    rgb_led(0, 0, 0);
    motor_stop();
  }
 

}


