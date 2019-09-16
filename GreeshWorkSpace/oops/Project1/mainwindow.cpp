#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    carFactory = new ProductCar;
    pBenz = carFactory->createCar("Benz");
    pBmw = carFactory->createCar("BMW");
    pAudi = carFactory->createCar("Audi");
    connect(ui->btn_display,&QPushButton::clicked,this , &MainWindow::onClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (!carFactory)
        delete carFactory;
    if (!pBenz)
        delete pBenz;
    if (!pBmw)
        delete pBmw;
    if (!pAudi)
        delete pAudi;
}

void MainWindow::onClicked()
{
    ui->lb_benz_bg->setPixmap(*(pBenz->getLogo()));
    ui->lb_bmw_bg->setPixmap(*(pBmw->getLogo()));
    ui->lb_audi_bg->setPixmap(*(pAudi->getLogo()));

    ui->lb_benz_company->setText("Company: " + pBenz->getProductCompanyName()+"\n"
                                 +"Name: " + pBenz->getProducerName() + "\n"
                                 +"Speed: " + pBenz->getSpeed());
    ui->lb_bmw_company->setText("Company: " + pBmw->getProductCompanyName()+"\n"
                                +"Name: " + pBmw->getProducerName() + "\n"
                                +"Speed: " + pBmw->getSpeed());
    ui->lb_audi_company->setText("Company: " + pAudi->getProductCompanyName()+"\n"
                                 +"Name: " + pAudi->getProducerName() + "\n"
                                 +"Speed: " + pAudi->getSpeed());

    ui->lb_benz_date->setText("Date: " + pBenz->getProductDate());
    ui->lb_bmw_date->setText("Date: " + pBmw->getProductDate());
    ui->lb_audi_date->setText("Date: " + pAudi->getProductDate());
}
