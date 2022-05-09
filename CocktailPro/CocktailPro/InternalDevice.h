//@(#) InternalDevice.h

#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**@class InternalDevice
 *
 * @brief abstract of measure pourers and processing units
 *
 */
class InternalDevice
{
public:
    /**
     * @brief shows that the ingredients are being poured out
     *
     * @param [in] value
     *
     * This method is to be inherited by classes Dosierer and Entleer
     */
    virtual void doIt(float value) = 0;

    /**
     * @brief output signals an ongoing cleaning process
     *
     * the appliance lets the user know it is cleaning itself. The timer is paused.
     */
    void clean();

private:
    /**
     * @brief The timer is set
     *
     * The function body is currently empty. Nothing is happening.
     */
    // void setTimer();

public:
    /**
     * @brief Constructor for InternalDevice
     */
    InternalDevice();

protected:
    /**
     * This variable holds the unit of time in interature
     */
    int timeUnit;

    /**
     * This boolean indicates something is currently happening inside the appliance
     */
    bool busy;

    /**
     * An object of Timer
     */
    Timer *myTimer;
};

#endif
