#include <MeetAndroid.h>
#include <Servo.h>
MeetAndroid meetAndroid;

float data[3] = {0};
int intdata[3] = {0};
int i = 1;
Servo myservo1; //lower servo
Servo myservo2; //upper servo
int pos1 = 0;
int pos2 = 0;

void setup() {
  // put your setup code here, to run once:
  // use the baud rate your bluetooth module is configured to 
  // not all baud rates are working well, i.e. ATMEGA168 works best with 57600
  Serial.begin(9600);
  
  // register callback functions, which will be called when an associated event occurs.
  // - the first parameter is the name of your function (see below)
  // - match the second parameter ('A', 'B', 'a', etc...) with the flag on your Android application
  //   small letters are custom events, capital letters inbuilt Amarino events
  meetAndroid.registerFunction(floatValues, 'A'); //orientation
  meetAndroid.registerFunction(intValue, 'B'); //Compass
  myservo1.attach(10); //Attach the servo to pin eleven
  myservo2.attach(11); //Attach the servo to pin eleven
}

void loop() {
  
  meetAndroid.receive(); // you need to keep this in your loop() to receive events
}

/*
 * Precision of float is currently 1/100th
 */
void floatValue(byte flag, byte numOfValues)
{
  float v = meetAndroid.getFloat();
  meetAndroid.send(v);
}

/**
 * Be careful about int values.
 * In Arduino int is a 16bit value!
 * In Android int is a 32bit value!
 *
 * If you expect to receive int values which are
 * not in this range (-32,768 to 32,767)
 * you should use meetAndroid.getLong()
 *
 */
void intValue(byte flag, byte numOfValues)
{
  int v = meetAndroid.getInt();
  meetAndroid.send(v);
  
    if (0<=data[1]<=359)   
  {
  
     pos1 = v/2;
     myservo1.write(pos1);
  }
  
}

/*
 * In this function we extract more than one value of an event
 * Use this technique when you know that more than one value is
 * attached to the event (basically an array of floats)
 */
void floatValues(byte flag, byte numOfValues)
{
  // create an array where all event values should be stored
  // the number of values attached to this event is given by
  // a parameter(numOfValues)
  float data[numOfValues];
  
  // call the library function to fill the array with values
  meetAndroid.getFloatValues(data);
  
  // access the values
  for (int i=0; i<numOfValues;i++)
  {
    meetAndroid.send(data[i]);
  }

  if (-180<=data[2]<=180)   
  {
     intdata[1] = int(data[1]); //Cast the X axis float value to int
     intdata[1] = intdata[1]+180;
     pos2 = intdata[1]/2;
     myservo2.write(pos2);
  }

//  if (-10<=data[3]<=10)   
//  {
//     
//     data[3] = data[3]+10;
//     pos2 = data[3]*9;
//     myservo2.write(pos2);
//  }
  
  
}
