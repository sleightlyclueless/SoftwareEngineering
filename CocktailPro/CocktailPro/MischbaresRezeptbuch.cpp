//@(#) MischbaresRezeptbuch.cpp

#include "MischbaresRezeptbuch.h"
#include <iostream>
//

void MischbaresRezeptbuch::browse()
{
    std::cout << "*********************************************" << std::endl;
    std::cout << "********** Mixable recipes **********" << std::endl;
    std::cout << "There are " << this->getNumberOfRecipes() << " cocktails" << std::endl;

    int foundCocktails = 0;
    int i = 0;
    while (foundCocktails < this->getNumberOfRecipes())
    {
        i++;
        Recipe *r = this->getRecipe(i); // Hallo Felix. Diese Zeile hier versucht den Cocktail mit der Nummer i zu holen.
        if(r != nullptr)
        {
            std::cout << i << ".";
            r->browse();
            std::cout << std::endl;
            foundCocktails++; // Prevent endless loop
        }
    }
    std::cout << "*********************************************" << std::endl;
}

MischbaresRezeptbuch::MischbaresRezeptbuch(VorhandeneZutaten *zv)
{

    // Debug *********
    std::cout << "********** Recipes before filtering **********" << std::endl;
    browse();
    // ******************

    setIngredientManager(zv);
    updateRecipeBook(zv);
}


void MischbaresRezeptbuch::updateRecipeBook(VorhandeneZutaten *zv) {
    int foundCocktails = 0;
    int i = 0;
    while (foundCocktails < getNumberOfRecipes())
    {
        i++;
        Recipe *r = getRecipe(i);
        if(r != nullptr)
        {
            foundCocktails++; // Prevent endless loop

            for (int j = 0; j < r->getNoOfRecipeSteps(); ++j) // Check if recipe is mixable
            {
                std::string searchedIngredient = r->getRecipeStep(j)->getIngredient();
                if(!checkIngredientExists(searchedIngredient) || !checkIngredientAmount(zv, r, j, searchedIngredient))
                {
                    deleteRecipe(i);
                    foundCocktails--; // Prevent skipping of recipes when one deleted
                    break;
                }

            }
        }
    }
}

bool MischbaresRezeptbuch::checkIngredientAmount(VorhandeneZutaten *zv, Recipe *r, int j, std::string &searchedIngredient) {
    bool retVal = false;

    if(checkForSpecialIngredient(searchedIngredient)) // If its a speshul ingredient, return true always!!!!
    {
        retVal = true;
    }

    for(int i = 0; i < zv->getNumberExistingIngredients(); i++) // Loop over all keys in map
    {
        std::string _key = zv->getIngredient(i);                // Get the current key at pos
        if(_key == searchedIngredient)                          // Check if the current Key is the searched
        {
            if(r->getRecipeStep(j)->getAmount() <= zv->getIngredientAmountByIndex(i)) // Is enough
            {
                retVal = true;
                break;
            }
        }
    }
    checkIngredientWarnings(zv, searchedIngredient);


    return retVal;
}

void MischbaresRezeptbuch::checkIngredientWarnings(VorhandeneZutaten *zv, std::string &searchedIngredient)
{
    // check 10% limit for warning
    if (zv->getIngredientAmount(searchedIngredient) <= zv->DEFAULT_MEASUREMENT * 0.1 && !checkForSpecialIngredient(searchedIngredient))
    {
        std::cout << "WARNING: " << searchedIngredient << " ALMOST EMPTY!" << std::endl;
    }
}

bool MischbaresRezeptbuch::checkIngredientExists(const std::string &searchedIngredient)
{
    bool retVal = checkForSpecialIngredient(searchedIngredient);

    for (int k = 0; k < myIngredientManager->getNumberExistingIngredients(); k++) // For "Normal" Consumable ingredients
    {
        if (myIngredientManager->getIngredient(k) == searchedIngredient)
        {
            retVal = true;
            break;
        }
    }
    return retVal;
}

bool MischbaresRezeptbuch::checkForSpecialIngredient(const std::string &searchedIngredient)
{
    int retVal = false;
    if (searchedIngredient == "Stampfen" || searchedIngredient == "Mischen" || searchedIngredient == "Schuetteln") // These always exist
        retVal = true;
    return retVal;
}

void MischbaresRezeptbuch::setIngredientManager(VorhandeneZutaten *ze)
{
    myIngredientManager = ze;
}
