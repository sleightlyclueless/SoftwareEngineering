#include "pch.h"

class RecipeTest : public ::testing::Test
{
protected:
    Recipe *r1;

    virtual void SetUp()
    {

        r1 = new Recipe();
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!
        r1->setName("Caipirinha");
        r1->appendStep("Limettenstuecke", 8);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete r1;
    }
};

TEST_F(RecipeTest, getNoOfRecipeSteps)
{
    int noOfSteps = r1->getNoOfRecipeSteps();
    EXPECT_EQ(noOfSteps, 1);
}

TEST_F(RecipeTest, getRecipeStep)
{
    RecipeStep *rStep = r1->getRecipeStep(0);
    EXPECT_EQ(rStep->getIngredient(), "Limettenstuecke");
}

TEST_F(RecipeTest, getName)
{
    EXPECT_EQ(r1->getName(), "Caipirinha");
}

TEST_F(RecipeTest, getRecipeStepNull)
{
    EXPECT_EQ(r1->getRecipeStep(100), nullptr);
}
