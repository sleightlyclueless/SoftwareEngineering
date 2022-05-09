#include "pch.h"

#define protected public
#define private public
/* Needed in top file - include all .cpp files */
#include "../CocktailPro/Waage.cpp"
#include "../CocktailPro/VorhandeneZutaten.cpp"
#include "../CocktailPro/Timer.cpp"
#include "../CocktailPro/Subject.cpp"
#include "../CocktailPro/Stampfer.cpp"
#include "../CocktailPro/Schuettler.cpp"
#include "../CocktailPro/RecipeStep.cpp"
#include "../CocktailPro/RecipeBook.cpp"
#include "../CocktailPro/Recipe.cpp"
#include "../CocktailPro/Mixer.cpp"
#include "../CocktailPro/MischbaresRezeptbuch.cpp"
#include "../CocktailPro/InternalDevice.cpp"
#include "../CocktailPro/Entleerer.cpp"
#include "../CocktailPro/Dosierer.cpp"
#include "../CocktailPro/DeviceVerwalter.cpp"
#include "../CocktailPro/CocktailZubereiter.cpp"
#include "../CocktailPro/CocktailPro.cpp"

#include "../CocktailPro/CocktailPro.h"
#undef protected
#undef private

class CocktailProTest : public ::testing::Test
{
 protected:
  CocktailPro *cp;
  std::basic_streambuf<char> *old_buf;
  std::stringstream ss;

  virtual void SetUp()
  {
      std::string strArg = "-G";            // The string does not matter, because argc is set to 0
      char* arg = &strArg[0];
      cp = new CocktailPro(2, arg);      // Empty args
      old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
  }

  virtual void TearDown()
  {
      std::cout.rdbuf(old_buf); // redirect cout back to standard cout
      delete cp;

  }
};


TEST_F(CocktailProTest, inputHelperString)
{
    std::string cocktail = "?";
    cp->inputHelper(cocktail);
    EXPECT_EQ("?", cp->inputHelper(cocktail));
}

TEST_F(CocktailProTest, inputHelperInt)
{
    std::string cocktail = "52572141";
    cp->inputHelper(cocktail);
    EXPECT_EQ("52572141", cp->inputHelper(cocktail));
}

TEST_F(CocktailProTest, stringToIntHelperValid)
{
    std::string cocktail = "5";
    EXPECT_EQ(5, cp->stringToIntHelper(cocktail));
}

TEST_F(CocktailProTest, stringToIntHelperInvalid)
{
    std::string cocktail = "?";
    EXPECT_EQ(-2, cp->stringToIntHelper(cocktail));
}

TEST_F(CocktailProTest, chooseCocktailExisting)
{
    std::string cocktail = "2";
    EXPECT_EQ(2, cp->chooseCocktail(cocktail));
}

TEST_F(CocktailProTest, chooseCocktailNonExisting)
{
    ss.clear();
    std::string cocktail = "52572141";
    cp->chooseCocktail(cocktail);
    EXPECT_EQ("MEEEP! Too many fingers on keyboard error!",ss.str().substr(ss.str().find("MEEEP! Too many fingers on keyboard error!"), 42));
}

TEST_F(CocktailProTest, chooseCocktailInvalid)
{
    ss.clear();
    std::string cocktail = "?";
    cp->chooseCocktail(cocktail);
    EXPECT_EQ("MEEEP! Too many fingers on keyboard error!",ss.str().substr(ss.str().find("MEEEP! Too many fingers on keyboard error!"), 42));
}

TEST_F(CocktailProTest, start)
{
    ss.clear();
    std::string param = "8";
    cp->start(param);
    EXPECT_EQ("I have received your order: Martini James B",ss.str().substr(ss.str().find("I have received your order: Martini James B"), 43));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(CocktailProTest, demoFunc)
{
    ss.clear();
    cp->demo();
    EXPECT_EQ("I have received your order: Caipirinha",ss.str().substr(ss.str().find("I have received your order: Caipirinha"), 38));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(CocktailProTest, checkSpecialOperators)
{
    CocktailPro *cpCopy = new CocktailPro(*cp);
    // Note: Google Test does not call the class == operator
    bool res = (cpCopy == cp);
    EXPECT_EQ(res, false);
    delete cpCopy;
}

TEST_F(CocktailProTest, endProgramm)
{
    int n = -1;
    EXPECT_EXIT({cp->end(n);},::testing::ExitedWithCode(0),"Device shutting down!");
}