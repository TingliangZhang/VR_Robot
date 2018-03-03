/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *baseAngleAddBtn;
    QPushButton *baseAngleSubBtn;
    QPushButton *longArmAddBtn;
    QPushButton *longArmSubBtn;
    QPushButton *shortArmAddBtn;
    QPushButton *shortArmSubBtn;
    QPushButton *rHeadAddBtn;
    QPushButton *rHeadSubBtn;
    QComboBox *teachMode;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *joint1Label;
    QLabel *xLabel;
    QLabel *joint2Label;
    QLabel *yLabel;
    QLabel *joint3Label;
    QLabel *zLabel;
    QLabel *rLabel;
    QLabel *joint4Label;
    QGroupBox *groupBox_3;
    QLineEdit *xPTPEdit;
    QLineEdit *yPTPEdit;
    QLineEdit *zPTPEdit;
    QLineEdit *rPTPEdit;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *sendBtn;
    QPushButton *connectBtn;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *deviceSNLabel;
    QLabel *DeviceNameLabel;
    QLabel *DeviceInfoLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 746);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 471, 271));
        baseAngleAddBtn = new QPushButton(groupBox);
        baseAngleAddBtn->setObjectName(QStringLiteral("baseAngleAddBtn"));
        baseAngleAddBtn->setEnabled(false);
        baseAngleAddBtn->setGeometry(QRect(40, 40, 75, 23));
        baseAngleSubBtn = new QPushButton(groupBox);
        baseAngleSubBtn->setObjectName(QStringLiteral("baseAngleSubBtn"));
        baseAngleSubBtn->setEnabled(false);
        baseAngleSubBtn->setGeometry(QRect(160, 40, 75, 23));
        longArmAddBtn = new QPushButton(groupBox);
        longArmAddBtn->setObjectName(QStringLiteral("longArmAddBtn"));
        longArmAddBtn->setEnabled(false);
        longArmAddBtn->setGeometry(QRect(40, 80, 75, 23));
        longArmSubBtn = new QPushButton(groupBox);
        longArmSubBtn->setObjectName(QStringLiteral("longArmSubBtn"));
        longArmSubBtn->setEnabled(false);
        longArmSubBtn->setGeometry(QRect(160, 80, 75, 23));
        shortArmAddBtn = new QPushButton(groupBox);
        shortArmAddBtn->setObjectName(QStringLiteral("shortArmAddBtn"));
        shortArmAddBtn->setEnabled(false);
        shortArmAddBtn->setGeometry(QRect(40, 120, 75, 23));
        shortArmSubBtn = new QPushButton(groupBox);
        shortArmSubBtn->setObjectName(QStringLiteral("shortArmSubBtn"));
        shortArmSubBtn->setEnabled(false);
        shortArmSubBtn->setGeometry(QRect(160, 120, 75, 23));
        rHeadAddBtn = new QPushButton(groupBox);
        rHeadAddBtn->setObjectName(QStringLiteral("rHeadAddBtn"));
        rHeadAddBtn->setEnabled(false);
        rHeadAddBtn->setGeometry(QRect(40, 160, 75, 23));
        rHeadSubBtn = new QPushButton(groupBox);
        rHeadSubBtn->setObjectName(QStringLiteral("rHeadSubBtn"));
        rHeadSubBtn->setEnabled(false);
        rHeadSubBtn->setGeometry(QRect(160, 160, 75, 23));
        teachMode = new QComboBox(groupBox);
        teachMode->setObjectName(QStringLiteral("teachMode"));
        teachMode->setEnabled(false);
        teachMode->setGeometry(QRect(290, 30, 69, 22));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 300, 471, 101));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 21, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 16, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 20, 16, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 20, 16, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 20, 16, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 70, 16, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(210, 70, 16, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(330, 70, 16, 16));
        joint1Label = new QLabel(groupBox_2);
        joint1Label->setObjectName(QStringLiteral("joint1Label"));
        joint1Label->setEnabled(true);
        joint1Label->setGeometry(QRect(50, 20, 54, 12));
        xLabel = new QLabel(groupBox_2);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setEnabled(true);
        xLabel->setGeometry(QRect(50, 70, 54, 12));
        joint2Label = new QLabel(groupBox_2);
        joint2Label->setObjectName(QStringLiteral("joint2Label"));
        joint2Label->setGeometry(QRect(140, 20, 54, 12));
        yLabel = new QLabel(groupBox_2);
        yLabel->setObjectName(QStringLiteral("yLabel"));
        yLabel->setGeometry(QRect(140, 70, 54, 12));
        joint3Label = new QLabel(groupBox_2);
        joint3Label->setObjectName(QStringLiteral("joint3Label"));
        joint3Label->setGeometry(QRect(240, 20, 54, 12));
        zLabel = new QLabel(groupBox_2);
        zLabel->setObjectName(QStringLiteral("zLabel"));
        zLabel->setGeometry(QRect(240, 70, 54, 12));
        rLabel = new QLabel(groupBox_2);
        rLabel->setObjectName(QStringLiteral("rLabel"));
        rLabel->setGeometry(QRect(360, 70, 54, 12));
        joint4Label = new QLabel(groupBox_2);
        joint4Label->setObjectName(QStringLiteral("joint4Label"));
        joint4Label->setGeometry(QRect(360, 20, 54, 12));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 420, 471, 231));
        xPTPEdit = new QLineEdit(groupBox_3);
        xPTPEdit->setObjectName(QStringLiteral("xPTPEdit"));
        xPTPEdit->setEnabled(false);
        xPTPEdit->setGeometry(QRect(130, 40, 113, 20));
        yPTPEdit = new QLineEdit(groupBox_3);
        yPTPEdit->setObjectName(QStringLiteral("yPTPEdit"));
        yPTPEdit->setEnabled(false);
        yPTPEdit->setGeometry(QRect(130, 80, 113, 20));
        zPTPEdit = new QLineEdit(groupBox_3);
        zPTPEdit->setObjectName(QStringLiteral("zPTPEdit"));
        zPTPEdit->setEnabled(false);
        zPTPEdit->setGeometry(QRect(130, 120, 113, 20));
        rPTPEdit = new QLineEdit(groupBox_3);
        rPTPEdit->setObjectName(QStringLiteral("rPTPEdit"));
        rPTPEdit->setEnabled(false);
        rPTPEdit->setGeometry(QRect(130, 160, 113, 20));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(50, 40, 54, 12));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(50, 80, 54, 12));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(50, 120, 54, 12));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(50, 160, 54, 12));
        sendBtn = new QPushButton(groupBox_3);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setEnabled(false);
        sendBtn->setGeometry(QRect(310, 40, 75, 23));
        connectBtn = new QPushButton(centralWidget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(580, 40, 131, 41));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(520, 120, 71, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(520, 150, 81, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(520, 180, 121, 20));
        deviceSNLabel = new QLabel(centralWidget);
        deviceSNLabel->setObjectName(QStringLiteral("deviceSNLabel"));
        deviceSNLabel->setGeometry(QRect(653, 120, 131, 20));
        deviceSNLabel->setFrameShape(QFrame::Panel);
        DeviceNameLabel = new QLabel(centralWidget);
        DeviceNameLabel->setObjectName(QStringLiteral("DeviceNameLabel"));
        DeviceNameLabel->setGeometry(QRect(653, 150, 131, 20));
        DeviceNameLabel->setFrameShape(QFrame::Panel);
        DeviceNameLabel->setTextFormat(Qt::AutoText);
        DeviceInfoLabel = new QLabel(centralWidget);
        DeviceInfoLabel->setObjectName(QStringLiteral("DeviceInfoLabel"));
        DeviceInfoLabel->setGeometry(QRect(653, 180, 131, 20));
        DeviceInfoLabel->setFrameShape(QFrame::Panel);
        DeviceInfoLabel->setFrameShadow(QFrame::Plain);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 820, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "JOG", 0));
        baseAngleAddBtn->setText(QApplication::translate("MainWindow", "J1+", 0));
        baseAngleSubBtn->setText(QApplication::translate("MainWindow", "J1-", 0));
        longArmAddBtn->setText(QApplication::translate("MainWindow", "J2+", 0));
        longArmSubBtn->setText(QApplication::translate("MainWindow", "J2-", 0));
        shortArmAddBtn->setText(QApplication::translate("MainWindow", "J3+", 0));
        shortArmSubBtn->setText(QApplication::translate("MainWindow", "J3-", 0));
        rHeadAddBtn->setText(QApplication::translate("MainWindow", "J4+", 0));
        rHeadSubBtn->setText(QApplication::translate("MainWindow", "J4-", 0));
        teachMode->clear();
        teachMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Joint", 0)
         << QApplication::translate("MainWindow", "Axis", 0)
        );
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Pose", 0));
        label->setText(QApplication::translate("MainWindow", "J1", 0));
        label_2->setText(QApplication::translate("MainWindow", "X", 0));
        label_3->setText(QApplication::translate("MainWindow", "J2", 0));
        label_4->setText(QApplication::translate("MainWindow", "J3", 0));
        label_5->setText(QApplication::translate("MainWindow", "J4", 0));
        label_6->setText(QApplication::translate("MainWindow", "Y", 0));
        label_7->setText(QApplication::translate("MainWindow", "Z", 0));
        label_8->setText(QApplication::translate("MainWindow", "R", 0));
        joint1Label->setText(QApplication::translate("MainWindow", "0", 0));
        xLabel->setText(QApplication::translate("MainWindow", "0", 0));
        joint2Label->setText(QApplication::translate("MainWindow", "0", 0));
        yLabel->setText(QApplication::translate("MainWindow", "0", 0));
        joint3Label->setText(QApplication::translate("MainWindow", "0", 0));
        zLabel->setText(QApplication::translate("MainWindow", "0", 0));
        rLabel->setText(QApplication::translate("MainWindow", "0", 0));
        joint4Label->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "PTP", 0));
        label_17->setText(QApplication::translate("MainWindow", "X", 0));
        label_18->setText(QApplication::translate("MainWindow", "Y", 0));
        label_19->setText(QApplication::translate("MainWindow", "Z", 0));
        label_20->setText(QApplication::translate("MainWindow", "R", 0));
        sendBtn->setText(QApplication::translate("MainWindow", "SendPTP", 0));
        connectBtn->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_9->setText(QApplication::translate("MainWindow", "Device SN:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Device Name:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Device information:", 0));
        deviceSNLabel->setText(QString());
        DeviceNameLabel->setText(QString());
        DeviceInfoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
