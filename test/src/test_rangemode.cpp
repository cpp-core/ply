// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/enum.h"

TEST(Ply, RangeMode)
{
    auto expected = "rangemode";
    auto actual = ply::as_string<ply::RangeMode>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, RangeModeNormal)
{
    core::json expected = "normal";
    auto actual = as_json(ply::RangeMode::Normal);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeModeToZero)
{
    core::json expected = "tozero";
    auto actual = as_json(ply::RangeMode::ToZero);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeModeNonNegative)
{
    core::json expected = "nonnegative";
    auto actual = as_json(ply::RangeMode::NonNegative);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



