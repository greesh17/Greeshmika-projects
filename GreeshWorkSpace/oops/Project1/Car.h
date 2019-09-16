#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QPixmap>
#include <QDate>
#include <QDebug>

class Car
{
public:
    Car();
    virtual ~Car();
    virtual QString getProductCompanyName() = 0;
    virtual QString getProductDate() = 0;
    virtual QString getProducerName() = 0;
    virtual QString getSpeed() = 0;
    virtual QPixmap* getLogo() = 0;
private:
    virtual void setLogo() = 0;
    virtual void setProductCompany() = 0;
    virtual void setProductDate() = 0;
    virtual void setProducerName() = 0;
    virtual void setSpeed() = 0;

};

#endif // CAR_H
