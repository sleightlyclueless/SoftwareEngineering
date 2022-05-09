#ifndef _REZEPTSCHRITT_H_472
#define _REZEPTSCHRITT_H_472

#include <list>
#include <string>

/**
 * @class RecipeStep
 * @brief recipe step
 *
 * A RecipeStep is a step within a recipe and contains an ingredient and an amount.
 * Ingredient and amount can be read and changed.
 */
class RecipeStep
{
private:
    /**
     * recipe step ingredient
     */
    std::string m_Ingredient;

    /**
     * recipe step amount
     */
    float m_Amount;

public:
    /**
     * @brief RecipeStep constructor
     * @return a pointer to the created RecipeStep
     *
     * This method creates a RecipeStep.
     * It initialises the name with an empty string and the amount with 0.
     */
    RecipeStep();

    /**
     * @brief RecipeStep destructor
     */
    ~RecipeStep();

    /**
     * @brief get ingredient name
     * @return ingredient name
     *
     * This method returns a copy of the ingredient name.
     */
    std::string getIngredient() const;

    /**
     * @brief get ingredient amount
     * @return ingredient amount
     *
     * This method returns a copy of the ingredient amount.
     */
    float getAmount(void) const;

    /**
     * @brief set ingredient name
     * @param [in] _m_Ingredient new ingredient name
     *
     * This method sets the ingredient name to "m_Ingredient".
     */
    void setIngredient(const std::string &_m_Ingredient);

    /**
     * @brief set ingredient amount
     * @param [in] _m_Amount new ingredient amount
     *
     * This method sets the ingredient amount to "m_Amount".
     */
    void setAmount(float _m_Amount);
};
#endif
