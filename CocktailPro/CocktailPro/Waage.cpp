//@(#) Waage.cpp
#include "Waage.h"

Waage::Waage() : Subject()
{
    this->weight = 0;
    this->deltaweight = 0;
}

void Waage::changeWeight(int additionalWeight)
{
    weight += additionalWeight; // calculate total weight with given value
    if (weight < 0)
        weight = 0;
    deltaweight += additionalWeight; // increase total weight of current step
    notify();                        // tell observer device has been updated
}

int Waage::tara()
{
    return deltaweight = 0;
}

int Waage::getWeight()
{
    return weight;
}

int Waage::getDelta()
{
    return deltaweight;
}
