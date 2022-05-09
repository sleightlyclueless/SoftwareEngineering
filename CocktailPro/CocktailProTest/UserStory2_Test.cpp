#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/CocktailPro.h"
#include "../CocktailPro/CocktailPro.cpp"
#undef protected
#undef private

// USERSTORY: CHECK NUMBERS FOR INGREDIENTS AND THEIR DECREASE OVER USAGE OF COCKTAILS - INCLUDING WARNING AT 10% THRESHOLD
class UserStory2_Test : public ::testing::Test
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

TEST_F(UserStory2_Test, runUserStoryIni)
{
// Check some default parameters if all ingredients full on initial startup
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Limettenstuecke"), 1000);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Zucker"), 1000);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Wodka"), 1000);
std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(UserStory2_Test, runUserStoryIngredientNotExisting)
{
// Check some default parameters if all ingredients full on initial startup
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Gibtsdochgarnicht"), -2);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("mixing"), -1);
std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(UserStory2_Test, runUserStoryDecreasing)
{
ss.clear();
//check initial amounts
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Limettenstuecke"), 1000);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Zucker"), 1000);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Eis"), 1000);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Cachaca"), 1000);

// Make an Caipirinha (Limettenstuecke (8), Zucker (15), Stampfen, Eis (90), Cachaca (5), Mischen)
Recipe* rezeptptr = cp->theMixableRecipebook->getRecipe(1);
cp->theCocktailMaker->makeCocktail(rezeptptr);
EXPECT_EQ("I have received your order: Caipirinha",ss.str().substr(ss.str().find("I have received your order: Caipirinha"), 38));

// Check amount decreasage
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Limettenstuecke"), 920);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Zucker"), 985);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Eis"), 900);
EXPECT_EQ(cp->theIngredientManager->getIngredientAmount("Cachaca"), 950); // *10ml because of cup dosage

}

TEST_F(UserStory2_Test, runUserStoryWarning)
{
ss.clear();
cp->theIngredientManager->setIngredientAmountByIndex(6, 11);
cp->theMixableRecipebook->updateRecipeBook(cp->theIngredientManager);
cp->theIngredientManager->browse(); // VorhandeneZutaten.h browse() -> print all ingredients and their available units
cp->theMixableRecipebook->browse(); // MischbaresRezeptbuch.h browse() -> print all available cocktails and their selection number

// Make an Caipirinha (Limettenstuecke (8), Zucker (15), Stampfen, Eis (90), Cachaca (5), Mischen) -> Falling below 10 of 100 Limette
std::string param = "1";
cp->start(param);
EXPECT_EQ("WARNING: Limettenstuecke ALMOST EMPTY!",ss.str().substr(ss.str().find("WARNING: Limettenstuecke ALMOST EMPTY!"), 38));

std::cout.rdbuf(old_buf); // redirect cout back to standard cout

}