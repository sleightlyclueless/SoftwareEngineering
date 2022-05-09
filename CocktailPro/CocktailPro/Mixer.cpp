//@(#) Mixer.cpp

#include "Mixer.h"

Mixer::Mixer() : InternalDevice()
{
}

void Mixer::doIt(float time)
{
    myTimer->sleepInIntervals(time * SLEEP_TIME); // sleep to simulate mixing process
    std::cout << std::endl;
}
