#include "pch.h"

class RecipeStepTest : public ::testing::Test
{
protected:
    RecipeStep *r;

    virtual void SetUp()
    {
        r = new RecipeStep(); // constructor is short enough to guarantee that m_Ingredient is "" and m_Amount is 0
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete r;
    }
};

TEST_F(RecipeStepTest, getIngredient)
{
    EXPECT_EQ("", r->getIngredient()); // really empty after initialising

    r->m_Ingredient = "bacon";
    EXPECT_EQ("bacon", r->getIngredient());

    r->m_Ingredient = "potato";
    EXPECT_EQ("potato", r->getIngredient());
}

TEST_F(RecipeStepTest, getAmount)
{
    EXPECT_EQ(0, r->getAmount()); // really 0 after initialising

    r->m_Amount = 69;
    EXPECT_EQ(69, r->getAmount());

    r->m_Amount = 420;
    EXPECT_EQ(420, r->getAmount());
}

TEST_F(RecipeStepTest, setIngredient)
{
    r->setIngredient("bacon");
    EXPECT_EQ("bacon", r->m_Ingredient);

    r->setIngredient("potato");
    EXPECT_EQ("potato", r->m_Ingredient);
}

TEST_F(RecipeStepTest, setAmount)
{
    r->setAmount(69);
    EXPECT_EQ(69, r->m_Amount);

    r->setAmount(420);
    EXPECT_EQ(420, r->m_Amount);
}