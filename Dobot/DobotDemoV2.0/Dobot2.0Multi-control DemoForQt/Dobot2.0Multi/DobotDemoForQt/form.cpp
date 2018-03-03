#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "DobotDll.h"
#include <QDebug>
#include <QThread>



ConnectTest::ConnectTest():QObject(0){}
void ConnectTest::setCom(QString com)
{
    m_com = com;
}
void ConnectTest::onStart()
{
    char fwType[20];
    char version[20];
    int dobotId;
    int flag = 1;
    int flagb = 1;
    int flagc = 1;
    PTPCmd ptpCmd;
    ptpCmd.ptpMode = PTPMOVJXYZMode;
    ptpCmd.z = 30;
    ptpCmd.r = 0;
    ptpCmd.x = 250;
    while(true){
        if (ConnectDobot(m_com.toLatin1().data(), 115200, fwType, version, &dobotId) != DobotConnect_NoError) {
            qDebug() << QThread::currentThread() <<" dobotId " << dobotId << m_com << "error";
            continue;
        }
        qDebug() << "ConnectDobot" << QThread::currentThread() << " dobotId " << dobotId << m_com << "success";

        ptpCmd.y = flag > 0?20:-20;
        ptpCmd.z = flagb > 0? 20 : -20;
        qDebug() << ptpCmd.y;
        SetQueuedCmdStartExec(dobotId);
        while (SetPTPCmd(dobotId, &ptpCmd, true, NULL) != DobotCommunicate_NoError) {
            qDebug() << "ConnectDobot" << QThread::currentThread() << " dobotId " << dobotId << m_com << "send error";
        }
        DisconnectDobot(dobotId);
        qDebug() << "DisconnectDobot" << QThread::currentThread() << " dobotId " << dobotId << m_com << "success";
        flag *= -1;
        flagc ++;
        if(flagc % 3 == 0)
            flagb *= -1;
        QThread::currentThread()->msleep(100);
    }
}

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    m_searchTime = new QTimer(this);
    connect(m_searchTime, SIGNAL(timeout()), this, SLOT(searchDobot1()));
    m_searchTime->setSingleShot(true);
    m_searchTime->setInterval(1);
    m_searchTime->start();
}

Form::~Form()
{
    m_searchTime->stop();
    delete ui;
}

void Form::on_pushButton_clicked()
{
    static int winNum = 0;
    winNum ++;
    MainWindow *mainWindow = new MainWindow(this);
    this->ui->tabWidget->addTab(mainWindow, QString("新窗口%1").arg(winNum));
}

void Form::searchDobot1(void)
{
    char lis[100];
    SearchDobot(lis, 100);
    ui->lbSearchResult->setText(QString(lis));
    QStringList comList = QString(lis).split(" ");
    if(QString(lis).isEmpty() || comList.size() < 2){
        m_searchTime->start();
        return;
    }

    qDebug() << "searchDobot1" << comList;

    for (int i = 0; i < comList.size(); ++i)
    {
        ConnectTest *ttttt = new ConnectTest();
        qDebug() << comList.at(i);
        ttttt->setCom(comList.at(i));
        QThread *trhd = new QThread();
        trhd->start();
        ttttt->moveToThread(trhd);
        QMetaObject::invokeMethod(ttttt, "onStart", Qt::QueuedConnection);
    }

}
