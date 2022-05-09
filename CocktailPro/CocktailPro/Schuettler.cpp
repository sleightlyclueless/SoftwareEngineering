/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : Schuettler.cpp
 *
 */

#include "Schuettler.h"

// Constructor (Extends Internal Device)
Schuettler::Schuettler() : InternalDevice()
{
}

/**
 * @param [in] time float: Time to shake in seconds
 */
void Schuettler::doIt(float time)
{
    myTimer->sleepInIntervals(time * TIME_FACTOR); // Waits "time" seconds
    std::cout << std::endl;                        // Newline in CLI
}
