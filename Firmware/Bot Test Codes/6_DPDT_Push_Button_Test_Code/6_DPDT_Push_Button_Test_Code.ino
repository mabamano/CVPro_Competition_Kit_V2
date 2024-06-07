// This firmware was developed by Development Team, Meritus AI. 2024

#define BUTTON_PIN 34 // GIOP21 pin connected to button
 
void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);
}
 
void loop() {
  // read the state of the switch/button:
  int buttonState = digitalRead(BUTTON_PIN);
  // print out the button's state
  Serial.println(buttonState);
  //delay(10);
}