// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/margin.h"

using namespace ply;

TEST(Ply, Margin)
{
    EXPECT_EQ(as_string<Margin>(), "margin");
    
    auto expected = nlj::json::object();
    auto actual = Margin().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginT)
{
    nlj::json expected = {{ "t", 1 }};
    auto actual = Margin().t(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginR)
{
    nlj::json expected = {{ "r", 1 }};
    auto actual = Margin().r(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginB)
{
    nlj::json expected = {{ "b", 1 }};
    auto actual = Margin().b(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginL)
{
    nlj::json expected = {{ "l", 1 }};
    auto actual = Margin().l(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginPad)
{
    nlj::json expected = {{ "pad", {{ "l", 1 }, { "r", 2 }, { "t", 3 }, { "b", 4 }}}};
    auto actual = Margin(Pad().l(1).r(2).t(3).b(4)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginAutoExpand)
{
    nlj::json expected = {{ "autoexpand", true }};
    auto actual = Margin().autoexpand(true).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



