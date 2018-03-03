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
** Created by:          liyi
** Created date:        2016-10-24
** Version:             V1.0.0
** Descriptions:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

#include "stdio.h"
#include "stm32f10x.h"
#include "../driver/systick.h"
#include "../driver/usart.h"
#include "../ComPlatform/Protocol.h"
#include "command.h"

/*********************************************************************************************************
** Global parameters
*********************************************************************************************************/
extern "C" __IO uint32_t gSystick;

JOGJointParams gJOGJointParams;
JOGCommonParams gJOGCommonParams;
JOGCmd gJOGCmd;

PTPCoordinateParams gPTPCoordinateParams;
PTPCommonParams gPTPCommonParams;
PTPCmd gPTPCmd;

uint64_t gQueuedCmdIndex;

/*********************************************************************************************************
** Function name:       InitRAM
** Descriptions:        Initializes a global variable
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
void InitRAM(void)
{
    gJOGJointParams.velocity[0] = 100;
    gJOGJointParams.velocity[1] = 100;
    gJOGJointParams.velocity[2] = 100;
    gJOGJointParams.velocity[3] = 100;
    gJOGJointParams.acceleration[0] = 80;
    gJOGJointParams.acceleration[1] = 80;
    gJOGJointParams.acceleration[2] = 80;
    gJOGJointParams.acceleration[3] = 80;

    gJOGCommonParams.velocityRatio = 50;
    gJOGCommonParams.accelerationRatio = 50;

    gJOGCmd.cmd = 0;
    gJOGCmd.isJoint = true;

    gPTPCoordinateParams.xyzVelocity = 100;
    gPTPCoordinateParams.rVelocity = 100;
    gPTPCoordinateParams.xyzAcceleration = 80;
    gPTPCoordinateParams.rAcceleration = 80;

    gPTPCommonParams.velocityRatio = 50;
    gPTPCommonParams.accelerationRatio = 50;

    gPTPCmd.ptpMode = MOVL_XYZ;
    gPTPCmd.x = 237.8772;
    gPTPCmd.y = 7.5856;
    gPTPCmd.z = -0.6136;
    gPTPCmd.r = 1.8265;

    gQueuedCmdIndex = 0;
}

/*********************************************************************************************************
** Function name:       main
** Descriptions:        Program entry
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    SystickInit();

    Uart1Init(115200);

    Uart4Init(115200);

    InitRAM();

    ProtocolInit();

    SetPTPCoordinateParams(&gPTPCoordinateParams, true, &gQueuedCmdIndex);

    SetPTPCommonParams(&gPTPCommonParams, true, &gQueuedCmdIndex);

    printf("\r\n======Enetr demo application======\r\n");

    for(; ;)
    {
        static uint32_t timer = gSystick;
        static uint32_t count = 0;
        if(gSystick - timer > 3000)
        {
            timer = gSystick;
            count++;
            if(count & 0x01)
            {
                gPTPCmd.x += 100;
                SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
            }
            else
            {
                gPTPCmd.x -= 100;
                SetPTPCmd(&gPTPCmd, true, &gQueuedCmdIndex);
            }
        }

        ProtocolProcess();
    }
}
