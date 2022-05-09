/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : Stampfer.cpp
 *
 */

#include "Stampfer.h"
/**
 * @brief Constructor for Stampfer
 * @returns Pointer to Stampfer
 *
 * Instantiates a new Stampfer instance.
 *
 */
Stampfer::Stampfer() : InternalDevice()
{
}

/**
 * @brief Method to crush ingredients
 * @param time the time to crush in seconds
 */
void Stampfer::doIt(float time)
{
    myTimer->sleepInIntervals(time * TIME_FACTOR); // Wait for "time" seconds
    std::cout << std::endl;                        // Print linebreak
}
