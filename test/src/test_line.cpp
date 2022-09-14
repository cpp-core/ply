// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/line.h"

using namespace ply;

TEST(Ply, Line)
{
    auto expected = json::object();
    auto actual = Line().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineColor)
{
    json expected = {{ "color", "rgb(1,2,3)" }};
    auto actual = Line(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineWidth)
{
    json expected = {{ "width", 2 }};
    auto actual = Line().width(2).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineSmoothing)
{
    json expected = {{ "smoothing", 0.8 }};
    auto actual = Line().smoothing(0.8).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineSimplify)
{
    json expected = {{ "simplify", true }};
    auto actual = Line().simplify(true).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineDash)
{
    json expected = {{ "dash", as_json(Dash::LongDash) }};
    auto actual = Line(Dash::LongDash).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineShape)
{
    json expected = {{ "shape", as_json(Shape::Spline) }};
    auto actual = Line(Shape::Spline).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



