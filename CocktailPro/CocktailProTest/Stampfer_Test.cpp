#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/Stampfer.h"
#undef protected
#undef private

class StampferTest : public ::testing::Test
{
protected:
    Stampfer *s;

    virtual void SetUp()
    {
        s = new Stampfer();
        s->myTimer->setTurbo(1000);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete s;
    }
};

TEST_F(StampferTest, ini)
{
    EXPECT_EQ(s->busy, false);
}

TEST_F(StampferTest, doIt)
{
    // time point start
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // timer sleep function
    s->doIt(1); // Sleep for 1 * TIME_FACTOR(1000ms);

    // time point end
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // time difference about 50ms (5%) accurate
    EXPECT_NEAR((1 / 1000) * s->TIME_FACTOR, std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(), 100);
}