//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>

/**
 * @class Subject
 *
 * @brief Subject manages a collection of Observers
 *
 * A subject manages a list of observers.
 * Observers can be attached, detached and notified.
 * Latter function will update all observer's statuses
 *
 */

class Subject
{
public:
    /** @brief Attaches a new observer to the list
     * @param [in] observer a pointer to the observer to add
     *
     * This method will attach the given observer to the observers list
     *
     */
    void attach(Observer *observer);

    /*
     *
     * @brief Detaches an observer from this subject
     * @param [in] observer a pointer to the observer to detach
     *
     * This method will detach the given observer.
     * It will be removed from the observers list
     *
     */
    // void detach(Observer * observer);

    /** @brief Notifies (updates) all observers in the list
     *
     * This method will notify all observers in the list observers and update their statuses
     *
     */
    void notify();

private:
    /**
     * This is the list of observers that the Subject manages
     *
     */
    std::vector<Observer *> observers;
};

#endif
