//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"

/**
 * @class Stampfer
 *
 * @brief Stampfer crushes the ingredients
 *
 * Stampfer crushes the ingredients for a given
 * amount of time.
 *
 */

class Stampfer : public InternalDevice
{
public:
    /** @brief Constructor that creates a Stampfer
     * @return A pointer to the created Stampfer
     *
     * This method creates a Stampfer.
     * It uses temporarily an object of the class Initialisierer
     * to initialize the Stampfer. After that the
     * Initialisierer is destroyed.
     */
    Stampfer();

    /** @brief Crushes the ingredients for a given time
     * @param [in] time a positive float. Ingredients will be crushed for that time
     *
     * Crushes the current ingredients for a given amount of time
     * Will print a linebreak when finished
     *
     */
    void doIt(float time);

private:
    /**
     * The amount of time in milliseconds for wait / sleep functions in this class.
     * Every sleep input value gets multiplied by this, so the input to the sleep()
     * function is in seconds.
     */
    const int TIME_FACTOR = 1000;
};

#endif
