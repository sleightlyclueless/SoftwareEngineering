#include "pch.h"

class DeviceVerwalterTest : public ::testing::Test
{
protected:
    Stampfer *s;
    VorhandeneZutaten *zv;
    DeviceVerwalter *d;
    std::basic_streambuf<char> *old_buf;
    std::stringstream ss;

    virtual void SetUp()
    {
        // redirect cout to stream for testing...
        old_buf = std::cout.rdbuf(ss.rdbuf());

        s = new Stampfer();
        s->myTimer->setTurbo(1000);
        std::string mode = "normal";
        zv = new VorhandeneZutaten(mode);
        d = new DeviceVerwalter(zv);
    }

    virtual void TearDown()
    {
        // redirect cout back to standard cout
        std::cout.rdbuf(old_buf);
        delete s;
        delete zv;
        delete d;
    }
};

TEST_F(DeviceVerwalterTest, createDevices)
{
    d->myDevices->insert(std::make_pair("Stampfen", s));

    // time point start
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    // timer sleep function
    d->myDevices->at("Stampfen")->doIt(1);

    // time point end
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    // time difference about 100ms (10%) accurate
    // 1000 = TIME_FACTOR of InternalDevice Stampfer
    EXPECT_NEAR((1), std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count(), 100); // Sleep for 1 * TIME_FACTOR(1000ms)
}

TEST_F(DeviceVerwalterTest, setIngredientManager)
{
    d->setIngredientManager(zv);
    EXPECT_EQ(d->myIngredientManager, zv);
}

TEST_F(DeviceVerwalterTest, makeRecipeStep)
{
    d->makeRecipeStep("Limettenstuecke", 1);
    ss.clear();
    d->myDevices->at("Limettenstuecke")->doIt(1); // Measure by time

    EXPECT_EQ("Limettenstuecke Valve has been opened", ss.str().substr(ss.str().find("Limettenstuecke Valve has been opened"), 37));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}

TEST_F(DeviceVerwalterTest, makeRecipeStepWithWait)
{
    d->makeRecipeStep("Wodka", 1);
    ss.clear();
    d->myDevices->at("Wodka")->doIt(1); // Measure by time

    EXPECT_EQ("Wodka Valve has been opened", ss.str().substr(ss.str().find("Wodka Valve has been opened"), 27));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}