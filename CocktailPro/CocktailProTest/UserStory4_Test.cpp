#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/CocktailPro.h"
#include "../CocktailPro/CocktailPro.cpp"
#undef protected
#undef private
// USERSTORY: CHECK NUMBERS FOR INGREDIENTS AND THEIR DECREASE OVER USAGE OF COCKTAILS - INCLUDING WARNING AT 10% THRESHOLD
class UserStory4_Test : public ::testing::Test
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

TEST_F(UserStory4_Test, runUserStoryIni)
{
    // Set mode to mexican evening -> double tequila
    std::string file = "zutaten.txt";
    std::string mode = "mexican";
    cp->theIngredientManager->readIngredientFile(file, mode);
    // check 2 Dispensers filled with tequila now
    EXPECT_EQ(cp->theIngredientManager->getIngredient(17), "Tequilla");
    EXPECT_EQ(cp->theIngredientManager->getIngredient(18), "Tequilla");
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}