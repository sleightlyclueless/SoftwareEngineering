#ifndef _REZEPT_H_479
#define _REZEPT_H_479

#include <list>
#include <string>
#include "RecipeStep.h"

/**
 * @class Recipe
 * @brief Recipe bundles the steps needed to make a cocktail.
 *
 * A Recipe is a name and a list of steps to make a cocktail. Each step contains an ingredient name and an amount.
 * Steps can be read and appended, all necessary ingredients browsed, the recipe name read and changed, as well as the number of steps read.
 */
class Recipe
{
private:
    /**
     * @brief recipe steps to create a cocktail
     *
     * This variable is a list of steps to make a cocktail. Each recipe step contains an ingredient name and an amount.
     */
    std::list<RecipeStep *> m_RecipeStep;

    /**
     * recipe name
     */
    std::string m_Name;

public:
    /**
     * @brief Recipe constructor
     * @return a pointer to the created Recipe
     *
     * This method creates a Recipe.
     * It initialises the name with an empty string and the recipe steps with an empty list.
     */
    Recipe();

    /**
     * @brief Recipe destructor
     * Right now, it doesn't do anyhing and thus creates a memory leak, because the created RecipeStep are not deleted.
     */
    ~Recipe();

    /**
     * @brief get number of recipe steps
     * @return number of recipe steps
     *
     * This method returns the number of recipe steps.
     */
    int getNoOfRecipeSteps();

    /**
     * @brief get recipe step number "i"
     * @param [in] index recipe step index
     * @return pointer to recipe step number "i", if invalid "i" nullptr
     *
     * This method returns a pointer to recipe step number "i". Since "i" is basically a list index, counting begins with 0. If "i" is greater or equal to the number of existing recipe steps, this function returns a nullptr.
     */
    RecipeStep *getRecipeStep(unsigned int index);

    /**
     * @brief get recipe name
     * @return recipe name
     *
     * This method returns a copy of the recipe name.
     */
    std::string getName() const;

    /**
     * @brief set recipe name
     * @param [in] theName new recipe name
     *
     * This method sets the recipe name to "Name".
     */
    void setName(const std::string &theName);

    /**
     * @brief append step to recipe
     * @param [in] theIngredient ingredient
     * @param [in] theAmount amount
     *
     * This method appends a step to the recipe. A recipe step contains an ingredient "z" and an amount "m". With those paramters, it creates a RecipeStep* interally and appends the pointer to the list of recipe steps.
     */
    void appendStep(std::string theIngredient, float theAmount);

    /**
     * @brief list of all ingredients
     * @return printout of all ingredients in std::cout
     *
     * This method prints a list of all ingredients sorted by step order. If an ingredient exists within multiple steps, duplicates are not removed.
     */
    void browse();
};

#endif