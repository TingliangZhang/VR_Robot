using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace DobotClientDemo.CPlusDll
{
    public class DobotDll
    {
        [DllImport("DobotDll.dll", EntryPoint = "DobotExec", CallingConvention = CallingConvention.Cdecl)]
        public static extern int DobotExec();

        [DllImport("DobotDll.dll", EntryPoint = "ConnectDobot", CallingConvention = CallingConvention.Cdecl)]
        public static extern int ConnectDobot(string portName, int baudrate, StringBuilder fwType, StringBuilder version);
        [DllImport("DobotDll.dll", EntryPoint = "DisconnectDobot", CallingConvention = CallingConvention.Cdecl)]
        public static extern void DisconnectDobot();
        [DllImport("DobotDll.dll", EntryPoint = "SearchDobot", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SearchDobot(StringBuilder dobotNameList, UInt32 maxLen);
        [DllImport("DobotDll.dll", EntryPoint = "SetCmdTimeout", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetCmdTimeout(uint ms);

        // Queued command control!
        [DllImport("DobotDll.dll", EntryPoint = "SetQueuedCmdStartExec", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetQueuedCmdStartExec();

        [DllImport("DobotDll.dll", EntryPoint = "SetQueuedCmdStopExec", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetQueuedCmdStopExec();

        [DllImport("DobotDll.dll", EntryPoint = "SetQueuedCmdForceStopExec", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetQueuedCmdForceStopExec();

        [DllImport("DobotDll.dll", EntryPoint = "SetQueuedCmdStartDownload", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetQueuedCmdStartDownload(UInt32 totalLoop, UInt32 linePerLoop);
        [DllImport("DobotDll.dll", EntryPoint = "SetQueuedCmdStopDownload", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetQueuedCmdStopDownload();
        [DllImport("DobotDll.dll", EntryPoint = "SetQueuedCmdClear", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetQueuedCmdClear();
        [DllImport("DobotDll.dll", EntryPoint = "GetQueuedCmdCurrentIndex", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetQueuedCmdCurrentIndex(ref UInt64 cmdIndex);

        // Device information
        [DllImport("DobotDll.dll", EntryPoint = "SetDeviceSN", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetDeviceSN(string deviceSN);

        [DllImport("DobotDll.dll", EntryPoint = "GetDeviceSN", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetDeviceSN(StringBuilder deviceSN, UInt32 maxlen);

        // Public functions
        // EndType Parameters
        [DllImport("DobotDll.dll", EntryPoint = "SetDeviceName", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetDeviceName(string deviceSN);

        [DllImport("DobotDll.dll", EntryPoint = "GetDeviceName", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetDeviceName(StringBuilder deviceSN, UInt32 maxlen);

        // public static extern functions
        [DllImport("DobotDll.dll", EntryPoint = "SetEndEffectorParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetEndEffectorParams(ref EndTypeParams type);
        [DllImport("DobotDll.dll", EntryPoint = "GetEndEffectorParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetEndEffectorParams(ref EndTypeParams type);

        [DllImport("DobotDll.dll", EntryPoint = "SetEndEffectorLaser", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetEndEffectorLaser(bool enableCtrl, bool on, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetEndEffectorParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetEndEffectorLaser(ref bool enableCtrl, ref bool isOn);

        [DllImport("DobotDll.dll", EntryPoint = "SetEndEffectorSuctionCup", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetEndEffectorSuctionCup(bool enableCtrl, bool on, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetEndEffectorParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetEndEffectorSuctionCup(ref bool enableCtrl, ref bool isOn);

        [DllImport("DobotDll.dll", EntryPoint = "SetEndEffectorGripper", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetEndEffectorGripper(bool enableCtrl, bool on, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetEndEffectorParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetEndEffectorGripper(ref bool enableCtrl, ref bool isOn);

        // InitialPose
        [DllImport("DobotDll.dll", EntryPoint = "ResetPose", CallingConvention = CallingConvention.Cdecl)]
        public static extern int ResetPose(bool manual, float rearArmAngle, float frontArmAngle);

        // Pose and Kinematics parameters are automatically get
        [DllImport("DobotDll.dll", EntryPoint = "GetPose", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPose(ref Pose pose);
        [DllImport("DobotDll.dll", EntryPoint = "GetKinematics", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetKinematics(ref Kinematics pose);

        // Alarms
        [DllImport("DobotDll.dll", EntryPoint = "GetAlarmsState", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetAlarmsState([MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 2)] byte[] alarmsState, ref UInt32 len, Int32 maxLen);
        [DllImport("DobotDll.dll", EntryPoint = "ClearAllAlarmsState", CallingConvention = CallingConvention.Cdecl)]
        public static extern int ClearAllAlarmsState();

        // HOME
        [DllImport("DobotDll.dll", EntryPoint = "SetHOMEParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetHOMEParams(ref HOMEParams homeParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetHOMEParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetHOMEParams(ref HOMEParams homeParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetHOMECmd", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetHOMECmd(ref HOMECmd homeCmd, bool isQueued, ref UInt64 queuedCmdIndex);

        // Jog functions
        [DllImport("DobotDll.dll", EntryPoint = "SetJOGJointParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetJOGJointParams(ref JOGJointParams jointJogParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetJOGJointParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetJOGJointParams(ref JOGJointParams jointJogParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetJOGCoordinateParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetJOGCoordinateParams(ref JOGCoordinateParams coordinateJogParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetJOGCoordinateParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetJOGCoordinateParams(ref JOGCoordinateParams coordinateJogParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetJOGCommonParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetJOGCommonParams(ref JOGCommonParams jogCommonParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetJogCommonParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetJogCommonParams(ref JOGCommonParams jogCommonParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetJOGCmd", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetJOGCmd(ref JogCmd jogCmd, bool isQueued, ref UInt64 queuedCmdIndex);

        // PTP functions
        [DllImport("DobotDll.dll", EntryPoint = "SetPTPJointParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetPTPJointParams(ref PTPJointParams playbackSpeedParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetPTPJointParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPTPJointParams(ref PTPJointParams playbackSpeedParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetPTPCoordinateParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetPTPCoordinateParams(ref PTPCoordinateParams playbackJumpParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetPlaybackJumpParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPTPCoordinateParams(ref PTPCoordinateParams playbackJumpParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetPTPJumpParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetPTPJumpParams(ref PTPJumpParams playbackCommonParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetPlaybackCommonParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPTPJumpParams(ref PTPJumpParams playbackCommonParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetPTPCommonParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetPTPCommonParams(ref PTPCommonParams ptpCommonParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetPTPCommonParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetPTPCommonParams(ref PTPCommonParams ptpCommonParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetPTPCmd", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetPTPCmd(ref PTPCmd playbackCmd, bool isQueued, ref UInt64 queuedCmdIndex);

        // CP functions
        [DllImport("DobotDll.dll", EntryPoint = "SetCPParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetCPParams(ref CPParams cpParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetCPParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetCPParams(ref CPParams cpParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetCPCmd", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetCPCmd(ref CPCmd cpCmd, bool isQueued, ref UInt64 queuedCmdIndex);

        // WAIT
        [DllImport("DobotDll.dll", EntryPoint = "SetWAITCmd", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetWAITCmd(ref WAITCmd waitCmd, bool isQueued, ref UInt64 queuedCmdIndex);

        //EIO
        [DllImport("DobotDll.dll", EntryPoint = "SetIOMultiplexing", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetIOMultiplexing(ref IOMultiplexing ioMultiplexing, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetIOMultiplexing", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetIOMultiplexing(ref IOMultiplexing ioMultiplexing);
        [DllImport("DobotDll.dll", EntryPoint = "SetIODO", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetIODO(ref IODO ioDO, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetIODO", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetIODO(ref IODO ioDO);
        [DllImport("DobotDll.dll", EntryPoint = "SetIOPWM", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetIOPWM(ref IOPWM ioPWM, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetIODO", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetIOPWM(ref IOPWM ioPWM);
        [DllImport("DobotDll.dll", EntryPoint = "GetIODI", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetIODI(ref IODI IODI);
        [DllImport("DobotDll.dll", EntryPoint = "GetIOADC", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetIOADC(ref IOADC ioPWM);


        [DllImport("DobotDll.dll", EntryPoint = "SetARCParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetARCParams(ref ARCParams arcParams, bool isQueued, ref UInt64 queuedCmdIndex);
        [DllImport("DobotDll.dll", EntryPoint = "GetARCParams", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetARCParams(ref ARCParams arcParams);
        [DllImport("DobotDll.dll", EntryPoint = "SetARCCmd", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetARCCmd(ref ARCCmd arcCmd, bool isQueued, ref UInt64 queuedCmdIndex);
    }
}
