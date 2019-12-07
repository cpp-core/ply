// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/color.h"

TEST(Ply, Color)
{
    auto expected = nlj::json::object();
    auto actual = ply::Color().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ColorRgb)
{
    nlj::json expected = "rgb(1,2,3)";
    auto actual = ply::Color().rgb(1,2,3).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ColorRgba)
{
    nlj::json expected = "rgba(1,2,3,0.5)";
    auto actual = ply::Color().rgba(1,2,3,0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



