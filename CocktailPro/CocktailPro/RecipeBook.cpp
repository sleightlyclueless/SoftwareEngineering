/**********************************************************************************/
/*                                 Definitionsmodul                               */
/**********************************************************************************/
/*
 * File       : RecipeBook.cpp
 *
 */

#include <algorithm>
#include "RecipeBook.h"

RecipeBook::RecipeBook()
{
    m_Recipe.clear();

    // Stream anlegen
    std::ifstream in;

    // Datei oeffnen
    in.open(RECIPE_FILENAME.c_str(), std::ios::in);

    if (!in) // File konnte nicht geoeffnet werden
    {
        buildDefaultRecipes();
        return;
    }
}
void RecipeBook::buildDefaultRecipes()
{
    int i = 1;
    Recipe *newRecipe;
    
    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Caipirinha");           // Add name for recipe
    newRecipe->appendStep("Limettenstuecke", 8);// Add ingredients and their needed amount
    newRecipe->appendStep("Zucker", 15);
    newRecipe->appendStep("Stampfen", 20);
    newRecipe->appendStep("Eis", 95);
    newRecipe->appendStep("Cachaca", 5);
    newRecipe->appendStep("Mischen", 10);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Margarita");            // Add name for recipe
    newRecipe->appendStep("Zitronensaft", 2);// Add ingredients and their needed amount
    newRecipe->appendStep("Cointreau", 2);
    newRecipe->appendStep("Tequilla", 4);
    newRecipe->appendStep("Eis", 50);
    newRecipe->appendStep("Mischen", 20);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Daiquiri");         // Add name for recipe
    newRecipe->appendStep("Limettensaft", 2);// Add ingredients and their needed amount
    newRecipe->appendStep("Zuckersirup", 2);
    newRecipe->appendStep("Rum weiss", 5);
    newRecipe->appendStep("Eis", 50);
    newRecipe->appendStep("Mischen", 20);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Planters Punch");           // Add name for recipe
    newRecipe->appendStep("Zitronensaft", 2);// Add ingredients and their needed amount
    newRecipe->appendStep("Grenadine", 1);
    newRecipe->appendStep("Orangensaft", 8);
    newRecipe->appendStep("Rum braun", 6);
    newRecipe->appendStep("Eis", 100);
    newRecipe->appendStep("Mischen", 20);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Caipiroska");           // Add name for recipe
    newRecipe->appendStep("Limettenstuecke", 8);// Add ingredients and their needed amount
    newRecipe->appendStep("Zucker", 15);
    newRecipe->appendStep("Stampfen", 20);
    newRecipe->appendStep("Eis", 90);
    newRecipe->appendStep("Wodka", 5);
    newRecipe->appendStep("Mischen", 10);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Caipirissima");         // Add name for recipe
    newRecipe->appendStep("Limettenstuecke", 8);// Add ingredients and their needed amount
    newRecipe->appendStep("Zucker", 15);
    newRecipe->appendStep("Stampfen", 20);
    newRecipe->appendStep("Eis", 90);
    newRecipe->appendStep("Rum weiss", 5);
    newRecipe->appendStep("Mischen", 10);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Cuban Island");         // Add name for recipe
    newRecipe->appendStep("Zitronensaft", 2);// Add ingredients and their needed amount
    newRecipe->appendStep("Cointreau", 2);
    newRecipe->appendStep("Rum weiss", 2);
    newRecipe->appendStep("Wodka", 2);
    newRecipe->appendStep("Eis", 30);
    newRecipe->appendStep("Mischen", 30);
    m_Recipe.insert(std::make_pair(i++, newRecipe));

    newRecipe = new Recipe;                     // Create new instance of recipe
    newRecipe->setName("Martini James B");          // Add name for recipe
    newRecipe->appendStep("Gin", 6);// Add ingredients and their needed amount
    newRecipe->appendStep("Wodka", 2);
    newRecipe->appendStep("Noilly Prat", 1);
    newRecipe->appendStep("Schuetteln", 10);
    m_Recipe.insert(std::make_pair(i++, newRecipe));
}

RecipeBook::~RecipeBook()
{
    m_Recipe.clear();
}

int RecipeBook::getNumberOfRecipes()
{
    return (m_Recipe.size());
}

Recipe *RecipeBook::getRecipe(unsigned int i)
{
    Recipe* retVal = nullptr;
    if (m_Recipe.find(i) != m_Recipe.end())
        retVal = m_Recipe.find(i)->second;
    return retVal;
}

bool RecipeBook::deleteRecipe(unsigned int i)
{
    bool retVal = false;
    if (m_Recipe.find(i) != m_Recipe.end()) {
        m_Recipe.erase(m_Recipe.find(i));
        retVal = true;
    }
    return retVal;
}