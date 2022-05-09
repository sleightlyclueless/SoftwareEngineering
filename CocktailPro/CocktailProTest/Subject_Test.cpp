#include "pch.h"

class SubjectTest : public ::testing::Test
{
protected:
    Subject *s;
    Waage *w;
    Dosierer *d;

    virtual void SetUp()
    {
        s = new Subject();
    }

    virtual void TearDown()
    {
        // Code here will be called immediately after each test
        // (right before the destructor).
        delete w;
        delete d;
        delete s;
    }
};

TEST_F(SubjectTest, attach)
{

    w = new Waage();
    d = new Dosierer(1, 250, "Wodka", w);
    s->attach(d);

    EXPECT_EQ(s->observers.size(), 1);
}
