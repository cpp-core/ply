// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/margin.h"

using namespace ply;

TEST(Ply, Margin)
{
    EXPECT_EQ(as_string<Margin>(), "margin");
    
    auto expected = json::object();
    auto actual = Margin().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginT)
{
    json expected = {{ "t", 1 }};
    auto actual = Margin().t(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginR)
{
    json expected = {{ "r", 1 }};
    auto actual = Margin().r(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginB)
{
    json expected = {{ "b", 1 }};
    auto actual = Margin().b(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginL)
{
    json expected = {{ "l", 1 }};
    auto actual = Margin().l(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginPad)
{
    json expected = {{ "pad", {{ "l", 1 }, { "r", 2 }, { "t", 3 }, { "b", 4 }}}};
    auto actual = Margin(Pad().l(1).r(2).t(3).b(4)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarginAutoExpand)
{
    json expected = {{ "autoexpand", true }};
    auto actual = Margin().autoexpand(true).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



