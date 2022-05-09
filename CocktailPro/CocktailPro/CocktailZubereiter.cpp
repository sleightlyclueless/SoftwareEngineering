//@(#) CocktailZubereiter.cpp


#include "CocktailZubereiter.h"

CocktailZubereiter::CocktailZubereiter(DeviceVerwalter* dm)
{
    myDeviceManager=dm;
    myIngredientManager=nullptr;
}

bool CocktailZubereiter::makeCocktail(Recipe* rzpt)
{
    std::cout<<"Hello, I am the CocktailMaker!"<<std::endl                          //cringe startmessage
             <<"I have received your order: "<<rzpt->getName()<<std::endl
             <<"Cocktail making process starts now!\n"<<std::endl;

    std::vector<std::map<std::string, InternalDevice*>::iterator> devicesUsed; // store the used devices to clean later

    for(int i=0; i<rzpt->getNoOfRecipeSteps(); ++i)
    {
        RecipeStep* step=rzpt->getRecipeStep(i);    //fetches each step of a recipe
        std::string ingredient = step->getIngredient();  //fetches the ingredient for each step
        int amount = step->getAmount();            //fetches the amount of said ingredient
        std::cout << "Recipe Step: "<<ingredient<<", "<< amount<<std::endl;
        std::map<std::string, InternalDevice*>::iterator deviceUsed = myDeviceManager->makeRecipeStep(ingredient, amount);       //the device manager fills the dispenser with said amount of said ingredient
        devicesUsed.push_back(deviceUsed); // Append the last used device to the vector
        upDateIngredientAmount(ingredient, amount);

    }
    myDeviceManager->myDrainer->doIt(rzpt->getNoOfRecipeSteps());   //the ingredient dispensers are emptied and need the number of recipe steps for some reason

    //for(std::map<std::string, InternalDevice*>::iterator device=myDeviceManager->myDevices->begin(); device!=myDeviceManager->myDevices->end(); ++device)
    for(int i = 0; i < (int)devicesUsed.size(); ++i)
    {    // the devices are cleaned in numerical order

        std::cout<<"Device: "<<devicesUsed[i]->first<<" is getting cleaned! "<<std::endl;
        devicesUsed[i]->second->clean();
    }
    return (true);    //leave the function after successful go-through
}

void CocktailZubereiter::upDateIngredientAmount(std::string &ingredient, int amount)
{
    amount = setIngredientAmount(ingredient, amount);

    if (myIngredientManager->getIngredientAmount(ingredient) > -1) // check if not special ingredient
    {
        for(int i = 0; i < myIngredientManager->getNumberExistingIngredients(); i++) // Loop all ingredients
        {
            std::string _key = myIngredientManager->getIngredient(i);
            if(_key == ingredient && myIngredientManager->getIngredientAmountByIndex(i) >= amount)
            {
                myIngredientManager->setIngredientAmountByIndex(i, myIngredientManager->getIngredientAmountByIndex(i) - amount);
                break;
            }
        }
    }
}

int CocktailZubereiter::setIngredientAmount(const std::string &ingredient, int &amount) const {
    if (ingredient == "Limettenstuecke")
    {
        // limettes in 10g steps
        amount = amount * 10;
    }
    else if (ingredient == "Eis" && amount % 20 != 0)
    {
        // funktionierte nur bei den geraden mengen bisher. Ersetzen durch:
        // only in 20g steps possible
        // amount = amount + 10 ;
        while (amount % 20 != 0)
        {
            amount++;
        }
    }
    else if (ingredient != "Zucker")
    {
        // cl for liquids into ml
        amount = amount*10;
    }
    return amount;
}

void CocktailZubereiter::setIngredientManager(VorhandeneZutaten* zv)
{
    myIngredientManager = zv;
}