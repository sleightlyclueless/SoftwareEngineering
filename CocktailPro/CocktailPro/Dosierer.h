//@(#) Dosierer.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
 * @class Dosierer
 *
 * @brief Dosierer measures the weight of an ingredient.
 *
 * This class inherits from the classes InternalDevice and Observer.
 *
 */
class Dosierer : public InternalDevice, public Observer
{
public:
    /**
     *@brief Constructor for a Dosierer
     * @param [in] theGramsPerTime for the weight of an ingredient
     * @param [in] theTimeUnit for the time units
     * @param [in] theContent for the contents
     * @param [in] theScale for a scale
     */
    Dosierer(float theGramsPerTime, int theTimeUnit, const std::string &theContent, Waage *theScale);

    /**
     * @brief Is busy while the weight isn't the target weight.
     * Updates the "doinIt" variable when done.
     *
     */
    virtual void update();

    /**
     * @brief pours out a set amount of weight of an ingredient
     *
     * @param [in] grams holds the weight of an ingredient
     */
    void doIt(float grams);

    /**
     * @brief fetches the amount poured out during a set amount of time
     *
     * @return an integer that holds this amount
     */
    int getPieceProTime();

private:
    /**
     * This variable shows the amount of grams per time
     */
    float gramsPerTime;

    /**
     * An object of Waage, this is the scale we use to measure
     */
    Waage *myScale;

    /**
     * weight
     */
    float weight;

    /**
     * contents
     */
    std::string content;
};

#endif
