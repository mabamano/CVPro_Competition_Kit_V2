// Function List // #######################################################################################//
/*
1. get_CS_Value(); - Use this to get Color Sensor Value.
2. get_US_Value("FUS"); - (FUS, F1US, F2US, BUS, RUS, LUS)
3. rgb_led(150, 0, 150); - (R, G, B)
4. motor_forward(220); Speed Limit - (190 - 255)
5. motor_backward(220); Speed Limit - (190 - 255)
6. motor_stop();
7. set_servo_to(100); Angle(Center - 100, Left - 80, Right - 120)
8. get_PushButton_Value(); Values(0 or 1)
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


