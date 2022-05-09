
 #include <algorithm>
#include <iostream>

#include "Recipe.h"

Recipe::Recipe()
{
    m_RecipeStep.clear();
    m_Name = "";
}

Recipe::~Recipe()
{
    // CREATES MEMORY LEAK BECAUSE OF APPEND
}

int Recipe::getNoOfRecipeSteps()
{
    return (m_RecipeStep.size());
}

RecipeStep *Recipe::getRecipeStep(unsigned int index)
{
    if (m_RecipeStep.size() <= index)
        return nullptr;

    std::list<RecipeStep *>::iterator p;      // Iterator
    advance(p = m_RecipeStep.begin(), index); // p zeigt jetzt auf das i-te Element
    return (*p);                              // Adresse vom Wert von p - also den Pointer auf den der Iterator zeigt
}

std::string Recipe::getName() const
{
    return m_Name;
}

void Recipe::setName(const std::string& theName)
{
    this->m_Name = theName;
}

void Recipe::browse()
{
    std::cout << m_Name << ": ";                         // recipe name
    for (int i = 0; i < this->getNoOfRecipeSteps(); i++) // list all ingredients
    {
        if (0 < i)
            std::cout << ", ";
        std::cout << getRecipeStep(i)->getIngredient();
    }
}

void Recipe::appendStep(std::string theIngredient, float theAmount)
{
    RecipeStep *t;
    t = new RecipeStep;
    t->setIngredient(theIngredient);
    t->setAmount(theAmount);
    m_RecipeStep.push_back(t);
}
