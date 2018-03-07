#include <TimerOne.h>
#include <TimerThree.h>
#include <Wire.h>
// #include<PixyI2C.h>
#include <stdio.h>

#define front 2
#define right 1
#define back 4
#define left 3

#define CW 1  //clockwise
#define CCW 0 //counterclockwise

//                        90deg Y_axis
//                        front
//                          |
//                          2
//                         ---
//      180deg left-- 3 |   +   | 1 -- right 0deg X_axis
//                         ---
//                          4
//                          |
//                         back
//                         270deg
#define VoltmeterPin A7
#define LedPin  13
#define PulsePin1  31
#define PulsePin2  33
#define PulsePin3  35
#define PulsePin4  37
#define DirectionPin1  22
#define DirectionPin2  24
#define DirectionPin3  26
#define DirectionPin4  28
#define EnablePin1  23
#define EnablePin2  25
#define EnablePin3  27
#define EnablePin4  29

#define MaxPulseFreq  3000 //unit: Hz
#define MaxAcc  400


#define MaxSp 200 //unit: cm/sec
#define MaxRotSp 360 //unit: deg/sec

#define Fine 24 //细分
#define WheelDiameter 127 //unit:mm

int ledState = LOW;

int runMode = 0; //0=remote control mode, 1=auto-chasing mode
int degree = 0;
int sp = 0;
int rotsp = 0;
int clockwise = 0;

int freq1 = 0;
int freq2 = 0;
int freq3 = 0;
int freq4 = 0;

int period[4] = {0, 0, 0, 0};  //unit: us
int steppercounter[4] = {0, 0, 0, 0};

String inputString = "";         // a string to hold incoming data
volatile boolean stringComplete = false;  // whether the string is complete
volatile boolean commandExecuted = true; //whether the command from computer is executed
volatile boolean translationExecuted =  true;
volatile boolean rotationExecuted = true;

int sig_exist[4][4] = {0, 0, 0, 0, 0, 0, 0, 0}; //signature existence in all camera, sig_exist[camera number][signature], camera_number:0 right,1 front,2 left,3 back, signature:0 yellow,1 red,2 green,3 blue
int px[4][4] = {0, 0, 0, 0, 0, 0, 0, 0}; //position X of a signature in all camera
int py[4][4] = {0, 0, 0, 0, 0, 0, 0, 0}; //position Y of a signature in all camera
int wdt[4][4] = {0, 0, 0, 0, 0, 0, 0, 0}; //width of a signature in all camera
int hgt[4][4] = {0, 0, 0, 0, 0, 0, 0, 0}; //height of a signature in all camera

//The final detected targets' info
int signature[4][6];//data order:{yellow ball, red shirt, green shirt, blue shirt}{existence,camera number, X,Y,width,height};
int chase_target = 0; //0=yellow,1=red,2=green,3=blue
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);

  // reserve 100 bytes for the inputString:
  inputString.reserve(100);
  pinMode(LedPin, OUTPUT);
  pinMode(PulsePin1, OUTPUT);
  pinMode(PulsePin2, OUTPUT);
  pinMode(PulsePin3, OUTPUT);
  pinMode(PulsePin4, OUTPUT);
  pinMode(DirectionPin1, OUTPUT);
  pinMode(DirectionPin2, OUTPUT);
  pinMode(DirectionPin3, OUTPUT);
  pinMode(DirectionPin4, OUTPUT);
  pinMode(EnablePin1, OUTPUT);
  pinMode(EnablePin2, OUTPUT);
  pinMode(EnablePin3, OUTPUT);
  pinMode(EnablePin4, OUTPUT);

  digitalWrite(EnablePin1, LOW);
  digitalWrite(EnablePin2, LOW);
  digitalWrite(EnablePin3, LOW);
  digitalWrite(EnablePin4, LOW);

  digitalWrite(DirectionPin1, LOW);
  digitalWrite(DirectionPin2, LOW);
  digitalWrite(DirectionPin3, LOW);
  digitalWrite(DirectionPin4, LOW);

  Timer1.initialize(10000);//10ms , unit:us
  Timer1.attachInterrupt(PulsePinControl, 100); // PulsePinControl to run every 100 us unit;us
  // Timer1.attachInterrupt(testMotion, 1000000); //carMotion to run every 100 ms, unit us

  Timer3.initialize(1000000);//1sec , unit:us
  //Timer3.attachInterrupt(blinkLED); // blinkLED to run every 1 second
  Timer3.attachInterrupt(carMotion, 120000); //120ms


  // Timer1.attachInterrupt(readPixy, 1000000);
  //Serial.print("Setup Done\n");
}

void loop() {
  // put your main code here, to run repeatedly:

  // to read a variable which the interrupt code writes, we
  // must temporarily disable interrupts, to be sure it will
  // not change while we are reading.  To minimize the time
  // with interrupts off, just quickly make a copy, and then
  // use the copy while allowing the interrupt to keep working.
  //  noInterrupts();
  //  blinkCopy = blinkCount;
  //  interrupts();

  //received a new command from computer
  if (stringComplete) {
    // Serial.println("input:" + inputString);
    int len1 = inputString.length();
    char input[len1];
    inputString.toCharArray(input, len1);
    if (input[0] == 'M')
    {
      if (input[1] == '1')
      {
        runMode = 1;
      }
      else if (input[1] == '0')
      {
        runMode = 0;
      }
    }
    else if (input[0] == 'R')
    {
      sscanf(input, "R%dS%d", &clockwise, &rotsp);
      rotationExecuted = false;
    }
    else if (input[0] == 'T')
    {
      sscanf(input, "T%dS%d", &degree, &sp);
      translationExecuted = false;
    }

    //    if(inputString[0]=='T')
    //    {
    //    }
    // clear the string:
    // Serial.println("new command");
    inputString = "";
    stringComplete = false;
    commandExecuted = false;
  }

  //readPixy();

  //carMotion();
  //testMotion();

  static unsigned long last = 0;
  if(millis() - last > 1000){
//    translation(0, 0);
//    Serial.println("F1: " + (String)freq1 + "F2: " + (String)freq2 + "F3: " + (String)freq3 + "F4: " + (String)freq4);
//    getPeriod();
      int sensorValue = analogRead(VoltmeterPin);
      Serial1.print(sensorValue);
      // Serial1.print(' ');
      last = millis();
  }

  

}

void blinkLED(void)
{
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(LedPin, ledState);
}



void carMotion(void)  //decide every motor's pulse period depend on the car's motion
{
  static long last_run = 0;
  if (commandExecuted == false) //under remote mode, a new command has come
  {
    digitalWrite(EnablePin1, LOW);
    digitalWrite(EnablePin2, LOW);
    digitalWrite(EnablePin3, LOW);
    digitalWrite(EnablePin4, LOW);
    if (translationExecuted == false)
    {
      translation(degree, sp);
      translationExecuted = true;
    }
    else if (rotationExecuted == false)
    {
      rotation(clockwise, rotsp);
      rotationExecuted = true;
    }

    // Serial.print(sp);
    // Serial.print(" S\r\n");
    // Serial.print(degree);
    // Serial.print(" T\r\n");
    last_run = millis();
    commandExecuted = true;
  }
  else  //under remote mode, but no new command
  {
    if(millis()-last_run > 200){
      //stop the car, to avoid keep running when there are no command
      //      digitalWrite(EnablePin1, HIGH);
      //      digitalWrite(EnablePin2, HIGH);
      //      digitalWrite(EnablePin3, HIGH);
      //      digitalWrite(EnablePin4, HIGH);
      //      freq1 = 0;
      //      freq2 = 0;
      //      freq3 = 0;
      //      freq4 = 0;
      sp = 0;
      rotsp = 0;
      freqAim(1, 0);
      freqAim(2, 0);
      freqAim(3, 0);
      freqAim(4, 0);
      if (freq1 == 0 && freq2 == 0 && freq3 == 0 && freq4 == 0)
      {
        digitalWrite(EnablePin1, HIGH);
        digitalWrite(EnablePin2, HIGH);
        digitalWrite(EnablePin3, HIGH);
        digitalWrite(EnablePin4, HIGH);
      }
    }
  }

  // Serial.println("F1: " + (String)freq1 + "F2: " + (String)freq2 + "F3: " + (String)freq3 + "F4: " + (String)freq4);
  getPeriod();
}

void testMotion(void)
{
  translation(90, 0);
  //Serial.println("F1: " + (String)freq1 + "F2: " + (String)freq2 + "F3: " + (String)freq3 + "F4: " + (String)freq4);
  getPeriod();
}

void PulsePinControl(void)
{
  int c = 0;
  setDirection();
  for (c = 0; c < 4; c++)
  {
    steppercounter[c]++;
    int realtime = steppercounter[c] * 100; //unit:us
    int halfperiod = period[c] / 2; //unit: us
    if (period[c] != 0)
    {
      if (realtime <= halfperiod)
      {
        switch (c) {
          case 0:
            digitalWrite(PulsePin1, HIGH);
            break;
          case 1:
            digitalWrite(PulsePin2, HIGH);
            break;
          case 2:
            digitalWrite(PulsePin3, HIGH);
            break;
          case 3:
            digitalWrite(PulsePin4, HIGH);
            break;
          default:
            break;
        }
      }
      else if ((realtime > halfperiod) && (realtime < period[c]))
      {
        switch (c) {
          case 0:
            digitalWrite(PulsePin1, LOW);
            break;
          case 1:
            digitalWrite(PulsePin2, LOW);
            break;
          case 2:
            digitalWrite(PulsePin3, LOW);
            break;
          case 3:
            digitalWrite(PulsePin4, LOW);
            break;
          default:
            break;
        }
      }
      else
      {
        steppercounter[c] = 0;
      }
    }
    else  //period[c]==0;
    {
      switch (c) {
        case 0:
          digitalWrite(PulsePin1, HIGH);
          break;
        case 1:
          digitalWrite(PulsePin2, HIGH);
          break;
        case 2:
          digitalWrite(PulsePin3, HIGH);
          break;
        case 3:
          digitalWrite(PulsePin4, HIGH);
          break;
        default:
          break;
      }
    }
  }

}

void getPeriod(void)
{
  if (freq1 != 0)
  {
    period[0] = 1000000 / abs(freq1);
  }
  else
  {
    period[0] = 0;
  }

  if (freq2 != 0)
  {
    period[1] = 1000000 / abs(freq2);
  }
  else
  {
    period[1] = 0;
  }

  if (freq3 != 0)
  {
    period[2] = 1000000 / abs(freq3);
  }
  else
  {
    period[2] = 0;
  }

  if (freq4 != 0)
  {
    period[3] = 1000000 / abs(freq4);
  }
  else
  {
    period[3] = 0;
  }

}


void setDirection(void)
{
  if (freq1 >= 0)
  {
    digitalWrite(DirectionPin1, HIGH);
  }
  else
  {
    digitalWrite(DirectionPin1, LOW);
  }

  if (freq2 >= 0)
  {
    digitalWrite(DirectionPin2, HIGH);
  }
  else
  {
    digitalWrite(DirectionPin2, LOW);
  }

  if (freq3 >= 0)
  {
    digitalWrite(DirectionPin3, HIGH);
  }
  else
  {
    digitalWrite(DirectionPin3, LOW);
  }

  if (freq4 >= 0)
  {
    digitalWrite(DirectionPin4, HIGH);
  }
  else
  {
    digitalWrite(DirectionPin4, LOW);
  }
}

void rotation(int clockwise, int rotsp)
{
  if (clockwise == CW)
  {
    freqAim(1, rotsp);
    freqAim(2, rotsp);
    freqAim(3, rotsp);
    freqAim(4, rotsp);
  }
  else  //clockwise == CCW
  {
    freqAim(1, -1 * rotsp);
    freqAim(2, -1 * rotsp);
    freqAim(3, -1 * rotsp);
    freqAim(4, -1 * rotsp);
  }
}

void translation(int degree, int goalFreq)
{
  float vx = goalFreq * cos(radians(degree));
  float vy = goalFreq * sin(radians(degree));

  freqAim(1, -1 * (int)vy);
  freqAim(2, (int)vx);
  freqAim(3, (int)vy);
  freqAim(4, -1 * (int)vx);
}

void freqAim(int number, int goalFrequency)
{
  switch (number) {
    case 1:
      if (goalFrequency > freq1)
      {
        if (goalFrequency - freq1 > MaxAcc)
        {
          freq1 += MaxAcc;
        }
        else
        {
          freq1 = goalFrequency;
        }
      }
      else if (goalFrequency < freq1)
      {
        if (freq1 - goalFrequency > MaxAcc)
        {
          freq1 -= MaxAcc;
        }
        else
        {
          freq1 = goalFrequency;
        }
      }
      break;
    case 2:
      if (goalFrequency > freq2)
      {
        if (goalFrequency - freq2 > MaxAcc)
        {
          freq2 += MaxAcc;
        }
        else
        {
          freq2 = goalFrequency;
        }
      }
      else if (goalFrequency < freq2)
      {
        if (freq2 - goalFrequency > MaxAcc)
        {
          freq2 -= MaxAcc;
        }
        else
        {
          freq2 = goalFrequency;
        }
      }

      break;
    case 3:
      if (goalFrequency > freq3)
      {
        if (goalFrequency - freq3 > MaxAcc)
        {
          freq3 += MaxAcc;
        }
        else
        {
          freq3 = goalFrequency;
        }
      }
      else if (goalFrequency < freq3)
      {
        if (freq3 - goalFrequency > MaxAcc)
        {
          freq3 -= MaxAcc;
        }
        else
        {
          freq3 = goalFrequency;
        }
      }

      break;
    case 4:
      if (goalFrequency > freq4)
      {
        if (goalFrequency - freq4 > MaxAcc)
        {
          freq4 += MaxAcc;
        }
        else
        {
          freq4 = goalFrequency;
        }
      }
      else if (goalFrequency < freq4)
      {
        if (freq4 - goalFrequency > MaxAcc)
        {
          freq4 -= MaxAcc;
        }
        else
        {
          freq4 = goalFrequency;
        }
      }

      break;
    default:
      break;
  }
}


/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent1() {
  while (Serial1.available() > 0) {
    // get the new byte:
    char inChar = (char)Serial1.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
