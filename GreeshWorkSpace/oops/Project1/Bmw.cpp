#include "Bmw.h"

BMW::BMW()
{
    imgLogo = NULL;
    strDate = "";
    strCompany= "";
    strName = "";
    strSpeed = "";
    setLogo();
    setProductDate();
    setProductCompany();
    setProducerName();
    setSpeed();
}

void BMW::setLogo()
{
    imgLogo = new QPixmap(":/bmw.png");
}

void BMW::setProductCompany()
{
    strCompany = "BMW";
}

void BMW::setProductDate()
{
    strDate = QDate::currentDate().toString();
}

void BMW::setProducerName()
{
    strName = "CCC";
}
void BMW::setSpeed()
{
    strSpeed = "390 kph";
}

QString BMW::getProductDate()
{
    return strDate;
}

QString BMW::getProductCompanyName()
{
    return strCompany;
}

QPixmap* BMW::getLogo()
{
    return imgLogo;
}

QString BMW::getProducerName()
{
    return strName;
}
QString BMW::getSpeed()
{
    return strSpeed;
}

BMW::~BMW()
{

}
