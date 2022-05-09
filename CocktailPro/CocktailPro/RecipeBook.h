#ifndef RECIPEBOOK_H_489
#define RECIPEBOOK_H_489

#include <fstream>
#include <sstream>
#include <cstdlib> // fuer exit() unter Linux
#include <iostream>
#include <map>
#include <string>
#include "Recipe.h"

/**
 * @class RecipeBook
 * @brief manages a list of recipes
 *
 * A RecipeBook contains a list of recipes.
 * Number of recipes can be read, recipes queried by index, and recipes deleted.
 */
class RecipeBook
{
private:
    /**
     * @brief list of recipes
     * This variable is the list of recipes that the RecipeBook manages.
     */
    std::map<int, Recipe *> m_Recipe;

    /**
     * @brief seperates recipe values
     */
    const char LINE_SEPERATOR = ';';

    /**
     *
     */
    const std::string RECIPE_FILENAME = "Rezepte.csv";

public:
    /**
     * @brief RecipeBook constructor
     * @return a pointer to the created RecipeBook
     *
     * This method creates a RecipeBook.
     * It tries to load an existing recipe book from "Rezepte.csv" first, otherwise it will initialise with a default recipe book.
     * It uses temporarily an object of the class initialisers to initialise the list of recipes. After that the initialiser is destroyed.
     */
    RecipeBook();

    /**
     * @brief RecipeBook destructor
     *
     * The destructor clears the recipe list.
     */
    virtual ~RecipeBook();

    /**
     * @brief get number of recipes
     * @return number of recipes in the RecipeBook
     *
     * This method returns a copy of the number of recipes in the RecipeBook.
     */
    int getNumberOfRecipes();

    /**
     * @brief get recipe number "i"
     * @param [in] i recipe index
     * @return pointer to recipe number "i", if invalid "i" nullptr
     *
     * This method returns a pointer to recipe number "i". Since "i" is basically a list index, counting begins with 0. If "i" is greater or equal to the number of existing recipes, this function returns a nullptr.
     */
    Recipe *getRecipe(unsigned int i);

    /**
     * @brief delete recipe number "i" from RecipeBook
     * @param [in] i recipe index
     * @return bool indicating success
     *
     * This method deletes recipe number "i" from the RecipeBook and returns true if the deletion was successful. For invalid "i" the function returns false.
     */
    bool deleteRecipe(unsigned int i);

    /**
     * @brief Build default recipes if no Rezepte.czv file found
     */
    void buildDefaultRecipes();
};

#endif
