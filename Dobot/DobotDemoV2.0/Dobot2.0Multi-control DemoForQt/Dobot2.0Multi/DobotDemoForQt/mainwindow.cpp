#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connectStatus = false;
    //endtype change
    connect(ui->teachMode, SIGNAL(currentIndexChanged(int)), this, SLOT(onChangedMode()));

    //connect dobot
    connect(ui->connectBtn, SIGNAL(clicked(bool)), this, SLOT(onConnectDobot()));

    //send PTP data
    connect(ui->sendBtn, SIGNAL(clicked(bool)), this, SLOT(onPTPsendBtnClicked()));

    //init JOG control
    initControl();

    //getPose Timer
    QTimer *getPoseTimer = new QTimer(this);
    getPoseTimer->setObjectName("getPoseTimer");
    connect(getPoseTimer, SIGNAL(timeout()), this, SLOT(onGetPoseTimer()));
    getPoseTimer->setSingleShot(true);

    //not more than 1000
    QRegExp regExp("500|0|[-]|[1-9][0-9]{0,2}[.][0-9]{1,3}");
    QValidator *validator = new QRegExpValidator(regExp, this);
    ui->xPTPEdit->setValidator(validator);
    ui->yPTPEdit->setValidator(validator);
    ui->zPTPEdit->setValidator(validator);
    ui->rPTPEdit->setValidator(validator);

    {
 qDebug() <<"one";
        char comnumber[64];//原始字符数组
        int spacenum;//空格位置
        QString space=" ";//空格字符
        SearchDobot(comnumber,sizeof(comnumber));//返回原始字符数组
        QString comqstring=QString("%1").arg(comnumber);
        spacenum=comqstring.indexOf(space);//得到空格位置1
        QString comqstring1=comqstring.mid(0,spacenum);//得到第一个com口
 qDebug() <<comqstring1;
        ui->combox1->addItem(comqstring1);//添加到第一个下来列表
 qDebug() <<"3";
        spacenum+=comqstring.mid(spacenum).indexOf(space)+1;//得到空格位置2
        QString comqstring2=comqstring.mid(spacenum,5);
        if(comqstring1!=comqstring2)
        ui->combox1->addItem(comqstring2);
        spacenum+=comqstring.mid(spacenum).indexOf(space)+1;//得到空格位置2
        QString comqstring3=comqstring.mid(spacenum,5);
        if(comqstring2!=comqstring3)
        ui->combox1->addItem(comqstring3);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGetPoseTimer()
{
    QTimer *getPoseTimer = findChild<QTimer *>("getPoseTimer");
    Pose pose;

    while (GetPose(dobotId, &pose) != DobotCommunicate_NoError) {
    }
    ui->joint1Label->setText(QString::number(pose.jointAngle[0]));
    ui->joint2Label->setText(QString::number(pose.jointAngle[1]));
    ui->joint3Label->setText(QString::number(pose.jointAngle[2]));
    ui->joint4Label->setText(QString::number(pose.jointAngle[3]));

    ui->xLabel->setText(QString::number(pose.x));
    ui->yLabel->setText(QString::number(pose.y));
    ui->zLabel->setText(QString::number(pose.z));
    ui->rLabel->setText(QString::number(pose.r));

    getPoseTimer->start();
}

void MainWindow::onChangedMode()
{
    if (ui->teachMode->currentIndex() == 1) {
        ui->baseAngleAddBtn->setText(tr("X+"));
        ui->baseAngleSubBtn->setText(tr("X-"));
        ui->longArmAddBtn->setText(tr("Y+"));
        ui->longArmSubBtn->setText(tr("Y-"));
        ui->shortArmAddBtn->setText(tr("Z+"));
        ui->shortArmSubBtn->setText(tr("Z-"));
        ui->rHeadAddBtn->setText(tr("R+"));
        ui->rHeadSubBtn->setText(tr("R-"));
    } else {
        ui->baseAngleAddBtn->setText(tr("J1+"));
        ui->baseAngleSubBtn->setText(tr("J1-"));
        ui->longArmAddBtn->setText(tr("J2+"));
        ui->longArmSubBtn->setText(tr("J2-"));
        ui->shortArmAddBtn->setText(tr("J3+"));
        ui->shortArmSubBtn->setText(tr("J3-"));
        ui->rHeadAddBtn->setText(tr("J4+"));
        ui->rHeadSubBtn->setText(tr("J4-"));
    }
}

void MainWindow::onConnectDobot()
{
    char fwType[20];
    char version[20];
    //connect dobot
    if (!connectStatus) {
        if (ConnectDobot( ui->combox1->currentText().toLatin1().data(), 115200, fwType, version, &dobotId) != DobotConnect_NoError) {
            QMessageBox::information(this, tr("error"), tr("Connect dobot error!!!"), QMessageBox::Ok);
            return;
        }
        qDebug() << "dobotId" << dobotId;
        connectStatus = true;
        refreshBtn();
        initDobot();

        QTimer *getPoseTimer = findChild<QTimer *>("getPoseTimer");
        getPoseTimer->start(200);
        qDebug() << "connect success!!!";
    } else {
        QTimer *getPoseTimer = findChild<QTimer *>("getPoseTimer");
        getPoseTimer->stop();
        connectStatus = false;
        refreshBtn();
        DisconnectDobot(dobotId);
    }
}

void MainWindow::refreshBtn()
{
    if (connectStatus) {
        ui->connectBtn->setText(tr("Disconnect"));

        ui->teachMode->setEnabled(true);
        ui->baseAngleAddBtn->setEnabled(true);
        ui->baseAngleSubBtn->setEnabled(true);
        ui->longArmAddBtn->setEnabled(true);
        ui->longArmSubBtn->setEnabled(true);
        ui->shortArmAddBtn->setEnabled(true);
        ui->shortArmSubBtn->setEnabled(true);
        ui->rHeadAddBtn->setEnabled(true);
        ui->rHeadSubBtn->setEnabled(true);

        ui->sendBtn->setEnabled(true);
        ui->xPTPEdit->setEnabled(true);
        ui->yPTPEdit->setEnabled(true);
        ui->zPTPEdit->setEnabled(true);
        ui->rPTPEdit->setEnabled(true);
    } else {
        ui->connectBtn->setText(tr("Connect"));

        ui->teachMode->setEnabled(false);
        ui->baseAngleAddBtn->setEnabled(false);
        ui->baseAngleSubBtn->setEnabled(false);
        ui->longArmAddBtn->setEnabled(false);
        ui->longArmSubBtn->setEnabled(false);
        ui->shortArmAddBtn->setEnabled(false);
        ui->shortArmSubBtn->setEnabled(false);
        ui->rHeadAddBtn->setEnabled(false);
        ui->rHeadSubBtn->setEnabled(false);

        ui->sendBtn->setEnabled(false);
        ui->xPTPEdit->setEnabled(false);
        ui->yPTPEdit->setEnabled(false);
        ui->zPTPEdit->setEnabled(false);
        ui->rPTPEdit->setEnabled(false);
    }
}

void MainWindow::initDobot()
{
    //Command timeout
    SetCmdTimeout(dobotId, 3000);
    //clear old commands and set the queued command running
    SetQueuedCmdClear(dobotId);
    SetQueuedCmdStartExec(dobotId);

    char deviceSN[64];
    GetDeviceSN(dobotId, deviceSN, sizeof(deviceSN));
    ui->deviceSNLabel->setText(deviceSN);

    char deviceName[64];
    GetDeviceName(dobotId, deviceName, sizeof(deviceName));
    ui->DeviceNameLabel->setText(deviceName);

    uint8_t majorVersion, minorVersion, revision;
    GetDeviceVersion(dobotId, &majorVersion, &minorVersion, &revision);
    ui->DeviceInfoLabel->setText(QString::number(majorVersion) + "." + QString::number(minorVersion) + "." + QString::number(revision));

    //set the end effector parameters
    EndEffectorParams endEffectorParams;
    memset(&endEffectorParams, 0, sizeof(endEffectorParams));
    endEffectorParams.xBias = 71.6f;
    SetEndEffectorParams(dobotId, &endEffectorParams, false, NULL);

    JOGJointParams jogJointParams;
    for (int i = 0; i < 4; i++) {
        jogJointParams.velocity[i] = 100;
        jogJointParams.acceleration[i] = 100;
    }
    SetJOGJointParams(dobotId, &jogJointParams, false, NULL);

    JOGCoordinateParams jogCoordinateParams;
    for (int i = 0; i < 4; i++) {
        jogCoordinateParams.velocity[i] = 100;
        jogCoordinateParams.acceleration[i] = 100;
    }
    SetJOGCoordinateParams(dobotId, &jogCoordinateParams, false, NULL);

    JOGCommonParams jogCommonParams;
    jogCommonParams.velocityRatio = 50;
    jogCommonParams.accelerationRatio = 50;
    SetJOGCommonParams(dobotId, &jogCommonParams, false, NULL);

    PTPJointParams ptpJointParams;
    for (int i = 0; i < 4; i++) {
        ptpJointParams.velocity[i] = 100;
        ptpJointParams.acceleration[i] = 100;
    }
    SetPTPJointParams(dobotId, &ptpJointParams, false, NULL);

    PTPCoordinateParams ptpCoordinateParams;
    ptpCoordinateParams.xyzVelocity = 100;
    ptpCoordinateParams.xyzAcceleration = 100;
    ptpCoordinateParams.rVelocity = 100;
    ptpCoordinateParams.rAcceleration = 100;
    SetPTPCoordinateParams(dobotId, &ptpCoordinateParams, false, NULL);

    PTPJumpParams ptpJumpParams;
    ptpJumpParams.jumpHeight = 20;
    ptpJumpParams.zLimit = 150;
    SetPTPJumpParams(dobotId, &ptpJumpParams, false, NULL);
}

void MainWindow::initControl()
{
    QSignalMapper *signalMapper  = new QSignalMapper(this);

    connect(ui->baseAngleAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->baseAngleSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->longArmAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->longArmSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->shortArmAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->shortArmSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->rHeadAddBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));
    connect(ui->rHeadSubBtn, SIGNAL(pressed()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->baseAngleAddBtn, 0);
    signalMapper->setMapping(ui->baseAngleSubBtn, 1);
    signalMapper->setMapping(ui->longArmAddBtn, 2);
    signalMapper->setMapping(ui->longArmSubBtn, 3);
    signalMapper->setMapping(ui->shortArmAddBtn, 4);
    signalMapper->setMapping(ui->shortArmSubBtn, 5);
    signalMapper->setMapping(ui->rHeadAddBtn, 6);
    signalMapper->setMapping(ui->rHeadSubBtn, 7);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(onJOGCtrlBtnPressed(int)));

    connect(ui->baseAngleAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->baseAngleSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->longArmAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->longArmSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->shortArmAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->shortArmSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->rHeadAddBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
    connect(ui->rHeadSubBtn, SIGNAL(released()), this, SLOT(onJOGCtrlBtnReleased()));
}

void MainWindow::onJOGCtrlBtnPressed(int index)
{
    JOGCmd jogCmd;

    jogCmd.isJoint = ui->teachMode->currentIndex() == 0;
    jogCmd.cmd = index + 1;
    while (SetJOGCmd(dobotId, &jogCmd, false, NULL) != DobotCommunicate_NoError) {
    }
}

void MainWindow::onJOGCtrlBtnReleased()
{
    JOGCmd jogCmd;

    jogCmd.isJoint = ui->teachMode->currentIndex() == 0;
    jogCmd.cmd = JogIdle;
    while (SetJOGCmd(dobotId, &jogCmd, false, NULL) != DobotCommunicate_NoError) {
    }
}

void MainWindow::onPTPsendBtnClicked()
{
    ui->sendBtn->setEnabled(false);

    PTPCmd ptpCmd;
    ptpCmd.ptpMode = PTPMOVJXYZMode;
    ptpCmd.x = ui->xPTPEdit->text().toFloat();
    ptpCmd.y = ui->yPTPEdit->text().toFloat();
    ptpCmd.z = ui->zPTPEdit->text().toFloat();
    ptpCmd.r = ui->rPTPEdit->text().toFloat();

    while (SetPTPCmd(dobotId, &ptpCmd, true, NULL) != DobotCommunicate_NoError) {
    }
    ui->sendBtn->setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *)
{

}
