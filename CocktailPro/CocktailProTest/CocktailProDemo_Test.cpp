#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/CocktailPro.h"
#undef protected
#undef private

class CocktailProDemoTest : public ::testing::Test
{
 protected:
  CocktailPro *cp;
  std::basic_streambuf<char> *old_buf;
  std::stringstream ss;

  virtual void SetUp()
  {
      old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
      std::string strArg = "-D";            // The string does not matter, because argc is set to 0
      char* arg = &strArg[0];
      cp = new CocktailPro(2, arg);      // Empty args
  }

  virtual void TearDown()
  {
      std::cout.rdbuf(old_buf); // redirect cout back to standard cout
      delete cp;

  }
};

TEST_F(CocktailProDemoTest, demoMode)
{
    EXPECT_EQ("I have received your order: Caipirinha",ss.str().substr(ss.str().find("I have received your order: Caipirinha"), 38));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}