Imports System.Runtime.InteropServices
Imports DobotDemoForVB.DobotDemoForVB
Imports System.Text

Public Class Form1

    Dim isDobotConnected As Boolean = False

    Private Sub connectBtn_Click(sender As Object, e As EventArgs) Handles connectBtn.Click
        If isDobotConnected = False Then
            Dim result As Integer

            result = DobotDll.ConnectDobot("", 115200)
            If result <> 0 Then
                MsgBox("Could not find Dobot or Dobot is occupied!")
                Return
            End If
            connectBtn.Text = "Disconnect"
            ptp1Btn.Enabled = True
            ptp2Btn.Enabled = True
            isDobotConnected = True
            Timer1.Enabled = True

            DobotDll.SetCmdTimeout(3000)
            DobotDll.SetQueuedCmdClear()
            DobotDll.SetQueuedCmdStartExec()

            Dim deviceName As New StringBuilder()
            deviceName.Capacity = 64
            DobotDll.GetDeviceName(deviceName, 64)
            DobotDll.GetDeviceName(deviceName, 64)
        Else
            connectBtn.Text = "Connect"
            ptp1Btn.Enabled = False
            ptp2Btn.Enabled = False
            isDobotConnected = False
            Timer1.Enabled = False

            DobotDll.DisconnectDobot()
        End If
    End Sub

    Private Sub GotoPoint(ptpMode As Byte, x As Single, y As Single, z As Single, r As Single)
        Dim ptpCmd As PTPCmd
        ptpCmd.ptpMode = ptpMode
        ptpCmd.x = x
        ptpCmd.y = y
        ptpCmd.z = z
        ptpCmd.r = r

        Dim result As Int32
        Dim queuedCmdIndex As UInt64
        Dim currentQueuedCmdIndex As UInt64
        While True
            result = DobotDll.SetPTPCmd(ptpCmd, True, queuedCmdIndex)
            If result = DobotCommunicate.DobotCommunicate_NoError Then
                Exit While
            End If
        End While
        While True
            result = DobotDll.GetQueuedCmdCurrentIndex(currentQueuedCmdIndex)
            If result = DobotCommunicate.DobotCommunicate_NoError Then
                If currentQueuedCmdIndex >= queuedCmdIndex Then
                    Exit While
                End If
            End If
        End While
    End Sub

    Private Sub ptp1Btn_Click(sender As Object, e As EventArgs) Handles ptp1Btn.Click
        ptp1Btn.Enabled = False
        ptp2Btn.Enabled = False
        GotoPoint(2, 200, 0, 0, 0)
        ptp1Btn.Enabled = True
        ptp2Btn.Enabled = True
    End Sub

    Private Sub ptpBtn2_Click(sender As Object, e As EventArgs) Handles ptp2Btn.Click
        ptp1Btn.Enabled = False
        ptp2Btn.Enabled = False
        GotoPoint(2, 250, 0, 0, 0)
        ptp1Btn.Enabled = True
        ptp2Btn.Enabled = True
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        Dim result As Int32
        Dim pose As Pose

        result = DobotDll.GetPose(pose)
        If result <> DobotCommunicate.DobotCommunicate_NoError Then
            Return
        End If
        Debug.Print(pose.x)
        Debug.Print(pose.y)
        Debug.Print(pose.z)
        Debug.Print(pose.r)
        Debug.Print(pose.joint1Angle)
        Debug.Print(pose.joint2Angle)
        Debug.Print(pose.joint3Angle)
        Debug.Print(pose.joint4Angle)
    End Sub
End Class
