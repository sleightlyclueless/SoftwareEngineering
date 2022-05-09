#include "pch.h"

class WaageTest : public ::testing::Test
{
public:
    Waage *w;

    virtual void SetUp()
    {
        w = new Waage();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete w;
    }
};

TEST_F(WaageTest, ini)
{
    EXPECT_EQ(w->weight, 2000);
}

TEST_F(WaageTest, tara)
{
    int taraWeight = w->tara();
    EXPECT_EQ(taraWeight, 0);
}

TEST_F(WaageTest, getWeight)
{
    w->changeWeight(0);
    int weight = w->getWeight();
    EXPECT_EQ(weight, 0);
}

TEST_F(WaageTest, getDelta)
{
    w->changeWeight(0);
    int dWeight = w->getDelta();
    EXPECT_EQ(dWeight, 0);
}

TEST_F(WaageTest, changeWeight)
{
    w->changeWeight(5);
    int dweight = w->getDelta();
    EXPECT_EQ(dweight, 5);
}

TEST_F(WaageTest,changeWeightNegative)
{
    w->changeWeight(-100);
    int weight = w->getWeight();
    EXPECT_EQ(weight,0);
}

TEST_F(WaageTest,changeDeltaNegative)
{
    w->changeWeight(-100);
    int dweight = w->getDelta();
    EXPECT_EQ(dweight,-100);
}
