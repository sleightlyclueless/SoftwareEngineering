//@(#) Entleerer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/** @class Entleerer
 *
 * @brief empties the cocktail
 *
 * This class inherits from classes InternalDevice and Observer
 */
class Entleerer : public InternalDevice, public Observer
{
public:
    /** @brief Constructor for the Entleerer
     *
     * @param [in] ingredientWeight holds the weight of an ingredient dispensed per unit of time
     * @param [in] currTimeUnit holds the unit of time
     * @param [in] waage is the scale used to measure ingredients
     */
    Entleerer(float ingredientWeight, int currTimeUnit, Waage *waage);

    /**
     * @brief Entleerer destructor
     *
     * As of now, it is empty
     */
    ~Entleerer();

    /**
     * @brief updates the weight
     */
    void update();

    /**
     * @brief empties InternalDevice
     * @param [in] _value holds a value to be assigned to the original float value in doIt()
     */
    void doIt(float _value);

private:
    /**
     * This variable shows the amount of grams per time
     */
    float gramPerTime;

    /**
     * An object of Waage, this is the scale we use to measure
     */
    Waage *myScale;

    /**
     * value
     */
    float value;

    /**
     * contents
     */
    std::string contents;
};

#endif
