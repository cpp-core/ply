// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/margin.h"

using namespace ply;

TEST(Ply, Margin)
{
    EXPECT_EQ(as_string<Margin>(), "margin");
    
    auto expected = core::json::object();
    auto actual = Margin().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginT)
{
    core::json expected = {{ "t", 1 }};
    auto actual = Margin().t(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginR)
{
    core::json expected = {{ "r", 1 }};
    auto actual = Margin().r(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginB)
{
    core::json expected = {{ "b", 1 }};
    auto actual = Margin().b(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginL)
{
    core::json expected = {{ "l", 1 }};
    auto actual = Margin().l(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginPad)
{
    core::json expected = {{ "pad", {{ "l", 1 }, { "r", 2 }, { "t", 3 }, { "b", 4 }}}};
    auto actual = Margin(Pad().l(1).r(2).t(3).b(4)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginAutoExpand)
{
    core::json expected = {{ "autoexpand", true }};
    auto actual = Margin().autoexpand(true).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



