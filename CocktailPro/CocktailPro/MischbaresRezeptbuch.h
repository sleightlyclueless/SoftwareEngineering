//@(#) MischbaresRezeptbuch.h

#ifndef MISCHBARESREZEPTBUCH_H_H
#define MISCHBARESREZEPTBUCH_H_H

#include "Recipe.h"
#include "RecipeBook.h"
#include "VorhandeneZutaten.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // fuer exit() unter Linux

/**
 * @class MischbaresRezeptbuch
 *
 * @brief Knows and can put out mixable recipes
 *
 *  This class inherits from class recipeBook.
 */
class MischbaresRezeptbuch : public RecipeBook
{
public:
    /**
     * @brief Constructor for MischbaresRezeptbuch
     *
     * @param [in] ze pointer to VorhandeneZutaten
     *
     * @return pointer to generated object
     */
    explicit MischbaresRezeptbuch(VorhandeneZutaten *ze);

    /**
     * @brief list of recipes
     *
     * This method displays the number of recipes and lets you browse them
     */
    void browse();

    /**
    * @brief check existing ingredients and remaining units - update available cocktails accordingly
    *
    * @param [in] zv pointer to VorhandeneZutaten
    */
    void updateRecipeBook(VorhandeneZutaten *zv);

private:
    /**
     * An object of VorhandeneZutaten
     */
    VorhandeneZutaten *myIngredientManager;

    /**
     * A vector that holds the recipes
     */
    std::vector<Recipe *> recipies;

    /**
     * @brief set IngredientManager
     *
     * @param [in] ze pointer to VorhandeneZutaten
     *
     * This method allows IngredientManager to be set to a value
     */
    void setIngredientManager(VorhandeneZutaten *ze);

    /**
     * @brief check if given ingredient exists
     *
     * @param [in] searchedIngredient string for searched ingredient
     *
     * @return bool if ingredient exists or not
     *
     * This method checks if a given ingredient as string exists for cocktail creation
     */
    bool checkIngredientExists(const std::string &searchedIngredient);

    /**
     * @brief check if given special ingredient step exists
     *
     * @param [in] searchedIngredient string for searched ingredient
     *
     * @return true or false wether we have a special ingredient
     *
     * This method checks if a given ingredient is a special step like crushing a lime which does not directly
     * correspond to ingredient itself
     */
    bool checkForSpecialIngredient(const std::string &searchedIngredient);

    /**
    * @brief check if given ingredient has enough amount left
    *
    * @param [in] zv Object of VorhandeneZutaten
    * @param [in] r current recipe
    * @param [in] j recipestep of recipe
    * @param [in] searchedIngredient string for searched ingredient in step
    *
    * @return true or false wether enough left
    *
    * This method checks if a given ingredient is a special step like crushing a lime which does not directly
    * correspond to ingredient itself
    */
    bool checkIngredientAmount(VorhandeneZutaten *zv, Recipe *r, int j, std::string &searchedIngredient);

    /**
    * @brief check 10% limit for warning
    *
    * @param [in] zv Object of VorhandeneZutaten
    * @param [in] searchedIngredient string for searched ingredient in step
    */
    void checkIngredientWarnings(VorhandeneZutaten *zv, std::string &searchedIngredient);
};

#endif
