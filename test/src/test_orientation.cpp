// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/orientation.h"

TEST(Ply, Orientation)
{
    auto expected = "orientation";
    auto actual = ply::as_string<ply::Orientation>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, OrientationH)
{
    core::json expected = "h";
    auto actual = as_json(ply::Orientation::H);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OrientationV)
{
    core::json expected = "v";
    auto actual = as_json(ply::Orientation::V);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



