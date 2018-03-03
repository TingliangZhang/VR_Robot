#ifndef DOBOTDLL_H
#define DOBOTDLL_H

#include "dobotdll_global.h"
#include "DobotType.h"

extern "C" DOBOTDLLSHARED_EXPORT int DobotExec(void);

extern "C" DOBOTDLLSHARED_EXPORT int SearchDobot(char *dobotNameList, uint32_t maxLen);
extern "C" DOBOTDLLSHARED_EXPORT int ConnectDobot(const char *portName, uint32_t baudrate, char *fwType, char *version, int *dobotId);
extern "C" DOBOTDLLSHARED_EXPORT int DisconnectDobot(int dobotId);

extern "C" DOBOTDLLSHARED_EXPORT int SetCmdTimeout(int dobotId, uint32_t cmdTimeout);

// Device information
extern "C" DOBOTDLLSHARED_EXPORT int SetDeviceSN(int dobotId, const char *deviceSN);
extern "C" DOBOTDLLSHARED_EXPORT int GetDeviceSN(int dobotId, char *deviceSN, uint32_t maxLen);

extern "C" DOBOTDLLSHARED_EXPORT int SetDeviceName(int dobotId, const char *deviceName);
extern "C" DOBOTDLLSHARED_EXPORT int GetDeviceName(int dobotId, char *deviceName, uint32_t maxLen);

extern "C" DOBOTDLLSHARED_EXPORT int GetDeviceVersion(int dobotId, uint8_t *majorVersion, uint8_t *minorVersion, uint8_t *revision);

extern "C" DOBOTDLLSHARED_EXPORT int SetDeviceWithL(int dobotId, bool isWithL);
extern "C" DOBOTDLLSHARED_EXPORT int GetDeviceWithL(int dobotId, bool *isWithL);

extern "C" DOBOTDLLSHARED_EXPORT int GetDeviceTime(int dobotId, uint32_t *deviceTime);

// Pose and Kinematics parameters are automatically get
extern "C" DOBOTDLLSHARED_EXPORT int GetPose(int dobotId, Pose *pose);
extern "C" DOBOTDLLSHARED_EXPORT int GetPoseEx(int dobotId, Pose *pose);
extern "C" DOBOTDLLSHARED_EXPORT int ResetPose(int dobotId, bool manual, float rearArmAngle, float frontArmAngle);
extern "C" DOBOTDLLSHARED_EXPORT int GetKinematics(int dobotId, Kinematics *kinematics);
extern "C" DOBOTDLLSHARED_EXPORT int GetPoseL(int dobotId, float *l);

// Alarms
extern "C" DOBOTDLLSHARED_EXPORT int GetAlarmsState(int dobotId, uint8_t *alarmsState, uint32_t *len, uint32_t maxLen);
extern "C" DOBOTDLLSHARED_EXPORT int ClearAllAlarmsState(int dobotId);

// HOME
extern "C" DOBOTDLLSHARED_EXPORT int SetHOMEParams(int dobotId, HOMEParams *homeParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetHOMEParams(int dobotId, HOMEParams *homeParams);

extern "C" DOBOTDLLSHARED_EXPORT int SetHOMECmd(int dobotId, HOMECmd *homeCmd, bool isQueued, uint64_t *queuedCmdIndex);

extern "C" DOBOTDLLSHARED_EXPORT int SetAutoLevelingCmd(int dobotId, AutoLevelingCmd *autoLevelingCmd, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetAutoLevelingResult(int dobotId, float *precision);

// Handheld teach
extern "C" DOBOTDLLSHARED_EXPORT int SetHHTTrigMode(int dobotId, HHTTrigMode hhtTrigMode);
extern "C" DOBOTDLLSHARED_EXPORT int GetHHTTrigMode(int dobotId, HHTTrigMode *hhtTrigMode);

extern "C" DOBOTDLLSHARED_EXPORT int SetHHTTrigOutputEnabled(int dobotId, bool isEnabled);
extern "C" DOBOTDLLSHARED_EXPORT int GetHHTTrigOutputEnabled(int dobotId, bool *isEnabled);

extern "C" DOBOTDLLSHARED_EXPORT int GetHHTTrigOutput(int dobotId, bool *isTriggered);

// EndEffector
extern "C" DOBOTDLLSHARED_EXPORT int SetEndEffectorParams(int dobotId, EndEffectorParams *endEffectorParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetEndEffectorParams(int dobotId, EndEffectorParams *endEffectorParams);

extern "C" DOBOTDLLSHARED_EXPORT int SetEndEffectorLaser(int dobotId, bool enableCtrl, bool on, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetEndEffectorLaser(int dobotId, bool *isCtrlEnabled, bool *isOn);

extern "C" DOBOTDLLSHARED_EXPORT int SetEndEffectorSuctionCup(int dobotId, bool enableCtrl, bool suck, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetEndEffectorSuctionCup(int dobotId, bool *isCtrlEnabled, bool *isSucked);

extern "C" DOBOTDLLSHARED_EXPORT int SetEndEffectorGripper(int dobotId, bool enableCtrl, bool grip, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetEndEffectorGripper(int dobotId, bool *isCtrlEnabled, bool *isGripped);

// Arm orientation
extern "C" DOBOTDLLSHARED_EXPORT int SetArmOrientation(int dobotId, ArmOrientation armOrientation, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetArmOrientation(int dobotId, ArmOrientation *armOrientation);

// JOG functions
extern "C" DOBOTDLLSHARED_EXPORT int SetJOGJointParams(int dobotId, JOGJointParams *jointJogParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetJOGJointParams(int dobotId, JOGJointParams *jointJogParams);

extern "C" DOBOTDLLSHARED_EXPORT int SetJOGCoordinateParams(int dobotId, JOGCoordinateParams *coordinateJogParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetJOGCoordinateParams(int dobotId, JOGCoordinateParams *coordinateJogParams);

extern "C" DOBOTDLLSHARED_EXPORT int SetJOGLParams(int dobotId, JOGLParams *jogLParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetJOGLParams(int dobotId, JOGLParams *jogLParams);

extern "C" DOBOTDLLSHARED_EXPORT int SetJOGCommonParams(int dobotId, JOGCommonParams *jogCommonParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetJOGCommonParams(int dobotId, JOGCommonParams *jogCommonParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetJOGCmd(int dobotId, JOGCmd *jogCmd, bool isQueued, uint64_t *queuedCmdIndex);

// PTP functions
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPJointParams(int dobotId, PTPJointParams *ptpJointParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPJointParams(int dobotId, PTPJointParams *ptpJointParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPCoordinateParams(int dobotId, PTPCoordinateParams *ptpCoordinateParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPCoordinateParams(int dobotId, PTPCoordinateParams *ptpCoordinateParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPLParams(int dobotId, PTPLParams *ptpLParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPLParams(int dobotId, PTPLParams *ptpLParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPJumpParams(int dobotId, PTPJumpParams *ptpJumpParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPJumpParams(int dobotId, PTPJumpParams *ptpJumpParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPCommonParams(int dobotId, PTPCommonParams *ptpCommonParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPCommonParams(int dobotId, PTPCommonParams *ptpCommonParams);

extern "C" DOBOTDLLSHARED_EXPORT int SetPTPCmd(int dobotId, PTPCmd *ptpCmd, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPWithLCmd(int dobotId, PTPWithLCmd *ptpWithLCmd, bool isQueued, uint64_t *queuedCmdIndex);

extern "C" DOBOTDLLSHARED_EXPORT int SetPTPJump2Params(int dobotId, PTPJump2Params *ptpJump2Params, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPJump2Params(int dobotId, PTPJump2Params *ptpJump2Params);

extern "C" DOBOTDLLSHARED_EXPORT int SetPTPPOCmd(int dobotId, PTPCmd *ptpCmd, ParallelOutputCmd *parallelCmd, int parallelCmdCount, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int SetPTPPOWithLCmd(int dobotId, PTPWithLCmd *ptpWithLCmd, ParallelOutputCmd *parallelCmd, int parallelCmdCount, bool isQueued, uint64_t *queuedCmdIndex);

// CP functions
extern "C" DOBOTDLLSHARED_EXPORT int SetCPParams(int dobotId, CPParams *cpParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetCPParams(int dobotId, CPParams *cpParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetCPCmd(int dobotId, CPCmd *cpCmd, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int SetCPLECmd(int dobotId, CPCmd *cpCmd, bool isQueued, uint64_t *queuedCmdIndex);

// ARC
extern "C" DOBOTDLLSHARED_EXPORT int SetARCParams(int dobotId, ARCParams *arcParams, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetARCParams(int dobotId, ARCParams *arcParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetARCCmd(int dobotId, ARCCmd *arcCmd, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int SetCircleCmd(int dobotId, CircleCmd *circleCmd, bool isQueued, uint64_t *queuedCmdIndex);

// WAIT
extern "C" DOBOTDLLSHARED_EXPORT int SetWAITCmd(int dobotId, WAITCmd *waitCmd, bool isQueued, uint64_t *queuedCmdIndex);

// TRIG
extern "C" DOBOTDLLSHARED_EXPORT int SetTRIGCmd(int dobotId, TRIGCmd *trigCmd, bool isQueued, uint64_t *queuedCmdIndex);

// EIO
extern "C" DOBOTDLLSHARED_EXPORT int SetIOMultiplexing(int dobotId, IOMultiplexing *ioMultiplexing, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetIOMultiplexing(int dobotId, IOMultiplexing *ioMultiplexing);

extern "C" DOBOTDLLSHARED_EXPORT int SetIODO(int dobotId, IODO *ioDO, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetIODO(int dobotId, IODO *ioDO);

extern "C" DOBOTDLLSHARED_EXPORT int SetIOPWM(int dobotId, IOPWM *ioPWM, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetIOPWM(int dobotId, IOPWM *ioPWM);

extern "C" DOBOTDLLSHARED_EXPORT int GetIODI(int dobotId, IODI *ioDI);
extern "C" DOBOTDLLSHARED_EXPORT int GetIOADC(int dobotId, IOADC *ioADC);

extern "C" DOBOTDLLSHARED_EXPORT int SetEMotor(int dobotId, EMotor *eMotor, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int SetEMotorS(int dobotId, EMotorS *eMotorS, bool isQueued, uint64_t *queuedCmdIndex);

extern "C" DOBOTDLLSHARED_EXPORT int SetColorSensor(int dobotId, bool enable,ColorPort colorPort);
extern "C" DOBOTDLLSHARED_EXPORT int GetColorSensor(int dobotId, uint8_t *r, uint8_t *g, uint8_t *b);

extern "C" DOBOTDLLSHARED_EXPORT int SetInfraredSensor(int dobotId, bool enable,InfraredPort infraredPort);
extern "C" DOBOTDLLSHARED_EXPORT int GetInfraredSensor(int dobotId, InfraredPort port, uint8_t *value);

// CAL
extern "C" DOBOTDLLSHARED_EXPORT int SetAngleSensorStaticError(int dobotId, float rearArmAngleError, float frontArmAngleError);
extern "C" DOBOTDLLSHARED_EXPORT int GetAngleSensorStaticError(int dobotId, float *rearArmAngleError, float *frontArmAngleError);
extern "C" DOBOTDLLSHARED_EXPORT int SetAngleSensorCoef(int dobotId, float rearArmAngleCoef, float frontArmAngleCoef);
extern "C" DOBOTDLLSHARED_EXPORT int GetAngleSensorCoef(int dobotId, float *rearArmAngleCoef, float *frontArmAngleCoef);

extern "C" DOBOTDLLSHARED_EXPORT int SetBaseDecoderStaticError(int dobotId, float baseDecoderError);
extern "C" DOBOTDLLSHARED_EXPORT int GetBaseDecoderStaticError(int dobotId, float *baseDecoderError);

extern "C" DOBOTDLLSHARED_EXPORT int SetLRHandCalibrateValue(int dobotId, float lrHandCalibrateValue);
extern "C" DOBOTDLLSHARED_EXPORT int GetLRHandCalibrateValue(int dobotId, float *lrHandCalibrateValue);

// WIFI
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFIConfigMode(int dobotId, bool enable);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFIConfigMode(int dobotId, bool *isEnabled);
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFISSID(int dobotId, const char *ssid);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFISSID(int dobotId, char *ssid, uint32_t maxLen);
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFIPassword(int dobotId, const char *password);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFIPassword(int dobotId, char *password, uint32_t maxLen);
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFIIPAddress(int dobotId, WIFIIPAddress *wifiIPAddress);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFIIPAddress(int dobotId, WIFIIPAddress *wifiIPAddress);
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFINetmask(int dobotId, WIFINetmask *wifiNetmask);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFINetmask(int dobotId, WIFINetmask *wifiNetmask);
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFIGateway(int dobotId, WIFIGateway *wifiGateway);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFIGateway(int dobotId, WIFIGateway *wifiGateway);
extern "C" DOBOTDLLSHARED_EXPORT int SetWIFIDNS(int dobotId, WIFIDNS *wifiDNS);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFIDNS(int dobotId, WIFIDNS *wifiDNS);
extern "C" DOBOTDLLSHARED_EXPORT int GetWIFIConnectStatus(int dobotId, bool *isConnected);

//FIRMWARE
extern "C" DOBOTDLLSHARED_EXPORT int UpdateFirmware(int dobotId, FirmwareParams *firmwareParams);
extern "C" DOBOTDLLSHARED_EXPORT int SetFirmwareMode(int dobotId, FirmwareMode *firmwareMode);
extern "C" DOBOTDLLSHARED_EXPORT int GetFirmwareMode(int dobotId, FirmwareMode *firmwareMode);

//LOSTSTEP
extern "C" DOBOTDLLSHARED_EXPORT int SetLostStepParams(int dobotId, float threshold);
extern "C" DOBOTDLLSHARED_EXPORT int SetLostStepCmd(int dobotId, bool isQueued, uint64_t *queuedCmdIndex);

// TEST
extern "C" DOBOTDLLSHARED_EXPORT int GetUserParams(int dobotId, UserParams *userParams);
extern "C" DOBOTDLLSHARED_EXPORT int GetPTPTime(int dobotId, PTPCmd *ptpCmd, uint32_t *ptpTime);
extern "C" DOBOTDLLSHARED_EXPORT int GetServoPIDParams(int dobotId, PID *pid);
extern "C" DOBOTDLLSHARED_EXPORT int SetServoPIDParams(int dobotId, PID *pid, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int GetServoControlLoop(int dobotId, uint8_t index, uint8_t *controlLoop);
extern "C" DOBOTDLLSHARED_EXPORT int SetServoControlLoop(int dobotId, uint8_t index, uint8_t controlLoop, bool isQueued, uint64_t *queuedCmdIndex);
extern "C" DOBOTDLLSHARED_EXPORT int SaveServoPIDParams(int dobotId, uint8_t index, uint8_t controlLoop, bool isQueued, uint64_t *queuedCmdIndex);

// Queued command
extern "C" DOBOTDLLSHARED_EXPORT int SetQueuedCmdStartExec(int dobotId);
extern "C" DOBOTDLLSHARED_EXPORT int SetQueuedCmdStopExec(int dobotId);
extern "C" DOBOTDLLSHARED_EXPORT int SetQueuedCmdForceStopExec(int dobotId);
extern "C" DOBOTDLLSHARED_EXPORT int SetQueuedCmdStartDownload(int dobotId, uint32_t totalLoop, uint32_t linePerLoop);
extern "C" DOBOTDLLSHARED_EXPORT int SetQueuedCmdStopDownload(int dobotId);
extern "C" DOBOTDLLSHARED_EXPORT int SetQueuedCmdClear(int dobotId);
extern "C" DOBOTDLLSHARED_EXPORT int GetQueuedCmdCurrentIndex(int dobotId, uint64_t *queuedCmdCurrentIndex);

#endif // DOBOTDLL_H
