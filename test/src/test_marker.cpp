// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/marker.h"

using namespace ply;

TEST(Ply, Marker)
{
    auto expected = json::object();
    auto actual = Marker().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarkerColor)
{
    json expected = {{ "color", "rgb(1,2,3)" }};
    auto actual = Marker(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarkerCircle)
{
    json expected = {{ "symbol", as_json(Symbol::Circle) }};
    auto actual = Marker(Symbol::Circle).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, MarkerSize)
{
    json expected = {{ "size", 2 }};
    auto actual = Marker().size(2).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



