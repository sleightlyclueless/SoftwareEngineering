#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/RecipeBook.h"
#undef protected
#undef private

class RecipeBookTest : public ::testing::Test
{
protected:
    RecipeBook *r;

    virtual void SetUp()
    {
        r = new RecipeBook();
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!

        r->m_Recipe.clear();
        Recipe *r1;

        r1 = new Recipe;
        r1->setName("Caipirinha");
        r1->appendStep("Limettenstuecke", 8);
        r->m_Recipe.insert(std::make_pair(1, r1));

        r1 = new Recipe;
        r1->setName("Margarita");
        r1->appendStep("Zitronensaft", 2);
        r->m_Recipe.insert(std::make_pair(1, r1));
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete r;
    }
};

TEST_F(RecipeBookTest, getNumberOfRecipesReturnsValueOfAttribute)
{
    int noOfRecipes = r->m_Recipe.size();
    EXPECT_EQ(noOfRecipes, r->getNumberOfRecipes());
}

TEST_F(RecipeBookTest, getRecipeReturnsCorrectRecipe)
{
    Recipe *rez;
    rez = r->getRecipe(1);
    EXPECT_EQ(rez->getName(), "Caipirinha");
}

TEST_F(RecipeBookTest, deleteRecipeRemovesCorrectRecipe)
{
    EXPECT_FALSE(r->deleteRecipe(-1));
    EXPECT_FALSE(r->deleteRecipe(42));
    EXPECT_TRUE(r->deleteRecipe(1));
    // Since recipe #0 is deleted now Margarita is #0
    EXPECT_EQ(r->getRecipe(1), nullptr);
}

TEST_F(RecipeBookTest, getRecipeNull)
{
    EXPECT_EQ(r->getRecipe(16), nullptr);
}