#include "Audi.h"

Audi::Audi()
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

void Audi::setLogo()
{
    imgLogo = new QPixmap(":/audi.png");
}

void Audi::setProductCompany()
{
    strCompany = "Audi";
}

void Audi::setProductDate()
{
    strDate = QDate::currentDate().toString();
}


void Audi::setProducerName()
{
    strName = "BBB";
}
void Audi::setSpeed()
{
    strSpeed = "340 kph";
}


QString Audi::getProductDate()
{
    return strDate;
}

QString Audi::getProductCompanyName()
{
    return strCompany;
}

QPixmap* Audi::getLogo()
{
    return imgLogo;
}

QString Audi::getProducerName()
{
    return strName;
}
QString Audi::getSpeed()
{
    return strSpeed;
}

Audi::~Audi()
{

}
