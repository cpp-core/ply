// Copyright (C) 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/contour.h"

using namespace ply;

TEST(Ply, Contour)
{
    auto expected = "contour";
    auto actual = as_string<Contour>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, ContourDefault)
{
    nlj::json expected = {{ "type", "contour" }};
    auto actual = Contour().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourPlotVisible)
{
    nlj::json expected = {{ "type", "contour" }, { "visible", false }};
    auto actual = Contour(PlotVisible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourShowLegend)
{
    nlj::json expected = {{ "type", "contour" }, { "showlegend", false }};
    auto actual = Contour().showlegend(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourLegendGroup)
{
    nlj::json expected = {{ "type", "contour" }, { "legendgroup", "abc" }};
    auto actual = Contour().legendgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourOpacity)
{
    nlj::json expected = {{ "type", "contour" }, { "opacity", 0.5 }};
    auto actual = Contour().opacity(0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourName)
{
    nlj::json expected = {{ "type", "contour" }, { "name", "abc" }};
    auto actual = Contour(Name("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourX)
{
    nlj::json expected = {{ "type", "contour" }, { "x", {1, 2, 3, 4} }};
    auto actual = Contour().x(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourX0)
{
    nlj::json expected = {{ "type", "contour" }, { "x0", 1 }};
    auto actual = Contour().x0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourDx)
{
    nlj::json expected = {{ "type", "contour" }, { "dx", 0.1 }};
    auto actual = Contour().dx(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourY)
{
    nlj::json expected = {{ "type", "contour" }, { "y", {1, 2, 3, 4} }};
    auto actual = Contour().y(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourY0)
{
    nlj::json expected = {{ "type", "contour" }, { "y0", 1 }};
    auto actual = Contour().y0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourDy)
{
    nlj::json expected = {{ "type", "contour" }, { "dy", 0.1 }};
    auto actual = Contour().dy(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourZ)
{
    nlj::json expected = {{ "type", "contour" }, { "z", {1, 2, 3, 4} }};
    auto actual = Contour().z(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourStackGroup)
{
    nlj::json expected = {{ "type", "contour" }, { "stackgroup", "abc" }};
    auto actual = Contour().stackgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourOrientation)
{
    nlj::json expected = {{ "type", "contour" }, { "orientation", "v" }};
    auto actual = Contour(Orientation::V).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourGroupNorm)
{
    nlj::json expected = {{ "type", "contour" }, { "groupnorm", "percent" }};
    auto actual = Contour(GroupNorm::Percent).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourText)
{
    nlj::json expected = {{ "type", "contour" }, { "text", "abc" }};
    auto actual = Contour().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourMode)
{
    nlj::json expected = {{ "type", "contour" }, { "mode", "markers" }};
    auto actual = Contour(Mode::Markers).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourLine)
{
    nlj::json expected = {{ "type", "contour" }, { "line", {{ "width", 2 }}}};
    auto actual = Contour(Line().width(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourColor)
{
    nlj::json expected = {{ "type", "contour" }, { "color", "rgb(1,2,3)" }};
    auto actual = Contour(Color(RGB(1,2,3))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



