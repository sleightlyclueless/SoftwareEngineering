#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/CocktailPro.h"
#undef protected
#undef private

// USERSTORY: CHECK IF COCKTAIL NUMBERS REMAIN CONSISTENT EVEN IF SOME COCKTAILS FALL AWAY DUE TO UNAVAILABLE INGREDIENTS
class UserStory3_Test : public ::testing::Test
{
protected:
    CocktailPro *cp;
    std::basic_streambuf<char> *old_buf;
    std::stringstream ss;

    virtual void SetUp()
    {
        std::string strArg = "-G";
        char *arg = &strArg[0];
        cp = new CocktailPro(2, arg);         // create cocktailpro object in turbo mode
        old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
    }

    virtual void TearDown()
    {
        std::cout.rdbuf(old_buf); // redirect cout back to standard cout
        delete cp;
    }
};

TEST_F(UserStory3_Test, runUserStoryIni)
{
    ss.clear();
    cp->theIngredientManager->browse(); // VorhandeneZutaten.h browse() -> print all ingredients and their available units
    cp->theMixableRecipebook->browse(); // MischbaresRezeptbuch.h browse() -> print all available cocktails and their selection number

    // Martini remains as number 8, eventhough Daiquiri and Planters Punch are deleted!
    EXPECT_EQ("8.Martini James B: Gin, Wodka, Noilly Prat, Schuetteln",ss.str().substr(ss.str().find("8.Martini James B: Gin, Wodka, Noilly Prat, Schuetteln"), 54));
    Recipe* rezeptptr = cp->theMixableRecipebook->getRecipe(8);
    cp->theCocktailMaker->makeCocktail(rezeptptr);
    EXPECT_EQ("I have received your order: Martini James B",ss.str().substr(ss.str().find("I have received your order: Martini James B"), 43));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(UserStory3_Test, runUserStoryNoLimette)
{
    ss.clear();
    cp->theIngredientManager->setIngredientAmountByIndex(6, 0);
    cp->theMixableRecipebook->updateRecipeBook(cp->theIngredientManager);
    cp->theIngredientManager->browse(); // VorhandeneZutaten.h browse() -> print all ingredients and their available units
    cp->theMixableRecipebook->browse(); // MischbaresRezeptbuch.h browse() -> print all available cocktails and their selection number


    // No Limette = Only 3 recipes out of 8 still active
    // Martini still available with number 8:
    EXPECT_EQ("8.Martini James B: Gin, Wodka, Noilly Prat, Schuetteln",ss.str().substr(ss.str().find("8.Martini James B: Gin, Wodka, Noilly Prat, Schuetteln"), 54));
    Recipe* rezeptptr = cp->theMixableRecipebook->getRecipe(8);
    cp->theCocktailMaker->makeCocktail(rezeptptr);
    EXPECT_EQ("I have received your order: Martini James B",ss.str().substr(ss.str().find("I have received your order: Martini James B"), 43));


    // Caipirinha not available anymore as it requires Limette
    std::size_t pos = ss.str().find("1.Caipirinha: Limettenstuecke, Zucker, Stampfen, Eis, Cachaca, Mischen");
    EXPECT_EQ(pos, std::string::npos);
    std::string param = "1";
    cp->chooseCocktail(param);
    EXPECT_EQ("MEEEP! Too many fingers on keyboard error!",ss.str().substr(ss.str().find("MEEEP! Too many fingers on keyboard error!"), 42));

    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}