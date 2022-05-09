//@(#) DeviceVerwalter.h
#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "VorhandeneZutaten.h"
#include "Dosierer.h"
#include "Mixer.h"
#include "Stampfer.h"
#include "Schuettler.h"
#include "Entleerer.h"
#include "Waage.h"

/**
 *@class DeviceVerwalter
 *@brief DeviceVerwalter fills dispensers and manages their interaction with other hardware classes during cocktail mixing steps
 *
 */
class DeviceVerwalter
{
public:
    /**
     *@brief Consructor for objects of DeviceVerwalter
     *@return pointer to generated object
     *@param theIngredientManager pointer to list of available ingredients
     *
     */
    explicit DeviceVerwalter(VorhandeneZutaten *theIngredientManager);

    /**
     *@brief handle a step in cocktail creation to fill the dispensers according to recipe
     *@param theIngredient ingredient for this step
     *@param theAmount amount of ingredient in this step
     *
     */
    std::map<std::string, InternalDevice *>::iterator
    makeRecipeStep(std::string theIngredient, float theAmount);

    /**
     * Entleerer object to pour cocktail in the end
     */
    Entleerer *myDrainer;

    /**
     * Any other device (with self-function putzen())
     */
    std::map<std::string, InternalDevice *> *myDevices;

private:
    /**
     *@brief give required ingredients to the ingerdient-handler
     *@return none
     *@param TheIngredientManager pointer to list of available ingredients
     *
     */
    void setIngredientManager(VorhandeneZutaten *TheIngredientManager);

    /**
     * Object of Mixer
     */
    Mixer *myMixer;
    /**
     * Object of myCrusher
     */
    Stampfer *myCrusher;
    /**
     * Object of myShaker
     */
    Schuettler *myShaker;
    /**
     * Object of myIngredientManager
     */
    VorhandeneZutaten *myIngredientManager;
    /**
     * Object of theScale
     */
    Waage *theScale;

    /**
     * Constant for lime slice ingredient
     */
    const std::string INGREDIENT_LIMESLICE = "Limettenstuecke";

    /**
     * Constant for lime slice ingredient
     */
    const std::string INGREDIENT_ICE = "Eis";

    /**
     *@brief construct all privately declared devices with their constructors, assign them to their pointer and write them into myDevices map
     *@return none
     *
     */
    void createDevices();
};

#endif
