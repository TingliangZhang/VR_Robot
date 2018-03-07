    //read PPM signals from 2 channels of an RC reciever
    //http://arduino.cc/forum/index.php/topic,42286.0.html
    
    //接收机两个通道分别接arduino的数字口2、3脚
    //Most Arduino boards have two external interrupts: numbers 0 (on digital pin 2) and 1 (on digital pin 3).
    //The Arduino Mega has an additional four: numbers 2 (pin 21), 3 (pin 20), 4 (pin 19), and 5 (pin 18).
    int ppm1 = 2;  //channel 1 connect to T14SG Reciever channel No.1 PITCH (interrupts: numbers 0)
    int ppm2 = 3;  //channel 2 connect to T14SG Reciever channel No.2 YAW (interrupts: numbers 1)
    int ppm3 = 20;  //channel 3 connect to T14SG Reciever channel No.3 THROTTLE (interrupts: numbers 3)
    int ppm4 = 21;  //channel 4 connect to T14SG Reciever channel No.4 ROLL (interrupts: numbers 2)
    
    unsigned long rc1_PulseStartTicks, rc2_PulseStartTicks, rc3_PulseStartTicks, rc4_PulseStartTicks;
    volatile int rc1_val, rc2_val, rc3_val, rc4_val;
    
    /****************************************Copyright(c)*****************************************************
    **                            Shenzhen Yuejiang Technology Co., LTD.
    **
    **                                 http://www.dobot.cc
    **
    **--------------File Info---------------------------------------------------------------------------------
    ** File name:           main.cpp
    ** Latest modified Date:2016-10-24
    ** Latest Version:      V2.0.0
    ** Descriptions:        main body
    **
    **--------------------------------------------------------------------------------------------------------
    ** Modify by:           Edward
    ** Modified date:       2016-11-25
    ** Version:             V1.0.0
    ** Descriptions:        Modified,From DobotDemoForSTM32
    **--------------------------------------------------------------------------------------------------------
    *********************************************************************************************************/
    #include "stdio.h"
    #include "Protocol.h"
    #include "command.h"
    #include "FlexiTimer2.h"
    
    //Set Serial TX&RX Buffer Size
    #define SERIAL_TX_BUFFER_SIZE 64
    #define SERIAL_RX_BUFFER_SIZE 256
    
    //#define JOG_STICK
    
    
    int valuex, valuey, valuez, valueflag, xflag, yflag , zflag, flag, value = 0;
    
    /*********************************************************************************************************
    ** Global parameters
    *********************************************************************************************************/
    EndEffectorParams gEndEffectorParams;
    
    JOGJointParams  gJOGJointParams;
    JOGCoordinateParams gJOGCoordinateParams;
    JOGCommonParams gJOGCommonParams;
    JOGCmd          gJOGCmd;
    
    PTPCoordinateParams gPTPCoordinateParams;
    PTPCommonParams gPTPCommonParams;
    PTPCmd          gPTPCmd;
    
    uint64_t gQueuedCmdIndex;
    
    /*********************************************************************************************************
    ** Function name:       setup
    ** Descriptions:        Initializes Serial
    ** Input parameters:    none
    ** Output parameters:   none
    ** Returned value:      none
    *********************************************************************************************************/
    void setup() {
    
      //PPM inputs from RC receiver
      pinMode(ppm1, INPUT);
      pinMode(ppm2, INPUT);
      pinMode(ppm3, INPUT);
      pinMode(ppm4, INPUT);
    
      // 电平变化即触发中断
      attachInterrupt(0, rc1, CHANGE);
      attachInterrupt(1, rc2, CHANGE);
      attachInterrupt(3, rc3, CHANGE);
      attachInterrupt(2, rc4, CHANGE);
    
    
      Serial.begin(115200);
      Serial1.begin(115200);
      printf_begin();
      //Set Timer Interrupt
      FlexiTimer2::set(100, Serialread);
      FlexiTimer2::start();
    }
    
    void rc1()
    {
      // did the pin change to high or low?
      if (digitalRead( ppm1 ) == HIGH)
        rc1_PulseStartTicks = micros();    // store the current micros() value
      else
        rc1_val = micros() - rc1_PulseStartTicks;
    }
    
    void rc2()
    {
      // did the pin change to high or low?
      if (digitalRead( ppm2 ) == HIGH)
        rc2_PulseStartTicks = micros();
      else
        rc2_val = micros() - rc2_PulseStartTicks;
    }
    
    void rc3()
    {
      // did the pin change to high or low?
      if (digitalRead( ppm3 ) == HIGH)
        rc3_PulseStartTicks = micros();    // store the current micros() value
      else
        rc3_val = micros() - rc3_PulseStartTicks;
    }
    void rc4()
    {
      // did the pin change to high or low?
      if (digitalRead( ppm4 ) == HIGH)
        rc4_PulseStartTicks = micros();    // store the current micros() value
      else
        rc4_val = micros() - rc4_PulseStartTicks;
    }
    
    
    /*********************************************************************************************************
    ** Function name:       Serialread
    ** Descriptions:        import data to rxbuffer
    ** Input parametersnone:
    ** Output parameters:
    ** Returned value:
    *********************************************************************************************************/
    void Serialread()
    {
      while (Serial1.available()) {
        uint8_t data = Serial1.read();
        if (RingBufferIsFull(&gSerialProtocolHandler.rxRawByteQueue) == false) {
          RingBufferEnqueue(&gSerialProtocolHandler.rxRawByteQueue, &data);
        }
      }
    }
    /*********************************************************************************************************
    ** Function name:       Serial_putc
    ** Descriptions:        Remap Serial to Printf
    ** Input parametersnone:
    ** Output parameters:
    ** Returned value:
    *********************************************************************************************************/
    int Serial_putc( char c, struct __file * )
    {
      Serial.write( c );
      return c;
    }
    
    /*********************************************************************************************************
    ** Function name:       printf_begin
    ** Descriptions:        Initializes Printf
    ** Input parameters:
    ** Output parameters:
    ** Returned value:
    *********************************************************************************************************/
    void printf_begin(void)
    {
      fdevopen( &Serial_putc, 0 );
    }
    
    /*********************************************************************************************************
    ** Function name:       InitRAM
    ** Descriptions:        Initializes a global variable
    ** Input parameters:    none
    ** Output parameters:   none
    ** Returned value:      none
    *********************************************************************************************************/
    void InitRAM(void)
    {
      //Set JOG Model
      gJOGJointParams.velocity[0] = 100;
      gJOGJointParams.velocity[1] = 100;
      gJOGJointParams.velocity[2] = 100;
      gJOGJointParams.velocity[3] = 100;
      gJOGJointParams.acceleration[0] = 80;
      gJOGJointParams.acceleration[1] = 80;
      gJOGJointParams.acceleration[2] = 80;
      gJOGJointParams.acceleration[3] = 80;
    
      gJOGCoordinateParams.velocity[0] = 100;
      gJOGCoordinateParams.velocity[1] = 100;
      gJOGCoordinateParams.velocity[2] = 100;
      gJOGCoordinateParams.velocity[3] = 100;
      gJOGCoordinateParams.acceleration[0] = 80;
      gJOGCoordinateParams.acceleration[1] = 80;
      gJOGCoordinateParams.acceleration[2] = 80;
      gJOGCoordinateParams.acceleration[3] = 80;
    
      gJOGCommonParams.velocityRatio = 50;
      gJOGCommonParams.accelerationRatio = 50;
    
      gJOGCmd.cmd = AP_DOWN;
      gJOGCmd.isJoint = JOINT_MODEL;
    
    
    
      //Set PTP Model
      gPTPCoordinateParams.xyzVelocity = 100;
      gPTPCoordinateParams.rVelocity = 100;
      gPTPCoordinateParams.xyzAcceleration = 80;
      gPTPCoordinateParams.rAcceleration = 80;
    
      gPTPCommonParams.velocityRatio = 50;
      gPTPCommonParams.accelerationRatio = 50;
    
      gPTPCmd.ptpMode = MOVL_XYZ;
      gPTPCmd.x = 200;
      gPTPCmd.y = 0;
      gPTPCmd.z = 0;
      gPTPCmd.r = 0;
    
      gQueuedCmdIndex = 0;
    
    
    }
    
    /*********************************************************************************************************
    ** Function name:       loop
    ** Descriptions:        Program entry
    ** Input parameters:    none
    ** Output parameters:   none
    ** Returned value:      none
    *********************************************************************************************************/
    
    void loop()
    {
    
      //print values
      Serial.print("channel 1:  ");
      Serial.print(rc1_val);
      Serial.print("        ");
      Serial.print("channel 2:  ");
      Serial.println(rc2_val);
      Serial.print("        ");
      Serial.print("channel 3:  ");
      Serial.print(rc3_val);
      Serial.print("        ");
      Serial.print("channel 4:  ");
      Serial.print(rc4_val);
      Serial.print("        ");
    
      InitRAM();
    
      ProtocolInit();
    
      SetJOGJointParams(&gJOGJointParams, true, &gQueuedCmdIndex);
    
      SetJOGCoordinateParams(&gJOGCoordinateParams, true, &gQueuedCmdIndex);
    
      SetJOGCommonParams(&gJOGCommonParams, true, &gQueuedCmdIndex);
    
      printf("\r\n======Enter demo application======\r\n");
    
      SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
      for (; ;)
      {
        value = 0;
        static uint32_t timer = millis();
        static uint32_t count = 0;
    
        static uint32_t timer_move = millis();
        int tempofcount;
    
        gJOGCmd.isJoint = 0;
        if (millis() - timer > 100) //伸缩程序
        {
    
          timer = millis();
          valuex = rc2_val - 1000;
          Serial.print("X: ");
          Serial.print(valuex, DEC);
          valuey = rc1_val - 1000;
          Serial.print(" | Y: ");
          Serial.print(valuey, DEC);
          valuez = rc3_val - 1000;
          Serial.print(" | Z: ");
          Serial.println(valuez, DEC);
          valueflag = rc4_val - 1000;
          Serial.print(" | FLAG: ");
          Serial.println(valueflag, DEC);
          
    if(rc4_val>1800)
    {
          if (abs(valuez - zflag) > 40)
          {
            gPTPCmd.z = valuez/5;
            SetPTPCmd(&gPTPCmd, false, &gQueuedCmdIndex);
            zflag = valuez;
          }
    }
    else
    {
    
          if (abs(valuex - xflag) > 50)
          {
            if (valuex < 400)
            {
              gJOGCoordinateParams.velocity[0] = (400 - valuex+50) * 2;
              gJOGCmd.cmd = AP_DOWN;
              xflag = valuex;
            }
            else if (valuex > 600)
            {
              gJOGCoordinateParams.velocity[0] = (valuex - 600 + 50) * 2;
              gJOGCmd.cmd = AN_DOWN;
              xflag = valuex;
            }
            value++;
          }
    
          if (abs(valuey - yflag) > 50)
          {
            if (valuey < 400)
            {
              gJOGCoordinateParams.velocity[1] = (400 - valuey + 50) * 2;
              gJOGCmd.cmd = BN_DOWN;
    
            }
            else if (valuey > 600)
            {
              gJOGCoordinateParams.velocity[1] = (valuey - 600 + 50) * 2;
              gJOGCmd.cmd = BP_DOWN;
    
            }
            value++;
          }
          
          if (valuex < 600 && valuex > 400 && valuey < 600 && valuey > 400)
          {
            gJOGCmd.cmd = IDEL;
            value++;
          }

          if (value != 0)
          {
         SetJOGCoordinateParams(&gJOGCoordinateParams, true, &gQueuedCmdIndex);
            SetJOGCmd(&gJOGCmd, true, &gQueuedCmdIndex);
    
          }
    
    }
          ProtocolProcess();
        }
      }
    }

