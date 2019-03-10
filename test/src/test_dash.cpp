// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/dash.h"

TEST(Ply, Dash)
{
    auto expected = "dash";
    auto actual = ply::as_string<ply::Dash>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, DashSolid)
{
    core::json expected = "solid";
    auto actual = as_json(ply::Dash::Solid);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, DashDot)
{
    core::json expected = "dot";
    auto actual = as_json(ply::Dash::Dot);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, DashDash)
{
    core::json expected = "dash";
    auto actual = as_json(ply::Dash::Dash);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, DashLongDash)
{
    core::json expected = "longdash";
    auto actual = as_json(ply::Dash::LongDash);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, DashDashDot)
{
    core::json expected = "dashdot";
    auto actual = as_json(ply::Dash::DashDot);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, DashLongDashDot)
{
    core::json expected = "longdashdot";
    auto actual = as_json(ply::Dash::LongDashDot);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



