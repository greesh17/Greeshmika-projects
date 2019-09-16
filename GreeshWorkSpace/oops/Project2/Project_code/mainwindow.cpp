#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "global.h"

QHash<int , Message> sharedData;

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pThreadSender = new Sender;
    pThreadReceiver = new Receiver;
    connect(ui->btn_Start , &QPushButton::clicked , this , &MainWindow::onStart);
    connect(pThreadReceiver , &Receiver::FinishReceiver , this , &MainWindow::onFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onFinished()
{
    QString result = "";
    for (int i = 0; i < 5;i++) {
        Message m = sharedData.value(i);
        QString temp = "";
        temp.setNum(m.getData().sum);
        result += temp + " ";
    }
    ui->lb_Result->setText(result);
}

void MainWindow::onStart()
{
    pThreadSender->start();
    pThreadReceiver->start();
}
