#include "CarManager.h"

CarManager::CarManager()
{
    pCar = NULL;
}
CarManager::~CarManager()
{
    if (!pCar)
        delete pCar;
}

void CarManager::changeCar(Car *car)
{
    if (!pCar) delete pCar;
        pCar = car;
}
