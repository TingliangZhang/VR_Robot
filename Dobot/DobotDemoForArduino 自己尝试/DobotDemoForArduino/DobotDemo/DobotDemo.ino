//加速度=0？修改dx?手柄阈值？Serial.x注释掉？速率比是什么？loop结构？


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
int valuex, valuey, valuez = 0;
//Set Serial TX&RX Buffer Size
#define SERIAL_TX_BUFFER_SIZE 64
#define SERIAL_RX_BUFFER_SIZE 256

//#define JOG_STICK //有一定判断所用
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
  Serial.begin(115200);
  Serial1.begin(115200);
  printf_begin();
  //Set Timer Interrupt
  FlexiTimer2::set(100, Serialread);
  FlexiTimer2::start();
  pinMode(24, INPUT_PULLUP);
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
  gJOGJointParams.velocity[0] = 200;
  gJOGJointParams.velocity[1] = 200;
  gJOGJointParams.velocity[2] = 200;
  gJOGJointParams.velocity[3] = 200;
  gJOGJointParams.acceleration[0] = 80;
  gJOGJointParams.acceleration[1] = 80;
  gJOGJointParams.acceleration[2] = 80;
  gJOGJointParams.acceleration[3] = 80;

  gJOGCoordinateParams.velocity[0] = 200;
  gJOGCoordinateParams.velocity[1] = 200;
  gJOGCoordinateParams.velocity[2] = 200;
  gJOGCoordinateParams.velocity[3] = 200;
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
  InitRAM();

  ProtocolInit();

  SetJOGJointParams(&gJOGJointParams, true, &gQueuedCmdIndex);

  SetJOGCoordinateParams(&gJOGCoordinateParams, true, &gQueuedCmdIndex);

  SetJOGCommonParams(&gJOGCommonParams, true, &gQueuedCmdIndex);

  SetPTPCoordinateParams(&gPTPCoordinateParams, true, &gQueuedCmdIndex);

  /*
     以下为demo部分
  */

  printf("\r\n======Enter demo application by LIU======\r\n");

  SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  for (; ;)
  {
    static uint32_t timer = millis();//常数，millis会变化
    static uint32_t count = 0;
    static uint32_t timer_move = millis();
    int tempofcount;
    /*
       定义了JOG_STICK，则为来回旋转，没有定义的话，则为伸缩模式。
    */
    /* #ifdef JOG_STICK
      if(millis() - timer > 1000)//更加巧妙的延时方式，延时1秒钟//如果定义了JOG_STICK则运行这个，如果没有定义，则运行下面一段//旋转程序
      {

             gPTPCmd.x += 10;//配置PTP 运动X 坐标+100
             //运动PTP 运动，坐标为gPTPCmd 结构体里面的坐标
             SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
             printf("  x= %f",gPTPCmd.x);
             printf("  y= %f",gPTPCmd.y);
             printf("  z= %f",gPTPCmd.z);
             printf("  r= %f",gPTPCmd.r);
             printf("================");
             //printf("x= %d,y= %d.z= %d,r= %d\n",gPTPCmd.x,gPTPCmd.y,gPTPCmd.z，gPTPCmd.r);
             delay(1000);
             gPTPCmd.x -= 10;//配置PTP 运动X 坐标+100
             //运动PTP 运动，坐标为gPTPCmd 结构体里面的坐标
             SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
             printf("  x= %f",gPTPCmd.x);
             printf("  y= %f",gPTPCmd.y);
             printf("  z= %f",gPTPCmd.z);
             printf("  r= %f",gPTPCmd.r);
             printf("================");
             delay(1000);
      }
      #else//如果没有定义，则运行下面一段*/
            if(millis() - timer > 100)//伸缩程序
            {
                timer = millis();
                valuex = analogRead(A1);
                 Serial.print("X:");
                 Serial.print(valuex, DEC);
                 valuey = analogRead(A2);
                 Serial.print(" | Y:");
                 Serial.print(valuey, DEC);
                 valuez = digitalRead(24);
                 Serial.print(" | Z: ");
                 Serial.println(valuez, DEC);
                 if(valuex<400)
                 {
                  gPTPCmd.x += 5;
                 }
                 else if(valuex>600)
                 {
                  gPTPCmd.x -= 5;
                 }
                  if(valuey<400)
                 {
                  gPTPCmd.y -= 5;
                 }
                 else if(valuey>600)
                 {
                  gPTPCmd.y += 5;
                 }
                  if(valuez==0)
                 {
                  gPTPCmd.z += 5;
                 }
    
    /*count++;
      if(count & 0x01)//转化成二进制后进行位运算，把count和0x01按位与。意思是判断count的最低位是否为0.
      {
        gPTPCmd.x += 10;//配置PTP 运动X 坐标+100
        gPTPCmd.y += 10;
        gPTPCmd.z += 10;
        //运动PTP 运动，坐标为gPTPCmd 结构体里面的坐标
        printf("\n==========================================\n");
        printf("  x= "); Serial.print(gPTPCmd.x);
        printf("  y= "); Serial.print(gPTPCmd.y);
        printf("  z= "); Serial.print(gPTPCmd.z);
        printf("  r= "); Serial.print(gPTPCmd.r);
        printf("\n==========================================\n");
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
        delay(3000);
      }
      else
      {
        gPTPCmd.x -= 10;
        gPTPCmd.y -= 10;
        gPTPCmd.z -= 10;
        printf("\n==========================================\n");
        printf("  x= "); Serial.print(gPTPCmd.x);
        printf("  y= "); Serial.print(gPTPCmd.y);
        printf("  z= "); Serial.print(gPTPCmd.z);
        printf("  r= "); Serial.print(gPTPCmd.r);
        printf("\n==========================================\n");
        SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
        delay(3000);
      }*/
  }
          if(millis() - timer_move > 1000)//一次运行时间与下一次运行时间间隔两秒钟
          {
            timer_move = millis();
           SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
  
          //#endif
          }

  /*
     以上为demo部分，应该是。。。。
  */
  ProtocolProcess();//Protocol 进程
}
}

