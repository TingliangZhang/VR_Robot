using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace DobotClientDemo.CPlusDll
{
    
    /*
     * 末端选择
     */
    public enum EndType {
        EndTypeCustom,
        EndTypeSuctionCap,
        EndTypeGripper,
        EndTypeLaser,
        EndTypePen,
        EndTypeMax,
        EndTypeNum = EndTypeMax
    };

    [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Ansi, Pack=1)]
    public struct EndTypeParams {
         public float xBias;
         public float yBias;
         public float zBias;
    };

    /*
     * 位姿
     */
    public struct Pose {
        public float x;
        public float y;
        public float z;
        public float rHead;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] jointAngle;
    };

    /*
     * 运动学参数
     */
    public struct Kinematics {
        public float velocity;
        public float acceleration;
    };

    /*
     * 报警状态：暂时支持32种报警状态
     */
    public struct AlarmsState {
        public int alarmsState;
    };

    /*********************************************************************************************************
    ** HOME参数
    *********************************************************************************************************/
    public struct HOMEParams {
        public float x;
        public float y;
        public float z;
        public float r;
    };

    public struct HOMECmd {
        public int temp;
    };

    /*********************************************************************************************************
    ** 点动示教部分
    *********************************************************************************************************/
    /*
     * 单关节点动示教参数
     */
    public struct JOGJointParams
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] velocity;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] acceleration;
    };

    /*
     * 单坐标轴点动示教参数
     */
    public struct JOGCoordinateParams
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] velocity;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] acceleration;
    };

    /*
     * 点动示教公共参数
     */
    public struct JOGCommonParams
    {
        public float velocityRatio;
        public float accelerationRatio;
    };

    /*
     * Jog Cmd
     */
    public enum JogCmdType{
        JogIdle,
        JogAPPressed,
        JogANPressed,
        JogBPPressed,
        JogBNPressed,
        JogCPPressed,
        JogCNPressed,
        JogDPPressed,
        JogDNPressed,
        JogEPPressed,
        JogENPressed
    };

    /*
     * Jog instant cmd
     */
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    public struct JogCmd {
        public byte isJoint;
        public byte cmd;
    };

    /*********************************************************************************************************
    ** 再现运动部分
    *********************************************************************************************************/
    /*
     * 再现运动参数
     */
    public struct PTPJointParams
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] velocity;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 4)]
        public float[] acceleration;
    };
    public struct PTPCoordinateParams
    {
        public float xyzVelocity;
        public float rVelocity;
        public float xyzAcceleration;
        public float rAcceleration;
    };

    public struct PTPJumpParams
    {
        public float jumpHeight;
        public float zLimit;
    };

    public struct PTPCommonParams
    {
        public float velocityRatio;
        public float accelerationRatio;
    };

    // For play back
    public enum PTPMode {
        PTPJUMPXYZMode,
        PTPMOVJXYZMode,
        PTPMOVLXYZMode,

        PTPJUMPANGLEMode,
        PTPMOVJANGLEMode,
        PTPMOVLANGLEMode,

        PTPMOVJXYZINCMode,
        PTPMOVLXYZINCMode,
    };

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    public struct PTPCmd
    {
        public byte ptpMode;
        public float x;
        public float y;
        public float z;
        public float rHead;
    };

    /*********************************************************************************************************
    ** 连续轨迹：Continuous path
    *********************************************************************************************************/
    /*
     * CP参数
     */
    public struct CPParams
    {
        public float planAcc;
        public float juncitionVel;
        public float acc;
        public byte realTimeTrack;
    };

    public enum ContinuousPathMode {
        CPRelativeMode,
        CPAbsoluteMode
    };
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    public struct CPCmd
    {
        public byte cpMode;
        public float x;
        public float y;
        public float z;
        public float velocity;
    };

    /*********************************************************************************************************
    ** User parameters
    *********************************************************************************************************/

    public struct WAITCmd
    {
        public UInt32 timeout;
    };

    public enum IOFunction
    {
        IOFunctionDummy,
        IOFunctionDO,
        IOFunctionPWM,
        IOFunctionDI,
        IOFunctionADC
    };

    public struct  IOMultiplexing{
        public byte address;
        public byte multiplex;
    };

    public struct IODO{
        public byte  address;
        public byte  level;
    };

    public struct IOPWM {
        public byte address;
        public float frequency;
        public float dutyCycle;
    };

    public struct IODI {
        public byte address;
        public byte level;
    };

    public struct IOADC
    {
        public byte address;
        public UInt16 value;
    };

    /*
     * ARC related
     */
    public struct ARCParams
    {
        public float xyzVelocity;
        public float rVelocity;
        public float xyzAcceleration;
        public float rAcceleration;
    };

    public struct ARCCmd {
        public float cirPoint_x;
        public float cirPoint_y;
        public float cirPoint_z;
        public float cirPoint_r;

        public float toPoint_x;
        public float toPoint_y;
        public float toPoint_z;
        public float toPoint_r;
    };

    /*********************************************************************************************************
    ** User parameters
    *********************************************************************************************************/
    public struct UserParams {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public float[] param;
    };

    /*********************************************************************************************************
    ** API result
    *********************************************************************************************************/
    public enum DobotConnect{
        DobotConnect_NoError,
        DobotConnect_NotFound,
        DobotConnect_Occupied
    };

    public enum DobotCommunicate{
        DobotCommunicate_NoError,
        DobotCommunicate_BufferFull,
        DobotCommunicate_Timeout,
        DobotCommunicate_InvalidParams
    };
}
