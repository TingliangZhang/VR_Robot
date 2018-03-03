Imports System
Imports System.Collections.Generic
Imports System.Linq
Imports System.Runtime.InteropServices
Imports System.Text

Namespace DobotDemoForVB
    Class DobotDll

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function ConnectDobot(ByVal portName As String, ByVal baudrate As Int32) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function DisconnectDobot() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SearchDobot(ByVal dobotList As StringBuilder, ByVal maxLen As UInt32) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function DobotExec() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetCmdTimeout(ByVal cmdTimeout As UInt32) As Int32
        End Function

        ' Queued command control!
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetQueuedCmdStartExec() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetQueuedCmdStopExec() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetQueuedCmdForceStopExec() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetQueuedCmdStartDownload(ByVal totalLoop As UInt32, ByVal linePerLoop As UInt32) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetQueuedCmdStopDownload() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetQueuedCmdClear() As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetQueuedCmdCurrentIndex(ByRef cmdIndex As UInt64) As Int32
        End Function

        ' SN information
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetDeviceSN(ByVal deviceSN As StringBuilder, ByVal maxLen As UInt32) As Int32
        End Function

        ' Device information
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetDeviceName(ByVal deviceName As String) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetDeviceName(ByVal deviceName As StringBuilder, ByVal maxLen As UInt32) As Int32
        End Function

        ' public static extern functions
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetEndEffectorParams(ByRef endEffectorParams As EndEffectorParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetEndEffectorParams(ByRef endEffectorParams As EndEffectorParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetEndEffectorLaser(ByVal enableCtrl As Boolean, ByVal isOn As Boolean, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetEndEffectorLaser(ByRef isCtrlEnabled As Boolean, ByRef isOn As Boolean) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetEndEffectorSuctionCup(ByVal enableCtrl As Boolean, ByVal suck As Boolean, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetEndEffectorSuctionCup(ByRef isCtrlEnabled As Boolean, ByRef isSucked As Boolean) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetEndEffectorGripper(ByVal enableCtrl As Boolean, ByVal grip As Boolean, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetEndEffectorGripper(ByRef isCtrlEnabled As Boolean, ByRef isGripped As Boolean) As Int32
        End Function

        ' InitialPose
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function ResetPose(ByVal manual As Boolean, ByVal rearArmAngle As Single, ByVal frontArmAngle As Single) As Int32
        End Function

        ' Pose and Kinematics parameters are automatically get
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetPose(ByRef pose As Pose) As Int32
        End Function

        ' HOME
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetHOMEParams(ByRef homeParams As HOMEParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetHOMEParams(ByRef homeParams As HOMEParams) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetHOMECmd(ByRef homeCmd As HOMECmd, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function

        ' Jog functions
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetJOGJointParams(ByRef jointJogParams As JOGJointParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetJOGJointParams(ByRef jointJogParams As JOGJointParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetJOGCoordinateParams(ByRef coordinateJogParams As JOGCoordinateParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetJOGCoordinateParams(ByRef coordinateJogParams As JOGCoordinateParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetJOGCommonParams(ByRef jogCommonParams As JOGCommonParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetJOGCommonParams(ByRef jogCommonParams As JOGCommonParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetJOGCmd(ByRef jogCmd As JogCmd, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function

        ' PTP functions
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetPTPJointParams(ByRef ptpJointParams As PTPJointParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetPTPJointParams(ByRef ptpJointParams As PTPJointParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetPTPCoordinateParams(ByRef ptpCoordinateParams As PTPCoordinateParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetPTPCoordinateParams(ByRef ptpCoordinateParams As PTPCoordinateParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetPTPJumpParams(ByRef ptpJumpParams As PTPJumpParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetPTPJumpParams(ByRef ptpJumpParams As PTPJumpParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetPTPCommonParams(ByRef ptpCommonParams As PTPCommonParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetPTPCommonParams(ByRef ptpCommonParams As PTPCommonParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetPTPCmd(ByRef ptpCmd As PTPCmd, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function

        ' CP functions
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetCPParams(ByRef cpParams As CPParams, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GetCPParams(ByRef cpParams As CPParams) As Int32
        End Function

        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetCPCmd(ByRef cpCmd As CPCmd, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function

        ' WAIT
        <DllImport("DobotDll.dll", CallingConvention:=CallingConvention.Cdecl)> Public Shared Function SetWAITCmd(ByRef waitCmd As WAITCmd, ByVal isQueued As Boolean, ByRef queuedCmdIndex As UInt64) As Int32
        End Function
    End Class
End Namespace
