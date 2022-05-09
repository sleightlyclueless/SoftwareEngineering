#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/VorhandeneZutaten.h"
#include "../CocktailPro/VorhandeneZutaten.cpp"
#undef protected
#undef private

class VorhandeneZutatenTest : public ::testing::Test
{
protected:
    VorhandeneZutaten *zv;
    std::basic_streambuf<char> *old_buf;
    std::stringstream ss;

    virtual void SetUp()
    {
        old_buf = std::cout.rdbuf(ss.rdbuf()); // redirect cout to stream for testing
        std::string mode = "normal";
        zv = new VorhandeneZutaten(mode);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        std::cout.rdbuf(old_buf); // redirect cout back to standard cout
        delete zv;
    }
};

TEST_F(VorhandeneZutatenTest, getAnzahlVorhandeneZutaten)
{
    EXPECT_EQ(15, zv->getNumberExistingIngredients());
}

TEST_F(VorhandeneZutatenTest, getAnzahlDispensers)
{
    EXPECT_EQ(15, zv->getNumberDispensers());
}

TEST_F(VorhandeneZutatenTest, getNonIngredient)
{
    EXPECT_ANY_THROW(zv->getIngredient(15));
}

TEST_F(VorhandeneZutatenTest, getExistingIngredient)
{
    EXPECT_NO_THROW(zv->getIngredient(14));
}

TEST_F(VorhandeneZutatenTest, FileZutatenDotTxtIsAvailable)
{
    // Test redirects the standard cout to another stream (ss)
    // this stream can be read and compared
    // after the test the normal cout is activated again

    ss.clear();
    std::string mode = "normal";
    zv->readIngredientFile(zv->INGREDIENTS_FILE, mode);
    EXPECT_EQ("Opening Ingredient File ", ss.str().substr(0, 24));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(VorhandeneZutatenTest, FileZutatenDotTxtIsNotAvailable)
{
    // Test asserts that an exception is thrown and that the type of the exception is the one expected
    // https://stackoverflow.com/questions/23270078/test-a-specific-exception-type-is-thrown-and-the-exception-has-the-right-propert
    EXPECT_THROW(
        {
            try
            {
                std::string mode = "normal";
                zv->readIngredientFile("xxxx.txt", mode);
            }
            catch (std::string e)
            {
                std::cout << e << std::endl;
                EXPECT_EQ("File not found: ", e.substr(0, 16));
                throw;
            }
        },
        std::string);
}

TEST_F(VorhandeneZutatenTest, browse)
{
    ss.clear();
    zv->browse();
    EXPECT_EQ("Opening Ingredient File ", ss.str().substr(0, 24));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(VorhandeneZutatenTest, checkSpecialOperators)
{
    VorhandeneZutaten *zvNew = new VorhandeneZutaten(*zv);
    // Note: Google Test does not call the class == operator
    bool res = (zvNew == zv);
    EXPECT_EQ(res, false);
    delete zvNew;
}
