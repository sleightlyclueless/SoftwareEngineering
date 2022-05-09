#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/CocktailPro.h"
#include "../CocktailPro/CocktailPro.cpp"
#undef protected
#undef private

class CocktailZubereiterTest : public ::testing::Test
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

TEST_F(CocktailZubereiterTest, makeCocktail)
{
    ss.clear();
    Recipe* rezeptptr = cp->theMixableRecipebook->getRecipe(1);
    cp->theCocktailMaker->makeCocktail(rezeptptr);
    EXPECT_EQ("I have received your order: Caipirinha",ss.str().substr(ss.str().find("I have received your order: Caipirinha"), 38));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}