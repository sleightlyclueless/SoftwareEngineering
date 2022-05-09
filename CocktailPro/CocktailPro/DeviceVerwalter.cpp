//@(#) DeviceVerwalter.cpp
#include "DeviceVerwalter.h"

// constructor
DeviceVerwalter::DeviceVerwalter(VorhandeneZutaten *theIngredientManager)
{
    setIngredientManager(theIngredientManager);
    this->createDevices();
}

// construct all privately declared devices with their constructors, assign to their pointer and write them into myDevices map
void DeviceVerwalter::createDevices()
{
    theScale = new Waage();
    myDevices = new std::map<std::string, InternalDevice *>;

    myDrainer = new Entleerer(25, 1000, theScale);
    myDevices->insert(std::make_pair("Entleeren", myDrainer));

    myCrusher = new Stampfer();
    myDevices->insert(std::make_pair("Stampfen", myCrusher));

    myShaker = new Schuettler();
    myDevices->insert(std::make_pair("Schuetteln", myShaker));

    myMixer = new Mixer();
    myDevices->insert(std::make_pair("Mischen", myMixer));

    std::string _myIngredient;
    for (int i = myIngredientManager->getNumberExistingIngredients() - 1; i >= 0; i--)
    {                                                          // VorhandeneZutaten.h getAnzahlVorhandeneZutaten() -> amount of possible ingredients from vector
        _myIngredient = myIngredientManager->getIngredient(i); // get current ingerdient
        // Switch for current ingredient
        if (_myIngredient == INGREDIENT_ICE)
            myDevices->insert(std::make_pair(_myIngredient, new Dosierer(20, 1000, _myIngredient, theScale))); // combine ingredient with dosage-units into a dedicated dispenser
        else if (_myIngredient == INGREDIENT_LIMESLICE)
            myDevices->insert(std::make_pair(_myIngredient, new Dosierer(10, 1000, _myIngredient, theScale))); // combine ingredient with dosage-units into a dedicated dispenser
        else
            myDevices->insert(std::make_pair(_myIngredient, new Dosierer(1, 250, _myIngredient, theScale))); // combine ingredient with dosage-units into a dedicated dispenser
    }
}

// give required ingredients to the ingerdient-handler
void DeviceVerwalter::setIngredientManager(VorhandeneZutaten *TheIngredientManager)
{
    myIngredientManager = TheIngredientManager; // set ingerdients into the ingredient handler
}

// handle a step in cocktail creation to fill the dispensers according to recipe
std::map<std::string, InternalDevice *>::iterator DeviceVerwalter::makeRecipeStep(std::string theIngredient, float theAmount)
{
    std::map<std::string, InternalDevice *>::iterator tmpDevice; // search for the device responsible for the ingerdient in myDevices map and tmp save its iterator
    tmpDevice = myDevices->find(theIngredient);                  // not used again?

    if (theIngredient == INGREDIENT_LIMESLICE) // Check for lime slice, if yes, measure by piece
    {
        // exception for limes -> measure by piece and not time
        int _piecePerTime = (static_cast<Dosierer *>(myDevices->at(theIngredient)))->getPieceProTime();
        myDevices->at(theIngredient)->doIt(theAmount * _piecePerTime);
    }
    else
    {
        myDevices->at(theIngredient)->doIt(theAmount); // Measure by time
    }
    return tmpDevice;
}