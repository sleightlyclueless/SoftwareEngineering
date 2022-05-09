//@(#) CocktailZubereiter.h

#ifndef COCKTAILZUBEREITER_H
#define COCKTAILZUBEREITER_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "DeviceVerwalter.h"



/**
 * @class CocktailZubereiter
 * @brief CocktailZubereiter prepares cocktails according to the recipe steps.
 *
 */
class CocktailZubereiter
{
public:
    /**
     * @brief CocktailZubereiter constructor
     * @param [in] dm device manager pointer
     * @return a pointer to the generated object
     */
    explicit CocktailZubereiter(DeviceVerwalter* dm);

    /**
     * @brief prepares the cocktail
     * @param [in] rzpt pointer to the recipe to be prepared
     * @return indicates cocktail preparation success
     */
    bool makeCocktail(Recipe* rzpt);

    /**
    * @brief update amounts for ingredient when used in cocktail preparation
    * @param [in] ingredient name of ingredient as map key
    * @param [in] amount of ingredient to be subtracted
    */
    void upDateIngredientAmount(std::string &ingredient, int amount);

    /**
    * @brief sets ingredient amount in coalation of measurements of ingredient
    * @param [in] ingredient ingredientname
    * @param [in] amount amount to be edited
    *
    * @return amount to be updated to
    */
    int setIngredientAmount(const std::string &ingredient, int &amount) const;

    /**
    * @brief gives CocktailZubereiter access of updated Ingredients from the IngredientManager
    * @param [in] zv instance of IngredientManager
    */
    void setIngredientManager(VorhandeneZutaten* zv);

private:
    /**
     * DeviceVerwalter object
     */
    DeviceVerwalter* myDeviceManager;
    /**
     * VorhandeneZutaten object
     */
    VorhandeneZutaten* myIngredientManager;

};

#endif
