//@(#) CocktailPro.h
#ifndef COCKTAILPRO_H
#define COCKTAILPRO_H

#include "DeviceVerwalter.h"
#include "VorhandeneZutaten.h"
#include "MischbaresRezeptbuch.h"
#include "CocktailZubereiter.h"

/**
  * @class CocktailPro
  * @brief CocktailPro simulates the cocktail mixer as a whole.
  * 
  * A CocktailPro is the cocktail mixer as a whole. It allows to choose a desired recipe by entering a recipe number or to make a demonstration.
  */
class CocktailPro
{
    private:
        //CocktailPro(const CocktailPro& other){} //forbid copy constructor and prevent funky shallow copies created by automatically generated copy constructor, reason: I don't want to implement a proper copy constructor unless needed
        static const int SPEED_FACTOR_DEMO=1000;
        static const int SPEED_FACTOR=10;

    protected:
        /**
        * Test param
        */
        bool testMode = false;

        /**
         * CocktailMaker object
         */
        CocktailZubereiter* theCocktailMaker;

        /**
         * DeviceManager object
         */
        DeviceVerwalter* theDeviceManager;

        /**
         * MixableRecipebook object
         */
        MischbaresRezeptbuch* theMixableRecipebook;

        /**
         * IngredientManager object
         */
        VorhandeneZutaten* theIngredientManager;


        /**
        * @brief helps chooseCocktail distinguishing user input and test inputs
        * @param testInput different predetermined values depending of test
        * @return returns number of recipe or debug param for google test
        */
        std::string inputHelper(const std::string &testInput);

        /**
        * @brief helps chooseCocktail to convert string to int
        * @param input string, to be converted
        * @return returns converted integer
        */
        int stringToIntHelper(const std::string &input);

        /**
        * @brief prints the menu and make user choose a cocktail recipe number
        * @return recipe number or -1 for exit
        * @param testParam cocktail to choose in testmode
        * This methods prints a menu of available recipes to std::cout and prompts the user to choose a recipe by entering a recipe number with std::cin. An input check is then performed and in case of a valid recipe number, returned. An invalid input results in an repition.
        */
        int chooseCocktail(const std::string& testParam);

        /** @brief exits the programm with exit code depending of param
        * @param n number passed from chooseCocktail
        * @return exits with exit(0) if "-1" inserted in chooseCocktail.
        */
        void end(int n);


        public:
            /**
             * @brief CocktailPro constructor
             * @param argc amount of cmd iterations
             * @param param array of additional arguments (e.g. turbo for timer)
             * @return a pointer to generated CocktailPro
             */
            CocktailPro(int argc, char* param);

            /**
            * @brief CocktailPro copy constructor
            * @param other CocktailPro object to copy
            */
            CocktailPro(const CocktailPro& other); //forbid copy constructor and prevent funky shallow copies created by automatically generated copy constructor, reason: I don't want to implement a proper copy constructor unless needed


            /**
            * @brief overloading the == operator
            * @param a an object of CocktailPro; attribute to be compared to another
            * @param b an object of CocktailPro; attribute to be compared to another
            * @return a bool indicating whether two compared attributes hold the same value or not
            *
            * Allows for comparison of class data from CocktailPro
            */
            friend bool operator==(const CocktailPro &a, const CocktailPro &b) { return a == b; }

            /**
            * @brief overloading the = operator
            * @param c an objectpointer of CocktailPro; attribute to be compared to another
            * @return a second copied object of class
            *
            * Allows for copying of class data from CocktailPro
            */
            CocktailPro& operator=(const CocktailPro &c)
            {
                theCocktailMaker = c.theCocktailMaker;
                theIngredientManager = c.theIngredientManager;
                theDeviceManager = c.theDeviceManager;
                theMixableRecipebook =  c.theMixableRecipebook;
                return *this;
            }

            /**
             * @brief asks the user for a recipe number and starts the making process
             * @param testMode Parameter of chosen cocktail if we are in testmode. If we are not this is ignored
             * This method asks the user for a recipe number to choose from, performs a validity check, and starts the cocktail making process.
             */
            void start(const std::string& testMode);

            /**
             * @brief demo() same as start()
             * @see start()
             *
             * but with predetermined recipe number 0.
             *
             */
            void demo();

};
#endif