/****************************************Copyright(c)*****************************************************
**                            Shenzhen Yuejiang Technology Co., LTD.
**
**                                 http://www.dobot.cc
**
**--------------File Info---------------------------------------------------------------------------------
** File name:           HardFault.c
** Latest modified Date:
** Latest Version:      V1.0.0
** Descriptions:
**
**--------------------------------------------------------------------------------------------------------
** Created by:          Liu Zhufu
** Created date:        2016-05-25
** Version:             V1.0.0
** Descriptions:
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/

#include "stm32f10x.h"
/*********************************************************************************************************
** Function name:       SystickInit
** Descriptions:        Init SysTick clock
** Input parameters:    none
** Output parameters:   none
** Returned value:      none
*********************************************************************************************************/
void SystickInit(void)
{
    SysTick_Config(SystemCoreClock / 1000); //1ms interrupt
    NVIC_SetPriority (SysTick_IRQn, 1);
}
