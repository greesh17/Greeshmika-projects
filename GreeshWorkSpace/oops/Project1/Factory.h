#ifndef FACTORY_H
#define FACTORY_H

#include "Car.h"
#include <QString>

class Factory
{
public:
    Factory();
    virtual Car* createCar(QString name) = 0;
    virtual ~Factory();
};

#endif // FACTORY_H
