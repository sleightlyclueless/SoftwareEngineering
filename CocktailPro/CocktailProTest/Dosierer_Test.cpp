#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/Dosierer.h"
#undef protected
#undef private

class DosiererTest : public ::testing::Test
{
protected:
    Dosierer *d;
    Waage *w;

    virtual void SetUp()
    {
        w = new Waage();
        d = new Dosierer(1, 250, "Wodka", w);
        d->myTimer->setTurbo(1000);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete w;
        delete d;
    }
};

TEST_F(DosiererTest, ini)
{
    EXPECT_EQ(d->busy, false);
}

TEST_F(DosiererTest, update)
{
    d->update();
    EXPECT_EQ(d->busy, false);
}

TEST_F(DosiererTest, doIt)
{
    d->doIt(50.0);
    EXPECT_EQ(50.0, w->getDelta());
}

TEST_F(DosiererTest, getPieceProTime)
{
    EXPECT_EQ(d->getPieceProTime(), 1);
}
