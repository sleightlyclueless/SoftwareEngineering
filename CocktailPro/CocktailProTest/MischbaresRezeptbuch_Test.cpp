#include "pch.h"

class MischbaresRezeptbuchTest : public ::testing::Test
{
protected:
    CocktailZubereiter *c;
    MischbaresRezeptbuch *m;
    VorhandeneZutaten *z;
    virtual void SetUp()
    {
        std::string mode = "normal";
        z = new VorhandeneZutaten(mode);
        m = new MischbaresRezeptbuch(z);
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete m;
        delete z;
    }
};

TEST_F(MischbaresRezeptbuchTest, checkIngredientExistsTrue)
{
    bool retVal = m->checkIngredientExists("Wodka");
    EXPECT_EQ(retVal, true);
}

TEST_F(MischbaresRezeptbuchTest, checkIngredientExistsFalse)
{
    bool retVal = m->checkIngredientExists("Kartoffel");
    EXPECT_EQ(retVal, false);
}

TEST_F(MischbaresRezeptbuchTest, checkForSpecialIngredientTrue)
{
    EXPECT_EQ(m->checkForSpecialIngredient("Stampfen"), true);
}

TEST_F(MischbaresRezeptbuchTest, checkForSpecialIngredientFalse)
{
    EXPECT_EQ(m->checkForSpecialIngredient("Raeuchern"), false);
}

TEST_F(MischbaresRezeptbuchTest, checkIngredientAmount)
{
    Recipe *r = m->getRecipe(1);
    int j = 1;
    std::string ingredient = "Limettenstuecke";
    EXPECT_EQ(m->checkIngredientAmount(z, r, j, ingredient), true);
}

TEST_F(MischbaresRezeptbuchTest, checkIngredientAmountLow)
{
    z->setIngredientAmountByIndex(6, 10);
    m->updateRecipeBook(z);

    Recipe *r = m->getRecipe(1);
    int j = 1;
    std::string ingredient = "Limettenstuecke";
    EXPECT_EQ(m->checkIngredientAmount(z, r, j, ingredient), false);
}

TEST_F(MischbaresRezeptbuchTest, checkIngredientAmountTooLow)
{
    z->setIngredientAmountByIndex(6, 0);

    Recipe *r = m->getRecipe(1);
    int j = 1;
    std::string ingredient = "Limettenstuecke";
    EXPECT_EQ(m->checkIngredientAmount(z, r, j, ingredient), false);
}