//@(#) Schuettler.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"
/**
 * @class Schuettler
 *
 * @brief Schuettler does the shaking of cocktails.
 *
 * A Schuettler shakes the cocktail ingredients for a given
 * amount of time.
 * Inherits from InternalDevice
 *
 */
class Schuettler : public InternalDevice
{
public:
    /** @brief Constructor that creates a Schuettler
     * @return A pointer to the created Schuettler
     *
     * This method creates a Schuettler.
     * It uses temporarily an object of the class Initialisierer
     * to initialize the Schuettler. After that the
     * Initialisierer is destroyed.
     */
    Schuettler();

    /** @brief shakes the ingredients for a given time
     * @param [in] time positive float time will be the shaking time
     *
     * This method shakes the inredients in the shaker,
     * where time is the duration of shaking.
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
