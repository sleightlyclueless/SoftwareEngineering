//@(#) Waage.h
#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

/**
 *@class Waage
 *@brief Waage as subject device to observe and use it
 *
 */
class Waage : public Subject
{
public:
    /**
     * @brief Constructor for Waage
     * @return pointer to Waage
     */
    Waage();

    /**
     *@brief increase weight and delta weight according to stap
     *@param additionalWeight total weight for the step
     *
     */
    void changeWeight(int additionalWeight);
    /**
     *@brief reset deltaweight to 0
     *
     */
    int tara();
    /**
     *@brief get current weight
     *@return return weight
     *
     */
    int getWeight();
    /**
     *@brief get current deltaweight
     *@return return deltaweight
     *
     */
    int getDelta();

private:
    /**
     * int weight
     */
    int weight{};
    /**
     * int deltaweight
     */
    int deltaweight{};
};

#endif
