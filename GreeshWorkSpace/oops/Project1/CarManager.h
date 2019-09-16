#ifndef CARMANAGER_H
#define CARMANAGER_H

#include "Car.h"

class CarManager
{
public:
    CarManager();
    ~CarManager();
    void changeCar(Car* car);
private:
    Car* pCar;
};

#endif // CARMANAGER_H
