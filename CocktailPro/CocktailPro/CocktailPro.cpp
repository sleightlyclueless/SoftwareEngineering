//@(#) CocktailPro.cpp
#include "CocktailPro.h"
#include <string>

// constructor
CocktailPro::CocktailPro(int argc, char* param)
{
    // construct helper objects for cocktail creation in files with same name
    std::string mode = "normal";
    theIngredientManager = new VorhandeneZutaten(mode);
    theMixableRecipebook = new MischbaresRezeptbuch(theIngredientManager);
    theDeviceManager = new DeviceVerwalter(theIngredientManager);
    theCocktailMaker = new CocktailZubereiter(theDeviceManager);
    theCocktailMaker->setIngredientManager(theIngredientManager); // give CocktailMaker access to ingredientManager to handle ingredient amounts since startup

    Timer * theTimer = Timer::getInstance(); // static constructor for timer element at Timer.h

    if (argc==2)
    {
        theTimer->setTurbo(SPEED_FACTOR); // initially normal speed
        if (std::string(param) == "-D") // if demomode (turbo + demo function)
        {
            theTimer->setTurbo(SPEED_FACTOR_DEMO);
            demo();
        }
        else if (std::string(param) == "-G") // if googletestmode
        {
            theTimer->setTurbo(SPEED_FACTOR_DEMO);
            testMode = true;
        }
        else if (std::string(param) == "-T") // if turbomode (turbo on)
        {
            theTimer->setTurbo(SPEED_FACTOR_DEMO);
        }
    }
}

// Copy constructor - assign parameters
CocktailPro::CocktailPro(const CocktailPro& other)
{
    testMode = other.testMode;
    theCocktailMaker = new CocktailZubereiter(other.theDeviceManager);
    std::string mode = "normal";
    theIngredientManager = new VorhandeneZutaten(mode);
    theDeviceManager = new DeviceVerwalter(theIngredientManager);
    theMixableRecipebook =  new MischbaresRezeptbuch(other.theIngredientManager);
}


// print the menue and make user choose a cocktail recipe number
int CocktailPro::chooseCocktail(const std::string& testParam)
{
    while(true)
    {
        theIngredientManager->browse();                                         // VorhandeneZutaten.h browse() -> print all ingredients and their available units
        theMixableRecipebook->browse();                                         // MischbaresRezeptbuch.h browse() -> print all available cocktails and their selection number
        std::cout << "What would you like to order? (-1 to exit)" << std::endl;

        // get user input for cocktail number as string and convert to integer
        std::string input   = inputHelper(testParam);                           // user input
        int recipeNumber    = stringToIntHelper(input);                         // user input converted to int, recipe number
        int recipeNumberMax = theMixableRecipebook->getNumberOfRecipes();       // maximum allowed recipe number, number of recipes

        end(recipeNumber);                                                      // on -1 exit loop

        if(theMixableRecipebook->getRecipe(recipeNumber) == nullptr)                      // if recipe doesn't exist: error
        {
            std::cout << "MEEEP! Too many fingers on keyboard error!\n";
            std::cout << "Please input a cocktail number between between 1 and " << recipeNumberMax<<"!\n";
            if (!testMode)                                                          // only one loop on non testmode - otherwise stuck in google tests
                continue;
        }

        return recipeNumber;
    }
}

// depending on google tests or not use parameter as cocktail number or use cin
std::string CocktailPro::inputHelper(const std::string& testInput)
{
    std::string input;
    if (testMode)
        input = testInput;
    else
        std::cin >> input;
    return input;
}

// pass string to integer and return -2 if there was an error -> too many fingers error triggered
int CocktailPro::stringToIntHelper(const std::string& input)
{
    int recipeNumber = -2;
    try
    {
        recipeNumber=std::stoi(input);  //convert std::string to int
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: Input could not be converted to integer.\n";
    }
    return recipeNumber;
}

// check to end the programm on passed cocktail value
void CocktailPro::end(int n)
{
    if (n == -1)
    {
        std::cerr << "Device shutting down!" << std::endl;
        exit(0);
    }
}

// asks the user for a recipe (number) to choose from to continue with the program
void CocktailPro::start(const std::string& testParam)
{
    while(true)
    {
        theMixableRecipebook->updateRecipeBook(theIngredientManager);               //Update recipebook after a cocktail was made
        int CocktailNo=chooseCocktail(testParam);                                   //return value of user input for selected cocktail-recipe if available
        Recipe* rezeptptr = theMixableRecipebook->getRecipe(CocktailNo);            //Recipebook.cpp getRecipe -> pointer to recipe at position of list
        theCocktailMaker->makeCocktail(rezeptptr);                                  //Cocktailzubereiter.cpp -> bool makeCocktail prints all steps and return true

        if (testMode) break;                                                        // Only one loop on non testmode - otherwise stuck in google tests
    }
}

// see start - the same only with predetermined recipe 0
void CocktailPro::demo()
{
    theCocktailMaker->makeCocktail(theMixableRecipebook->getRecipe(1));      //make cocktail
}