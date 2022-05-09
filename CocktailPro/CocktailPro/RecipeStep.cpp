#include <algorithm>
#include "RecipeStep.h"

RecipeStep::RecipeStep() : m_Ingredient(""), m_Amount(0)
{
}

RecipeStep::~RecipeStep()
{
}

std::string RecipeStep::getIngredient(void) const
{
    return m_Ingredient;
}

float RecipeStep::getAmount(void) const
{
    return m_Amount;
}

void RecipeStep::setIngredient(const std::string &_m_Ingredient)
{
    this->m_Ingredient = _m_Ingredient;
}

void RecipeStep::setAmount(float _m_Amount)
{
    this->m_Amount = _m_Amount;
}
