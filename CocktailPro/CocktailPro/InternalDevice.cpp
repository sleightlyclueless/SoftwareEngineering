//@(#) InternalDevice.cpp

#include "InternalDevice.h"
/*
void InternalDevice::setTimer() {

}*/

InternalDevice::InternalDevice() // Constructor, sets variables to default
{
    myTimer = Timer::getInstance();
    this->busy = 0;
    timeUnit = 0;
}

void InternalDevice::clean()
{
    std::cout << "Cleaning..." << std::endl;
    myTimer->sleep(500);
    std::cout << "Done cleaning!" << std::endl;
}
