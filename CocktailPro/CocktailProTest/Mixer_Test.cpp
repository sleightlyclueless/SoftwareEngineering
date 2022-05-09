#include "pch.h"

class MixerTest : public ::testing::Test
{
protected:
    Mixer *m;

    virtual void SetUp()
    {
        m = new Mixer();
        m->myTimer->setTurbo(1000);
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete m;
    }
};

TEST_F(MixerTest, ini)
{
    EXPECT_EQ(m->busy, false);
}

TEST_F(MixerTest, doIt)
{
    // time point start
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // timer sleep function
    m->doIt(1); // Sleep for 1 * SLEEP_TIME (1000ms);

    // time point end
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // time difference about 50ms (5%) accurate
    EXPECT_NEAR((1 / 1000) * m->SLEEP_TIME, std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(), 100);
}