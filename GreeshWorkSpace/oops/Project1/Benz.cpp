#include "Benz.h"

Benz::Benz()
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

void Benz::setLogo()
{
    imgLogo = new QPixmap(":/benz.png");
}

void Benz::setProductCompany()
{
    strCompany = "Benz";
}

void Benz::setProductDate()
{
    strDate = QDate::currentDate().toString();
}

void Benz::setProducerName()
{
    strName = "AAA";
}
void Benz::setSpeed()
{
    strSpeed = "370 kph";
}

QString Benz::getProductDate()
{
    return strDate;
}

QString Benz::getProductCompanyName()
{
    return strCompany;
}

QPixmap* Benz::getLogo()
{
    return imgLogo;
}

QString Benz::getProducerName()
{
    return strName;
}
QString Benz::getSpeed()
{
    return strSpeed;
}

Benz::~Benz()
{

}
