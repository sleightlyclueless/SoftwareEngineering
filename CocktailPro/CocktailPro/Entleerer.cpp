//@(#) Entleerer.cpp

#include "Entleerer.h"
// Constructor
Entleerer::Entleerer(float ingredientWeight, int currTimeUnit, Waage *waage) : InternalDevice()
{
    this->gramPerTime = ingredientWeight;
    this->timeUnit = currTimeUnit;
    this->myScale = waage;
    this->myScale->attach(this);
}
// Destructor
Entleerer::~Entleerer() {}

void Entleerer::update()
{
    if (!this->busy)
        return;                              // If not busy, return
    if (myScale->getWeight() <= this->value) // If busy and done, set busy = false,
    {
        busy = 0;
    } // aka set busy false
}

void Entleerer::doIt(float _value)
{
    std::cout << "Your cocktail has a total weight of " << myScale->getWeight() << "g" << std::endl;
    std::cout << "Starting draining..." << std::endl;
    this->value = _value;
    busy = 1;
    while (busy)
    {                                        // Loop while busy
        myTimer->sleepInIntervals(timeUnit); // Wait and update weight
        myScale->changeWeight(-gramPerTime);
    }
    std::cout << std::endl;
    std::cout << "Emptying stopped, please claim your cocktail!" << std::endl;
    std::cout << std::endl;
}
