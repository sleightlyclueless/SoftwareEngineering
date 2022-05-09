#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/Timer.h"
#include "../CocktailPro/Timer.cpp"
#undef protected
#undef private

class TimerTest : public ::testing::Test
{
protected:
    Timer *t;

    virtual void SetUp()
    {
        t = new Timer();
        t->setTurbo(1000);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        t->setTurbo(1);
        delete t;
    }
};

TEST_F(TimerTest, sleep)
{
    // time point start
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // timer sleep function
    t->sleep(1000); // Sleep for 1000ms;

    // time point end
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // time difference about 50ms (5%) accurate
    EXPECT_NEAR(1000 / 1000, std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(), 100);
}

TEST_F(TimerTest, sleepInIntervals)
{
    // time point start
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // timer sleep function
    t->sleepInIntervals(1000); // Sleep for 1000ms;

    // time point end
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // time difference about 50ms (5%) accurate
    EXPECT_NEAR(1000 / 1000, std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(), 100);
}

// Check if instance var gets changed to true if we create an instance
TEST_F(TimerTest, getInstance)
{
    t->getInstance();
    EXPECT_EQ(t->instanceFlag, true);
}

// Check if turbo is set correctly
TEST_F(TimerTest, setTurbo)
{
    t->setTurbo(2000);
    EXPECT_EQ(t->booster, 2000);
}
