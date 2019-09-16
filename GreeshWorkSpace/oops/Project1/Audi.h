#ifndef AUDI_H
#define AUDI_H

#include "Car.h"


class Audi: public Car
{
public:
    Audi();
    ~Audi();
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

#endif // AUDI_H
