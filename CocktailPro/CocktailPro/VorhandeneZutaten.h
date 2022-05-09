//@(#) VorhandeneZutaten.h

#ifndef VorhandeneZutaten_H_H
#define VorhandeneZutaten_H_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <cstdlib> // fuer exit() unter Linux
#include <iostream>
/**
 * @class VorhandeneZutaten
 *
 * @brief VorhandeneZutaten manages a list of ingredients
 *
 *  Reads ingredients from a list
 *  memorizes the ingredients + physical state
 *
 */

class VorhandeneZutaten
{
public:
    /**
    *  Default string of ingredients filename
    */
    const std::string INGREDIENTS_FILE = "zutaten.txt";
    /**
    *  Default measurements for grams / ml
    */
    const int DEFAULT_MEASUREMENT = 1000; // for all bottles (1000 millilitres = 1 Bottle), sugar and icecubes (gramm)

    /** @brief Constructor that creates a VorhandeneZutaten
     * @param mode which mode for the ingredients (mexican = more tequila instead of nolly prat)
     * @return A pointer to the created VorhandeneZutaten
     *
     * This method creates a VorhandeneZutaten.
     * It uses temporarily an object of the class Initialisierer
     * to initialize the list of recipes. After that the
     * Initialisierer is destroyed.
     */
    explicit VorhandeneZutaten(std::string &mode);
    /**
     * @brief VorhandeneZutaten copy constructor
     * @param copyConstructorExistingIngredients VorhandeneZutaten object to copy
     */
    VorhandeneZutaten(const VorhandeneZutaten &copyConstructorExistingIngredients);

    /**
     * @brief overloading the == operator
     * @param a an object of VorhandeneZutaten; attribute to be compared to another
     * @param b an object of VorhandeneZutaten; attribute to be compared to another
     * @return a bool indicating whether two compared attributes hold the same value or not
     *
     * Allows for comparison of class data from VorhandeneZutaten
     */
    friend bool operator==(VorhandeneZutaten &a, VorhandeneZutaten &b)
    {
        bool retVal = true;
        if ((a.getNumberDispensers() != b.getNumberDispensers()))
        {
            retVal = false;
        }

        for (int i = 0; i<a.getNumberExistingIngredients() * (int)retVal; i++)
        {
            if (a.getIngredient(i) != b.getIngredient(i))
            {
                retVal = false;
                break;
            }
        }

        return retVal;
    }

    /**
     * @brief overloading the = operator
     * @param v an objectpointer of VorhandeneZutaten; attribute to be compared to another
     * @return a second copied object of class
     *
     * Allows for copying of class data from VorhandeneZutaten
     */
    VorhandeneZutaten &operator=(const VorhandeneZutaten &v)
    {
        ingredients = v.ingredients;
        numberDispensers = v.numberDispensers;
        std::string mode = "normal";
        this->readIngredientFile("zutaten.txt", mode);
        return *this;
    }

    /** @brief Destructor that destroys a VorhandeneZutaten
     */
    virtual ~VorhandeneZutaten();

    /** @brief Print all available ingredients to CLI
     *
     * Print all available ingredients to CLI
     */
    void browse(void);

    /** @brief Returns ingredient at index i.
     * @param [in] i Index to return ingredient from
     * @return A string that is the ingredient at index.
     *
     * This method returns whatever is at index i in the ingredient list.
     */
    std::string getIngredient(int i);

    /** @brief Returns amount still available for ingredient-key.
    * @param [in] str map key / name of ingredient
    * @return Amount of unit still available for ingredient
    *
    * This method returns amount in units still available for ingredient
    */
    int getIngredientAmount(std::string str);

    /** @brief Returns amount still available for ingredient-key.
    * @param [in] i index of the ingredient map
    * @return Amount of unit still available for ingredient
    *
    * This method returns amount in units still available for ingredient
    */
    int getIngredientAmountByIndex(int i);

    /** @brief Returns amount still available for ingredient-key.
    * @param [in] i index of the ingredient map
    * @param [in] amount amogus to set to
    *
    * This method returns amount in units still available for ingredient
    */
    void setIngredientAmountByIndex(int i, int amount);

    /** @brief Returns number of available ingredients
     * @return Integer of available ingredients
     *
     * Returns number of available ingredients
     */
    int getNumberExistingIngredients();

    /** @brief Returns number of dispensers
    * @return int of number dispensers
    *
    * Returns number of available dispensers
    */
    int getNumberDispensers();

private:
    // VorhandeneZutaten(const VorhandeneZutaten& copyConstructorVorhandeneZutaten){}; //forbid copy constructor and prevent auto-generated shallow copies as there is no need currently
    /**
     *  A list of all available Zutaten
     */
    std::multimap<std::string, int> *ingredients;


    /** @brief Simulates reading zutaten from zutaten.txt file
     *
     * Populates the zutaten list with hardcoded dummy values
     * SHOULD BE USED IN DEBUG MODE ONLY!
     */
    // void DummyZutatenEinfuegen();

    /**
     *   @brief Reads available Zutaten from file zutaten.txt
     *   @param [in] myFile The location to the zutaten.txt file
     *   @param [in] mode special modes to fill more ingredients of certain type
     *
     *   Reads the available zutaten from config file:
     *   zutaten.txt
     *
     *   Equivalent to DummyZutatenEinfuegen(),
     *   use this function in RELEASE config.
     */
    virtual void readIngredientFile(std::string myFile, std::string &mode);

    /**
     * The number of Dispensers
     */
    int numberDispensers;
};

/**
 * The location for the zutaten config file (zutaten.txt)
 */
static std::string FileName;

#endif
