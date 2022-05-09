//@(#) Subject.cpp

#include "Subject.h"

void Subject::attach(Observer *observer) // Parse an observer by reference
{
    this->observers.push_back(observer); // Add the observer to the vector
}

/*void Subject::detach(Observer * observer) // Parse the observer to detach by reference
{
    for (int i = observers.size() - 1; i >= 0; i--) { // Loop over all observers in the list
        if (observers.at(i) == observer) {            // And find the one to detach
            observers.erase(observers.begin() + i);   // Finally, remove it
        }
    }
}*/

void Subject::notify() // Notifies all observers stored in the subject's list
{
    for (int i = observers.size() - 1; i >= 0; i--)
    {                              // Loop all observers
        observers.at(i)->update(); // And notify them
    }
}
