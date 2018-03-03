// DobotDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DobotDemo.h"
#include "DobotDemoDlg.h"
#include <conio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ENABLE_CONSOLE_PRINT    1

float laserHeight;
// CDobotDemoDlg dialog

// Dobot specified library and header

#pragma comment(lib, "./DobotDll/DobotDll.lib")

#include "./DobotDll/DobotDll.h"


CDobotDemoDlg::CDobotDemoDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CDobotDemoDlg::IDD, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    // Private member
    m_bConnectStatus = false;
}

void CDobotDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_BUTTON_CONNECT, m_ConnectButton);
    DDX_Control(pDX, IDC_COMBO_JOGMODE, m_JOGMode);
    DDX_Control(pDX, IDC_BUTTON_J1P, m_ButtonJ1P);
    DDX_Control(pDX, IDC_BUTTON_J1N, m_ButtonJ1N);
    DDX_Control(pDX, IDC_BUTTON_J2P, m_ButtonJ2P);
    DDX_Control(pDX, IDC_BUTTON_J2N, m_ButtonJ2N);
    DDX_Control(pDX, IDC_BUTTON_J3P, m_ButtonJ3P);
    DDX_Control(pDX, IDC_BUTTON_J3N, m_ButtonJ3N);
    DDX_Control(pDX, IDC_BUTTON_J4P, m_ButtonJ4P);
    DDX_Control(pDX, IDC_BUTTON_J4N, m_ButtonJ4N);
    DDX_Control(pDX, IDC_STATIC_J1, m_StaticJ1);
    DDX_Control(pDX, IDC_STATIC_J2, m_StaticJ2);
    DDX_Control(pDX, IDC_STATIC_J3, m_StaticJ3);
    DDX_Control(pDX, IDC_STATIC_J4, m_StaticJ4);
    DDX_Control(pDX, IDC_STATIC_X, m_StaticX);
    DDX_Control(pDX, IDC_STATIC_Y, m_StaticY);
    DDX_Control(pDX, IDC_STATIC_Z, m_StaticZ);
    DDX_Control(pDX, IDC_STATIC_R, m_StaticR);
    DDX_Control(pDX, IDC_EDIT_X, m_EditX);
    DDX_Control(pDX, IDC_EDIT_Y, m_EditY);
    DDX_Control(pDX, IDC_EDIT_Z, m_EditZ);
    DDX_Control(pDX, IDC_EDIT_R, m_EditR);
    DDX_Control(pDX, IDC_BUTTON_SENDPTP, m_ButtonSendPTP);
}

BEGIN_MESSAGE_MAP(CDobotDemoDlg, CDialog)
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    //}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CDobotDemoDlg::OnBnClickedButtonConnect)
    ON_WM_TIMER()
    ON_CBN_SELCHANGE(IDC_COMBO_JOGMODE, &CDobotDemoDlg::OnCbnSelchangeComboJOGMode)
    ON_BN_CLICKED(IDC_BUTTON_SENDPTP, &CDobotDemoDlg::OnBnClickedButtonSendPTP)
END_MESSAGE_MAP()


// CDobotDemoDlg message handlers

BOOL CDobotDemoDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);            // Set big icon
    SetIcon(m_hIcon, FALSE);        // Set small icon

    // TODO: Add extra initialization here
#if ENABLE_CONSOLE_PRINT
    AllocConsole();
#endif
    InitControls();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDobotDemoDlg::InitControls(void)
{
    m_JOGMode.InsertString(0, L"Joint");
    m_JOGMode.InsertString(1, L"Coordinate");
    m_JOGMode.SetCurSel(0);
    OnCbnSelchangeComboJOGMode();

    RefreshButtons();
}

void CDobotDemoDlg::OnCbnSelchangeComboJOGMode()
{
    // TODO: Add your control notification handler code here
    int currentSelect = m_JOGMode.GetCurSel();

    if (currentSelect == 0) {
        m_ButtonJ1P.SetWindowText(L"J1+");
        m_ButtonJ1N.SetWindowText(L"J1-");
        m_ButtonJ2P.SetWindowText(L"J2+");
        m_ButtonJ2N.SetWindowText(L"J2-");
        m_ButtonJ3P.SetWindowText(L"J3+");
        m_ButtonJ3N.SetWindowText(L"J3-");
        m_ButtonJ4P.SetWindowText(L"J4+");
        m_ButtonJ4N.SetWindowText(L"J4-");
    } else {
        m_ButtonJ1P.SetWindowText(L"X+");
        m_ButtonJ1N.SetWindowText(L"X-");
        m_ButtonJ2P.SetWindowText(L"Y+");
        m_ButtonJ2N.SetWindowText(L"Y-");
        m_ButtonJ3P.SetWindowText(L"Z+");
        m_ButtonJ3N.SetWindowText(L"Z-");
        m_ButtonJ4P.SetWindowText(L"R+");
        m_ButtonJ4N.SetWindowText(L"R-");
    }
}

void CDobotDemoDlg::RefreshButtons(void)
{
    if (m_bConnectStatus) {
        m_ConnectButton.SetWindowText(L"Disconnect");
    } else {
        m_ConnectButton.SetWindowText(L"Connect");
    }
    m_ButtonJ1P.EnableWindow(m_bConnectStatus);
    m_ButtonJ1N.EnableWindow(m_bConnectStatus);
    m_ButtonJ2P.EnableWindow(m_bConnectStatus);
    m_ButtonJ2N.EnableWindow(m_bConnectStatus);
    m_ButtonJ3P.EnableWindow(m_bConnectStatus);
    m_ButtonJ3N.EnableWindow(m_bConnectStatus);
    m_ButtonJ4P.EnableWindow(m_bConnectStatus);
    m_ButtonJ4N.EnableWindow(m_bConnectStatus);
    m_JOGMode.EnableWindow(m_bConnectStatus);

    m_EditX.EnableWindow(m_bConnectStatus);
    m_EditY.EnableWindow(m_bConnectStatus);
    m_EditZ.EnableWindow(m_bConnectStatus);
    m_EditR.EnableWindow(m_bConnectStatus);

    m_ButtonSendPTP.EnableWindow(m_bConnectStatus);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDobotDemoDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDobotDemoDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}

void CDobotDemoDlg::OnBnClickedButtonConnect()
{
    // TODO: Add your control notification handler code here
    if (!m_bConnectStatus) {
        if (ConnectDobot(0, 115200,0,0) != DobotConnect_NoError) {
            ::AfxMessageBox(L"Cannot connect Dobot!");
            return;
        }
        m_bConnectStatus = true;
        RefreshButtons();
        SetTimer(1, 250, NULL);
        InitDobot();
    } else {
        m_bConnectStatus = false;
        RefreshButtons();
        KillTimer(1);
        DisconnectDobot();
    }
}

void CDobotDemoDlg::InitDobot(void)
{
    // Command timeout
    SetCmdTimeout(3000);
    // Clear old commands and set the queued command running
    SetQueuedCmdClear();
    SetQueuedCmdStartExec();

    // Device SN
    char deviceSN[64];
    GetDeviceSN(deviceSN, sizeof(deviceSN));
    _cprintf("Device SN:%s\r\n", deviceSN);

    // Device Name
    char deviceName[64];
    GetDeviceName(deviceName, sizeof(deviceName));
    _cprintf("Device Name:%s\r\n", deviceName);

    // Device version information
    uint8_t majorVersion, minorVersion, revision;
    GetDeviceVersion(&majorVersion, &minorVersion, &revision);
    _cprintf("Device information:V%d.%d.%d\r\n", majorVersion, minorVersion, revision);

    // Set the end effector parameters
    EndEffectorParams endEffectorParams;
    memset(&endEffectorParams, 0, sizeof(EndEffectorParams));
    endEffectorParams.xBias = 71.6f;
    SetEndEffectorParams(&endEffectorParams, false, NULL);

    // 1. Set the JOG parameters
    JOGJointParams jogJointParams;
    for (uint32_t i = 0; i < 4; i++) {
        jogJointParams.velocity[i] = 200;
        jogJointParams.acceleration[i] = 200;
    }
    SetJOGJointParams(&jogJointParams, false, NULL);

    JOGCoordinateParams jogCoordinateParams;
    for (uint32_t i = 0; i < 4; i++) {
        jogCoordinateParams.velocity[i] = 200;
        jogCoordinateParams.acceleration[i] = 200;
    }
    SetJOGCoordinateParams(&jogCoordinateParams, false, NULL);

    JOGCommonParams jogCommonParams;
    jogCommonParams.velocityRatio = 50;
    jogCommonParams.accelerationRatio = 50;
    SetJOGCommonParams(&jogCommonParams, false, NULL);

    // 2. Set the PTP parameters
    PTPJointParams ptpJointParams;
    for (uint32_t i = 0; i < 4; i++) {
        ptpJointParams.velocity[i] = 200;
        ptpJointParams.acceleration[i] = 200;
    }
    SetPTPJointParams(&ptpJointParams, false, NULL);

    PTPCoordinateParams ptpCoordinateParams;
    ptpCoordinateParams.xyzVelocity = 200;
    ptpCoordinateParams.xyzAcceleration = 200;
    ptpCoordinateParams.rVelocity = 200;
    ptpCoordinateParams.rAcceleration = 200;
    SetPTPCoordinateParams(&ptpCoordinateParams, false, NULL);

    PTPJumpParams ptpJumpParams;
    ptpJumpParams.jumpHeight = 10;
    ptpJumpParams.zLimit = 150;
    SetPTPJumpParams(&ptpJumpParams, false, NULL);
}

BOOL CDobotDemoDlg::PreTranslateMessage(MSG *pMsg)
{
    HWND hWnd[] = {
        m_ButtonJ1P.m_hWnd, m_ButtonJ1N.m_hWnd,
        m_ButtonJ2P.m_hWnd, m_ButtonJ2N.m_hWnd,
        m_ButtonJ3P.m_hWnd, m_ButtonJ3N.m_hWnd,
        m_ButtonJ4P.m_hWnd, m_ButtonJ4N.m_hWnd
    };

    if (pMsg->message == WM_LBUTTONDOWN) {
        for (int i = 0; i < sizeof(hWnd) / sizeof(hWnd[0]); i++) {
            if (pMsg->hwnd == hWnd[i]) {
                JOGCmd jogCmd;
                jogCmd.isJoint = m_JOGMode.GetCurSel() == 0;
                jogCmd.cmd = i + 1;
                SetJOGCmd(&jogCmd, false, NULL);
                break;
            }
        }
    } else if (pMsg->message == WM_LBUTTONUP) {
        for (int i = 0; i < sizeof(hWnd) / sizeof(hWnd[0]); i++) {
            if (pMsg->hwnd == hWnd[i]) {
                JOGCmd jogCmd;
                jogCmd.isJoint = m_JOGMode.GetCurSel() == 0;
                jogCmd.cmd = 0;
                SetJOGCmd(&jogCmd, false, NULL);
                break;
            }
        }
    }
    return CDialog::PreTranslateMessage(pMsg);
}

void CDobotDemoDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: Add your message handler code here and/or call default
    switch (nIDEvent) {
        case 1:
            do {
                Pose pose;
                if (GetPose(&pose) != DobotCommunicate_NoError) {
                    break;
                }
                CString str;
                str.Format(L"%1.3f", pose.jointAngle[0]);
                m_StaticJ1.SetWindowText(str);
                str.Format(L"%1.3f", pose.jointAngle[1]);
                m_StaticJ2.SetWindowText(str);
                str.Format(L"%1.3f", pose.jointAngle[2]);
                m_StaticJ3.SetWindowText(str);
                str.Format(L"%1.3f", pose.jointAngle[3]);
                m_StaticJ4.SetWindowText(str);

                str.Format(L"%1.3f", pose.x);
                m_StaticX.SetWindowText(str);
                str.Format(L"%1.3f", pose.y);
                m_StaticY.SetWindowText(str);
                str.Format(L"%1.3f", pose.z);
                m_StaticZ.SetWindowText(str);
                str.Format(L"%1.3f", pose.r);
                m_StaticR.SetWindowText(str);
            } while (0);
        break;

        default:

        break;
    }
    CDialog::OnTimer(nIDEvent);
}

void CDobotDemoDlg::GotoPoint(UINT mode, float x, float y, float z, float r, bool waitEnd)
{
    PTPCmd ptpCmd;

    ptpCmd.ptpMode = mode;
    ptpCmd.x = x;
    ptpCmd.y = y;
    ptpCmd.z = z;
    ptpCmd.r = r;

    // Send the command. If failed, just resend the command
    uint64_t queuedCmdIndex;
    do {
        int result = SetPTPCmd(&ptpCmd, true, &queuedCmdIndex);
        if (result == DobotCommunicate_NoError) {
            break;
        }
    } while (1);

    // Check whether the command is finished
    do {
        if (waitEnd == false) {
            break;
        }
        uint64_t currentIndex;
        int result = GetQueuedCmdCurrentIndex(&currentIndex);
        if (result == DobotCommunicate_NoError &&
            currentIndex >= queuedCmdIndex) {
                break;
        }
    } while (1);
}

void CDobotDemoDlg::LaserCtrl(bool isOn, bool waitEnd)
{
    // Send the command. If failed, just resend the command
    uint64_t queuedCmdIndex;
    do {
        int result = SetEndEffectorLaser(true, isOn, true, &queuedCmdIndex);
        if (result == DobotCommunicate_NoError) {
            break;
        }
    } while (1);

    // Check whether the command is finished
    do {
        if (waitEnd == false) {
            break;
        }
        uint64_t currentIndex;
        int result = GetQueuedCmdCurrentIndex(&currentIndex);
        if (result == DobotCommunicate_NoError &&
            currentIndex >= queuedCmdIndex) {
                break;
        }
    } while (1);
}

void CDobotDemoDlg::SuctionCupCtrl(bool suck, bool waitEnd)
{
    // Send the command. If failed, just resend the command
    uint64_t queuedCmdIndex;
    do {
        int result = SetEndEffectorSuctionCup(true, suck, true, &queuedCmdIndex);
        if (result == DobotCommunicate_NoError) {
            break;
        }
    } while (1);

    // Check whether the command is finished
    do {
        if (waitEnd == false) {
            break;
        }
        uint64_t currentIndex;
        int result = GetQueuedCmdCurrentIndex(&currentIndex);
        if (result == DobotCommunicate_NoError &&
            currentIndex >= queuedCmdIndex) {
                break;
        }
    } while (1);
}

void CDobotDemoDlg::WaitForSeconds(float seconds, bool waitEnd)
{
    // Send the command. If failed, just resend the command
    uint64_t queuedCmdIndex;
    do {
        WAITCmd waitCmd;
        waitCmd.timeout = (uint32_t)(seconds * 1000);
        int result = SetWAITCmd(&waitCmd, true, &queuedCmdIndex);
        if (result == DobotCommunicate_NoError) {
            break;
        }
    } while (1);

    // Check whether the command is finished
    do {
        if (waitEnd == false) {
            break;
        }
        uint64_t currentIndex;
        int result = GetQueuedCmdCurrentIndex(&currentIndex);
        if (result == DobotCommunicate_NoError &&
            currentIndex >= queuedCmdIndex) {
                break;
        }
    } while (1);
}

void CDobotDemoDlg::Home(void)
{
    // Send the command. If failed, just resend the command
    uint64_t queuedCmdIndex;
    do {
        HOMECmd homeCmd;
        int result = SetHOMECmd(&homeCmd, true, &queuedCmdIndex);
        if (result == DobotCommunicate_NoError) {
            break;
        }
    } while (1);

    // Check whether the command is finished
    do {
        bool waitEnd = true;
        if (waitEnd == false) {
            break;
        }
        uint64_t currentIndex;
        int result = GetQueuedCmdCurrentIndex(&currentIndex);
        if (result == DobotCommunicate_NoError &&
            currentIndex >= queuedCmdIndex) {
                break;
        }
    } while (1);
}

void CDobotDemoDlg::OnBnClickedButtonSendPTP()
{
    // TODO: Add your control notification handler code here
    wchar_t buffer[32];

    m_EditX.GetWindowText((LPTSTR)buffer, sizeof(buffer));
    float x = (float)_wtof(buffer);
    m_EditY.GetWindowText((LPTSTR)buffer, sizeof(buffer));
    float y = (float)_wtof(buffer);
    m_EditZ.GetWindowText((LPTSTR)buffer, sizeof(buffer));
    float z = (float)_wtof(buffer);
    m_EditR.GetWindowText((LPTSTR)buffer, sizeof(buffer));
    float r = (float)_wtof(buffer);

    /*
     * In this demo, we just input the values and send the PTP command
     * In the real condition, there are two kinds of controlling of queued command
     * The first one, send the queued commands, and wait for command to be finished for every command
     * The second one, send the queued commands, and just wait for the last command to be finished!
     * The second one is much more effiency
     */

    // Just an example
    GotoPoint(PTPJUMPXYZMode, x, y, z, r, true);
}
