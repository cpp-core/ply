// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/group_norm.h"

TEST(Ply, GroupNorm)
{
    core::json expected = "groupnorm";
    auto actual = ply::as_string<ply::GroupNorm>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, GroupNormNone)
{
    core::json expected = "";
    auto actual = as_string(ply::GroupNorm::None);
    EXPECT_EQ(actual, expected);
}

TEST(Ply, GroupNormFraction)
{
    core::json expected = "fraction";
    auto actual = as_string(ply::GroupNorm::Fraction);
    EXPECT_EQ(actual, expected);
}

TEST(Ply, GroupNormPercent)
{
    core::json expected = "percent";
    auto actual = as_string(ply::GroupNorm::Percent);
    EXPECT_EQ(actual, expected);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



