// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/color.h"

TEST(Ply, Color)
{
    auto expected = json::object();
    auto actual = ply::Color().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ColorRgb)
{
    json expected = "rgb(1,2,3)";
    auto actual = ply::Color().rgb(1,2,3).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ColorRgba)
{
    json expected = "rgba(1,2,3,0.5)";
    auto actual = ply::Color().rgba(1,2,3,0.5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



