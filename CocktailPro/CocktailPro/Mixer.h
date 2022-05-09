//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

/**
 * @class Mixer
 * @brief Mixer mixes for a specified amount of time.
 *
 * A mixer is an internal device that mixes ingredients for a specified amount of time.
 */
class Mixer : public InternalDevice
{
public:
    /**
     * @brief mixer constructor
     * @return a pointer to the created mixer
     *
     * This method creates a mixer.
     * It actually doesn't do anything internally.
     */
    Mixer();

    /**
     * @brief mix for "time" seconds
     * @param [in] time time in seconds
     *
     * This method activates the mixer for "time" seconds.
     */
    void doIt(float time);

private:
    /**
     * Sleep time for Sleeping interval
     */
    const int SLEEP_TIME = 1000;
};

#endif
