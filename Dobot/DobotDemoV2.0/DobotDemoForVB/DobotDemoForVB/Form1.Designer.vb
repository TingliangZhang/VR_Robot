<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.connectBtn = New System.Windows.Forms.Button()
        Me.ptp1Btn = New System.Windows.Forms.Button()
        Me.ptp2Btn = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'Timer1
        '
        Me.Timer1.Interval = 250
        '
        'connectBtn
        '
        Me.connectBtn.Location = New System.Drawing.Point(65, 38)
        Me.connectBtn.Name = "connectBtn"
        Me.connectBtn.Size = New System.Drawing.Size(75, 23)
        Me.connectBtn.TabIndex = 0
        Me.connectBtn.Text = "Connect"
        Me.connectBtn.UseVisualStyleBackColor = True
        '
        'ptp1Btn
        '
        Me.ptp1Btn.Enabled = False
        Me.ptp1Btn.Location = New System.Drawing.Point(65, 82)
        Me.ptp1Btn.Name = "ptp1Btn"
        Me.ptp1Btn.Size = New System.Drawing.Size(75, 23)
        Me.ptp1Btn.TabIndex = 1
        Me.ptp1Btn.Text = "PTP1"
        Me.ptp1Btn.UseVisualStyleBackColor = True
        '
        'ptp2Btn
        '
        Me.ptp2Btn.Enabled = False
        Me.ptp2Btn.Location = New System.Drawing.Point(65, 135)
        Me.ptp2Btn.Name = "ptp2Btn"
        Me.ptp2Btn.Size = New System.Drawing.Size(75, 23)
        Me.ptp2Btn.TabIndex = 2
        Me.ptp2Btn.Text = "PTP2"
        Me.ptp2Btn.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(206, 226)
        Me.Controls.Add(Me.ptp2Btn)
        Me.Controls.Add(Me.ptp1Btn)
        Me.Controls.Add(Me.connectBtn)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents connectBtn As System.Windows.Forms.Button
    Friend WithEvents ptp1Btn As System.Windows.Forms.Button
    Friend WithEvents ptp2Btn As System.Windows.Forms.Button

End Class
