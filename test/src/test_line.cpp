// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/line.h"

TEST(Ply, Line)
{
    auto expected = core::json::object();
    auto actual = ply::Line().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineColor)
{
    core::json expected = {{ "color", "rgb(1,2,3)" }};
    auto actual = ply::Line()(ply::Color().rgb(1,2,3)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineWidth)
{
    core::json expected = {{ "width", 2 }};
    auto actual = ply::Line().width(2).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineSmoothing)
{
    core::json expected = {{ "smoothing", 0.8 }};
    auto actual = ply::Line().smoothing(0.8).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineSimplify)
{
    core::json expected = {{ "simplify", true }};
    auto actual = ply::Line().simplify(true).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineDash)
{
    core::json expected = {{ "dash", as_json(ply::Dash::LongDash) }};
    auto actual = ply::Line()(ply::Dash::LongDash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LineShape)
{
    core::json expected = {{ "shape", as_json(ply::Shape::Spline) }};
    auto actual = ply::Line()(ply::Shape::Spline).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



