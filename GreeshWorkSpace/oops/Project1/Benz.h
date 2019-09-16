#ifndef BENZ_H
#define BENZ_H

#include "Car.h"


class Benz: public Car
{
public:
    Benz();
    ~Benz();
    QString getProductCompanyName();
    QString getProductDate();
    QPixmap* getLogo();
    QString getProducerName();
    QString getSpeed();
private:
    void setLogo();
    void setProductCompany();
    void setProductDate();
    void setProducerName();
    void setSpeed();
    QPixmap* imgLogo;
    QString strCompany;
    QString strDate;
    QString strName;
    QString strSpeed;

};

#endif // BENZ_H
