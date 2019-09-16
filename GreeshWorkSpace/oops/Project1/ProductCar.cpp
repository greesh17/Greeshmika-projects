#include "ProductCar.h"

ProductCar::ProductCar()
{

}

Car* ProductCar::createCar(QString name)
{
    Car* Production = NULL;
    if (name == constStrBenz)
        Production = new Benz;
    else if (name == constStrBMW)
        Production = new BMW;
    else if (name == constStrAudi)
        Production = new Audi;
    return Production;
}

ProductCar::~ProductCar()
{

}
