#include <MeetAndroid.h>

MeetAndroid meetAndroid;

void setup() {
  // put your setup code here, to run once:
  // use the baud rate your bluetooth module is configured to 
  // not all baud rates are working well, i.e. ATMEGA168 works best with 57600
  Serial.begin(9600);
  
  // register callback functions, which will be called when an associated event occurs.
  // - the first parameter is the name of your function (see below)
  // - match the second parameter ('A', 'B', 'a', etc...) with the flag on your Android application
  //   small letters are custom events, capital letters inbuilt Amarino events
  meetAndroid.registerFunction(floatValues, 'A');
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
}
