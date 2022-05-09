#include "pch.h"

#define protected public
#define private public
#include "../CocktailPro/InternalDevice.h"
#include "../CocktailPro/InternalDevice.cpp"
#include "../CocktailPro/Entleerer.h"
#include "../CocktailPro/Entleerer.cpp"
#include "../CocktailPro/Waage.h"
#include "../CocktailPro/Waage.cpp"
#undef protected
#undef private

class InternalDeviceTest : public ::testing::Test
{
protected:
    InternalDevice *i;
    Entleerer *entl;
    Waage sca;
    std::basic_streambuf<char> *old_buf;
    std::stringstream ss;

    virtual void SetUp()
    {
        // redirect cout to stream for testing...
        old_buf = std::cout.rdbuf(ss.rdbuf());
        // Inherits function clean() from InternalDevice as an InternalDevice...
        entl = new Entleerer(1.0, 5, &sca);
        entl->myTimer->setTurbo(1000);
    }

    virtual void TearDown()
    {
        // redirect cout back to standard cout
        std::cout.rdbuf(old_buf);
        delete entl;
    }
};

TEST_F(InternalDeviceTest, clean)
{
    ss.clear();
    entl->clean();
    EXPECT_EQ("Cleaning...", ss.str().substr(0, 11));
    std::cout.rdbuf(old_buf); // redirect cout back to standard cout
}