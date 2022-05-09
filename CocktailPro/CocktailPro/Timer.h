//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

#include <chrono>
using namespace std::chrono;
#include <iostream>

/**
 * @class Timer
 * @brief Timer manages a collection of recipes
 *
 * Timer is responsible for sleeping tasks.
 * Time is measured in ms
 *
 */
class Timer
{
public:
    /** @brief This function will set the booster to the given amount
     * @param [in] turbo The turbo value to set the booster to
     *
     * Sets the booster to the turbo amount
     */
    void setTurbo(int turbo);

    /** @brief This function will create a new Timer object if necessary
     * @return A pointer to a timer
     *
     * Creates a new timer object if necessary. If not, it returns the existing one.
     * Also updates the instanceFlag parameter if necessary.
     */
    static Timer *getInstance();

    /**
     * 	~Timer( )
     *     {
     *         instanceFlag = false;
     *     };
     */

    /** @brief This function will make the program wait for given time
     * @param [in] delayInMs A long integer, the time to wait in milliseconds
     *
     * Makes the program wait for a given amount of time.
     * Ignores threads for compatibility, waits in intervals of max. 1000 ms
     * and updates the progress in CLI
     */
    void sleepInIntervals(long delayInMs);

    /** @brief This function will make the program wait for given time
     * @param [in] delayInMs A long integer, the time to wait in milliseconds
     *
     * Makes the program wait for a given amount of time.
     * Using while loops to block threads.
     */
    void sleep(long delayInMs);

private:
    /**
     * Checks if a timer instance exists
     */
    static bool instanceFlag;

    /**
     * Holds a reference to the timer
     */
    static Timer *theTimer;

    /**
     * Stores the amount of the booster
     */
    int booster;

    /**
     * Length of one waiting interval in milliseconds
     */
    const int MAX_INTERVAL_TIME = 1000;

    /** @brief Constructor that creates a Timer
     * @return A pointer to the created Timer
     *
     * This method creates a Timer.
     * It uses temporarily an object of the class Initialisierer
     * to initialize the list of recipes. After that the
     * Initialisierer is destroyed.
     *
     * Sets the booster to 1 by default.
     */
    Timer() : booster(1){};
};

#endif
