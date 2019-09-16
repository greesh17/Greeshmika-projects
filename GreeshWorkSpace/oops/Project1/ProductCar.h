#ifndef PRODUCTCAR_H
#define PRODUCTCAR_H

#include "Factory.h"
#include "Benz.h"
#include "Bmw.h"
#include "Audi.h"

class ProductCar:public Factory
{
public:
    ProductCar();
    Car* createCar(QString name);
    ~ProductCar();
private:
    const QString constStrBenz = "Benz";
    const QString constStrBMW = "BMW";
    const QString constStrAudi = "Audi";
};

#endif // PRODUCTCAR_H
