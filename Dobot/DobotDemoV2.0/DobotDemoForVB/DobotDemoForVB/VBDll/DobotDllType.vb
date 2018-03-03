Imports System
Imports System.Collections.Generic
Imports System.Linq
Imports System.Runtime.InteropServices
Imports System.Text

Namespace DobotDemoForVB
    Public Enum EndType
        EndTypeCustom
        EndTypeSuctionCap
        EndTypeGripper
        EndTypeLaser
        EndTypePen
        EndTypeMax
        EndTypeNum = EndTypeMax
    End Enum

    <StructLayout(Runtime.InteropServices.LayoutKind.Sequential, Pack:=1)> _
    Public Structure EndEffectorParams
        Dim xBias As Single
        Dim yBias As Single
        Dim zBias As Single
    End Structure

    Public Structure Pose
        Dim x As Single
        Dim y As Single
        Dim z As Single
        Dim r As Single
        Dim joint1Angle As Single
        Dim joint2Angle As Single
        Dim joint3Angle As Single
        Dim joint4Angle As Single
    End Structure

    Public Structure HOMEParams
        Dim x As Single
        Dim y As Single
        Dim z As Single
        Dim r As Single
    End Structure

    Public Structure HOMECmd
        Dim temp As UInt32
    End Structure

    Public Structure JOGJointParams
        Dim velocity1 As Single
        Dim velocity2 As Single
        Dim velocity3 As Single
        Dim velocity4 As Single

        Dim acceleration1 As Single
        Dim acceleration2 As Single
        Dim acceleration3 As Single
        Dim acceleration4 As Single
    End Structure

    Public Structure JOGCoordinateParams
        Dim velocity1 As Single
        Dim velocity2 As Single
        Dim velocity3 As Single
        Dim velocity4 As Single

        Dim acceleration1 As Single
        Dim acceleration2 As Single
        Dim acceleration3 As Single
        Dim acceleration4 As Single
    End Structure

    Public Structure JOGCommonParams
        Dim velocityRatio As Single
        Dim accelerationRatio As Single
    End Structure

    Public Enum JogCmdType
        JogIdle
        JogAPPressed
        JogANPressed
        JogBPPressed
        JogBNPressed
        JogCPPressed
        JogCNPressed
        JogDPPressed
        JogDNPressed
        JogEPPressed
        JogENPressed
    End Enum


    <StructLayout(Runtime.InteropServices.LayoutKind.Sequential, Pack:=1)> _
    Public Structure JogCmd
        Dim isJoint As Byte
        Dim cmd As Byte
    End Structure

    Public Structure PTPJointParams
        Dim velocity1 As Single
        Dim velocity2 As Single
        Dim velocity3 As Single
        Dim velocity4 As Single

        Dim acceleration1 As Single
        Dim acceleration2 As Single
        Dim acceleration3 As Single
        Dim acceleration4 As Single
    End Structure

    Public Structure PTPCoordinateParams
        Dim xyzVelocity As Single
        Dim rVelocity As Single
        Dim xyzAcceleration As Single
        Dim rAcceleration As Single
    End Structure

    Public Structure PTPJumpParams
        Dim jumpHeight As Single
        Dim zLimit As Single
    End Structure

    Public Structure PTPCommonParams
        Dim velocityRatio As Single
        Dim accelerationRatio As Single
    End Structure

    ' For play back
    Public Enum PTPMode
        PTPJUMPXYZMode
        PTPMOVJXYZMode
        PTPMOVLXYZMode

        PTPJUMPANGLEMode
        PTPMOVJANGLEMode
        PTPMOVLANGLEMode

        PTPMOVJXYZINCMode
        PTPMOVLXYZINCMode
    End Enum

    <StructLayout(Runtime.InteropServices.LayoutKind.Sequential, Pack:=1)> _
    Public Structure PTPCmd
        Dim ptpMode As Byte
        Dim x As Single
        Dim y As Single
        Dim z As Single
        Dim r As Single
    End Structure

    Public Structure CPParams
        Dim planAcc As Single
        Dim juncitionVel As Single
        Dim acc As Single
        Dim realTimeTrack As Byte
    End Structure

    Public Enum ContinuousPathMode
        CPRelativeMode
        CPAbsoluteMode
    End Enum

    <StructLayout(Runtime.InteropServices.LayoutKind.Sequential, Pack:=1)> _
    Public Structure CPCmd
        Dim cpMode As Byte
        Dim x As Single
        Dim y As Single
        Dim z As Single
        Dim velocity As Single
    End Structure

    Public Structure WAITCmd
        Dim timeout As UInt32
    End Structure

    Public Enum IOFunction
        IOFunctionDummy
        IOFunctionDO
        IOFunctionPWM
        IOFunctionDI
        IOFunctionADC
    End Enum

    ' API result
    Public Enum DobotConnect
        DobotConnect_NoError
        DobotConnect_NotFound
        DobotConnect_Occupied
    End Enum

    Public Enum DobotCommunicate
        DobotCommunicate_NoError
        DobotCommunicate_BufferFull
        DobotCommunicate_Timeout
    End Enum
End Namespace

