#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Form;
}

class ConnectTest : public QObject
{
    Q_OBJECT

public:
    ConnectTest();
    void setCom(QString com);
    Q_INVOKABLE void onStart();

private:
    QString m_com;
};

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();
    void searchDobot1(void);

private:
    Ui::Form *ui;
    QTimer *m_searchTime;
};

#endif // FORM_H
