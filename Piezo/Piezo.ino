/*Piezo sensor with Arduino.
  Serial monitor readings.
  created by the SriTu Tech team.
  Read the code below and use it for any of your creation
*/
int pad1;
int pad2; 

void setup() {
  Serial.begin(9600);//enable serial monitor
}
void loop() {
  pad1 = analogRead(A1);//read analog value and put in to the variable
  pad2 = analogRead(A2);//read analog value and put in to the variable
  Serial.print("\nPad1: ");//print serial monitor
  Serial.print(pad1);//print serial monitor
  Serial.print("  Pad2: ");//print serial monitor
  Serial.print(pad2);//print serial monitor
}
