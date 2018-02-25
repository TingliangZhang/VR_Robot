
// zoomkat 12-25-13 serial servo test
// type servo position 0 to 180 in serial monitor
// or for writeMicroseconds, use a value like 1500
// Send an a to attach servo or d to detach servo
// for IDE 1.0.5 and later
// Powering a servo from the arduino usually *DOES NOT WORK*.

#include <Servo.h> 
String readString; //String captured from serial port
Servo myservo;  // create servo object to control a servo 
int n; //value to write to servo

void setup() {
  Serial.begin(9600);
  myservo.writeMicroseconds(1500); //set initial servo position if desired
  myservo.attach(8, 500, 2500);  //the pin for the servo control, and range if desired
  Serial.println("servo all-in-one test code 12-25-13"); // so I can keep track of what is loaded
  Serial.println();
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured string 

      // attach or detach servo if desired
    if (readString == "d") { 
      while (digitalRead(7)) {} //delay loop until pin 7 is low
      myservo.detach(); //detach servo
      Serial.println("servo detached");
      goto bailout; //jump over writing to servo
    }
    if (readString == "a") {
      myservo.attach(7); //reattach servo to pin 7
      Serial.println("servo attached");
      goto bailout;
    }    

    n = readString.toInt();  //convert readString into a number

    // auto select appropriate value
    if(n >= 500)
    {
      Serial.print("writing Microseconds: ");
      Serial.println(n);
      myservo.writeMicroseconds(n);
    }
    else
    {   
      Serial.print("writing Angle: ");
      Serial.println(n);
      myservo.write(n); 
    }

bailout: //reenter code loop
    Serial.print("Last servo command position: ");    
    Serial.println(myservo.read());
    Serial.println();
    readString=""; //empty for next input
  }
}

