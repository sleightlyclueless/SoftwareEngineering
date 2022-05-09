//@(#) VorhandeneZutaten.cpp

#include "VorhandeneZutaten.h"
//

VorhandeneZutaten::VorhandeneZutaten(std::string &mode)
{
    ingredients = new std::multimap<std::string, int>; // Initialize ingredients with map
    readIngredientFile(INGREDIENTS_FILE, mode);

    ingredients->insert(std::make_pair("mixing", -1));
    ingredients->insert(std::make_pair("crushing", -1));
    numberDispensers = ingredients->size();
}

// Copy constructor - assign parameters
VorhandeneZutaten::VorhandeneZutaten(const VorhandeneZutaten &copyConstructorExistingIngredients)
{

    ingredients = new std::multimap<std::string, int>; // Initialize ingredients with map

    std::map<std::string, int>::iterator it;
    for(it=copyConstructorExistingIngredients.ingredients->begin(); it != copyConstructorExistingIngredients.ingredients->end(); ++it)
    {
        ingredients->insert(std::make_pair(it->first, it->second));
    }
    numberDispensers = ingredients->size();
}

VorhandeneZutaten::~VorhandeneZutaten(void){}

void VorhandeneZutaten::readIngredientFile(std::string myFile, std::string &mode)
{
    std::ifstream in; // Create filestream
    FileName = myFile;
    in.open(FileName.c_str(), std::ios::in); // c_str converts string to char[]

    if (!in)
    { // file could not be opened
        std::string my_exception = "File not found: " + FileName;
        std::cout << my_exception << std::endl;
        throw my_exception;
    }
    std::cout << "Opening Ingredient File " << FileName << std::endl;
    std::string line;
    while (getline(in, line))
    {
        // Cut trailing \r - to make Linux or Windows Files equal
        if (line.size() && line[line.size() - 1] == '\r') // Loop over one line, done when reading a \r
            line = line.substr(0, line.size() - 1); // add current char to line.

        // fill ingredients
        this->ingredients->insert(std::make_pair(line, DEFAULT_MEASUREMENT));
    }
    // Add another bottle of tequila for mexican evening instead of noilly prat
    if (mode == "mexican")
    {
        this->ingredients->insert(std::make_pair("Tequilla", DEFAULT_MEASUREMENT));
        this->ingredients->erase("Noilly Prat");
    }
    in.close(); // Cleanup, close fstream
}

void VorhandeneZutaten::browse(void)
{
    std::map<std::string, int>::iterator it;

    std::cout << "*********** Available ingredients (units): ***********" << std::endl;
    for(it=ingredients->begin(); it != ingredients->end(); ++it)
    {
        if (it->first != "crushing" && it->first != "mixing")
        {
            std::cout << it->first << " (" << it->second << ")" << std::endl;
        }
    }
    std::cout << "**********************************************************" << std::endl;
}

std::string VorhandeneZutaten::getIngredient(int i)
{
    //std::multimap<std::string, int>::iterator it;
    int j = 0;
    for(auto it = ingredients->begin(); it != ingredients->end(); ++it)
    {
        if (j == i)
        {
            return it->first;
        }
        j++;
    }

    throw std::runtime_error("Ingredient index out of bounds!");

}

int VorhandeneZutaten::getIngredientAmountByIndex(int i)
{
    int j = 0;
    for(auto it = ingredients->begin(); it != ingredients->end(); ++it)
    {
        if (j == i)
        {
            return it->second;
        }
        j++;
    }
    throw std::runtime_error("Ingredient index out of bounds!");
}

int VorhandeneZutaten::getIngredientAmount(std::string str) // Suche nach zutat und returne anzahl / Füllstand
{
    int retVal = -2;
    if (ingredients->find(str) != ingredients->end())
    {
        retVal = ingredients->find(str)->second;
    }


    return retVal;
}

void VorhandeneZutaten::setIngredientAmountByIndex(int i, int amount)
{
    int j = 0;
    for(auto it = ingredients->begin(); it != ingredients->end(); ++it)
    {
        if (j == i)
        {
            it->second = amount;
            return;
        }
        j++;
    }
}

int VorhandeneZutaten::getNumberExistingIngredients()
{
    return ingredients->size(); // Return number of elements in ingredients list as count of available ingredients
}

int VorhandeneZutaten::getNumberDispensers()
{
    return numberDispensers; // Return number of dispensers
}
