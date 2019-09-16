#ifndef BMW_H
#define BMW_H

#include "Car.h"


class BMW: public Car
{
public:
    BMW();
    ~BMW();
    QString getProductCompanyName();
    QString getProductDate();
    QString getProducerName();
    QString getSpeed();
    QPixmap* getLogo();
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

#endif // BMW_H
