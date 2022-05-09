#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/Entleerer.h"
#include "../CocktailPro/Entleerer.cpp"
#include "../CocktailPro/Waage.h"
#include "../CocktailPro/Waage.cpp"
#undef protected
#undef private

class EntleererTest : public ::testing::Test
{
protected:
    Entleerer *entl;
    Waage sca;
    virtual void SetUp()
    {
        entl = new Entleerer(1.0, 5, &sca);
        entl->myTimer->setTurbo(1000);
    }

    virtual void TearDown()
    {
        delete entl;
    }
};

TEST_F(EntleererTest, ini)
{
    EXPECT_EQ(entl->busy, false);
}

TEST_F(EntleererTest, Entleerer)
{
    EXPECT_EQ(1.0, entl->gramPerTime);
    EXPECT_EQ(5, entl->timeUnit);
    EXPECT_EQ(&sca, entl->myScale);
}

TEST_F(EntleererTest, update)
{
    // Test wouldn't be useful
}

TEST_F(EntleererTest, doIt)
{
    sca.weight = 69;
    entl->doIt(0.0);
    EXPECT_EQ(0, sca.getWeight());
}
