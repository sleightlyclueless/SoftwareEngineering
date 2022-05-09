//@(#) Dosierer.cpp

#include "Dosierer.h"

/**
 *  Constructor for Dosierer, inherits from InternalDevice
 */
Dosierer::Dosierer(float theGramsPerTime, int theTimeUnit, const std::string &theContent, Waage *theScale) : InternalDevice(), content(theContent)
{
    // Set values from constructor
    this->gramsPerTime = theGramsPerTime;
    this->timeUnit = theTimeUnit;
    this->myScale = theScale;
    this->myScale->attach(this);
}

void Dosierer::update()
{
    if (!this->busy) // While not used, exit right away
    {
        return;
    }
    if (myScale->getDelta() >= weight) // If currently used and weight is above target weight,
    {
        busy = false; // Set "busy" to false, to signal its not busy
    }
}

void Dosierer::doIt(float grams)
{
    this->weight = grams; // Set current weight to input weight
    myScale->tara();      // Reset the Waage
    busy = true;          // Set as busy
    std::cout << content << " Valve has been opened." << std::endl;

    while (busy) // While busy, sleep and let time pass, update weight
    {
        myTimer->sleepInIntervals(timeUnit);
        myScale->changeWeight(gramsPerTime); // Update weight in intervals
        // myScale->changeWeight(0);
    }
    std::cout << std::endl
              << content << " Valve has been closed" << std::endl;
    std::cout << "" << myScale->getDelta() << "g " << content << " filled" << std::endl;
    std::cout << std::endl;
}

int Dosierer::getPieceProTime() // Simply returns the value of gramsPerTime
{
    return this->gramsPerTime;
}
