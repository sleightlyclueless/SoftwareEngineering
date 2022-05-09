//@(#) Timer.cpp

#include "Timer.h"

/**
 * @brief Set the turbo for this timer
 * @param turbo the value of the turbo
 *
 */
void Timer::setTurbo(int turbo)
{
    this->booster = turbo;
}

/**
 * @brief Get the Timer instance
 * @return A pointer to the timer instance of this Timer
 */
Timer *Timer::getInstance()
{
    if (!instanceFlag) // If object of Timer does not exist
    {
        theTimer = new Timer(); // Create a new Timer and update instanceFlag
        instanceFlag = true;
        return theTimer; // Return new timer
    }
    else
    {
        return theTimer; // Timer already exists, return it
    }
}

/**
 * @brief Sleeps for a time measured in ms
 * @param delayInMs Delay in ms
 */
void Timer::sleep(long delayInMs)
{
    // if netbeans does not recognize system_clock you have to set the project properties to C++11:
    // Project-Properties->Code Assistance -> C++ (and C). Set it to C++!
    long now_millis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count(); // Get the value of current time to long
    long limit = now_millis + (delayInMs / booster);                                                 // Get the max. waiting time by booster and delay

    while (limit > now_millis) // Loop as long as waiting is not complete
    {

        now_millis = time_point_cast<milliseconds>(system_clock::now()).time_since_epoch().count(); // update the timer for the while cond.
    }
}

/**
 * @brief Sleeps for a time measured in ms
 * @param delayInMs Delay in ms
 */
void Timer::sleepInIntervals(long delayInMs)
{
    // to improve compatibility between Linux and Windows this implementation
    // is using busy wait (and avoids threads)! On purpose...
    long delay = 0;

    while (delayInMs > 0) // While total time to wait is greater than 0
    {
        if (delayInMs >= MAX_INTERVAL_TIME) // as long as delay_in_ms is >= 1000,
        {
            std::cout << "*" << std::flush; // Print * to cli
            delay = MAX_INTERVAL_TIME;      // Prepare delay to subtract
            delayInMs = delayInMs - delay;  // Subtract delay_in_ms by delay to reduce time
                                            // Creates a sleep interval of max. 1000 ms.
        }
        else // If delay_in_ms < 1000
        {
            std::cout << "." << std::flush; // Print a . to cli
            delay = delayInMs;              // and set the delay to delay_in_ms
            delayInMs = 0;                  // Set delay_in_ms to 0
                                            // Creates the rest of the sleep as an interval
        }
        sleep(delay); // Sleep the set interval
    }
}

bool Timer::instanceFlag = false; // Initialize the instance flag to false
                                  // because the timer does not exist by default

Timer *Timer::theTimer = 0; // Initialize the timer to 0 because the timer does not exist by default