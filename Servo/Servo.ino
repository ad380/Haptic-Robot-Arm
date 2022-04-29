#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int runvalue = 0;

#define FORCE_SENSOR_PIN_1 A0 // the FSR and 10K pulldown are connected to A0
#define FORCE_SENSOR_PIN_2 A1 // the FSR and 10K pulldown are connected to A1

void setup() {
  Serial.begin(9600);
  
  myservo1.attach(8);  
  myservo2.attach(9);
  myservo3.attach(10);
  myservo4.attach(11);
  myservo5.attach(12);
  myservo6.attach(13);

  myservo1.write(80);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
  myservo5.write(80);
  myservo6.write(80);
}

void loop() {
  if(runvalue == 0){

    for (pos = 90; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

    for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    for (pos = 90; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo4.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    for (pos = 80; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo5.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    for (pos = 90; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo6.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

    delay(1000);

    for (pos = 80; pos <= 140; pos += 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    int analogReading1 = analogRead(FORCE_SENSOR_PIN_1);
    int analogReading2 = analogRead(FORCE_SENSOR_PIN_2);
    Serial.print("Force sensor readings = ");
    Serial.print(analogReading1); // print the raw analog reading
    Serial.print(", ");
    Serial.print(analogReading2); // print the raw analog reading
    Serial.println();
    
    delay(1000);

    /*
    for (pos = 180; pos >= 130; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    */
    
    for (pos = 120; pos >= 80; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo5.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    delay(1000);

    for (pos = 80; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo5.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

    for (pos = 140; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    delay (1000); 
    
    for (pos = 120; pos >= 80; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo5.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
    delay(1000);
    
    for (pos = 150; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo4.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo3.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }

    for (pos = 90; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 2 degree
      myservo2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    delay(2000);
    //runvalue = 1;
    
  }
  else{
    int analogReading1 = analogRead(FORCE_SENSOR_PIN_1);
    int analogReading2 = analogRead(FORCE_SENSOR_PIN_2);
    Serial.print("Force sensor readings = ");
    Serial.print(analogReading1); // print the raw analog reading
    Serial.print(", ");
    Serial.print(analogReading2); // print the raw analog reading
    Serial.println();
  }
  
}
