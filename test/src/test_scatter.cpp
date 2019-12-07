// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/scatter.h"

using namespace ply;

TEST(Ply, Scatter)
{
    auto expected = "scatter";
    auto actual = as_string<Scatter>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, ScatterDefault)
{
    nlj::json expected = {{ "type", "scatter" }};
    auto actual = Scatter().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterPlotVisible)
{
    nlj::json expected = {{ "type", "scatter" }, { "visible", false }};
    auto actual = Scatter(PlotVisible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterShowLegend)
{
    nlj::json expected = {{ "type", "scatter" }, { "showlegend", false }};
    auto actual = Scatter().showlegend(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterLegendGroup)
{
    nlj::json expected = {{ "type", "scatter" }, { "legendgroup", "abc" }};
    auto actual = Scatter().legendgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterOpacity)
{
    nlj::json expected = {{ "type", "scatter" }, { "opacity", 0.5 }};
    auto actual = Scatter().opacity(0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterName)
{
    nlj::json expected = {{ "type", "scatter" }, { "name", "abc" }};
    auto actual = Scatter(Name("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterX)
{
    nlj::json expected = {{ "type", "scatter" }, { "x", {1, 2, 3, 4} }};
    auto actual = Scatter().x(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterX0)
{
    nlj::json expected = {{ "type", "scatter" }, { "x0", 1 }};
    auto actual = Scatter().x0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterDx)
{
    nlj::json expected = {{ "type", "scatter" }, { "dx", 0.1 }};
    auto actual = Scatter().dx(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterY)
{
    nlj::json expected = {{ "type", "scatter" }, { "y", {1, 2, 3, 4} }};
    auto actual = Scatter().y(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterY0)
{
    nlj::json expected = {{ "type", "scatter" }, { "y0", 1 }};
    auto actual = Scatter().y0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterDy)
{
    nlj::json expected = {{ "type", "scatter" }, { "dy", 0.1 }};
    auto actual = Scatter().dy(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterStackGroup)
{
    nlj::json expected = {{ "type", "scatter" }, { "stackgroup", "abc" }};
    auto actual = Scatter().stackgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterOrientation)
{
    nlj::json expected = {{ "type", "scatter" }, { "orientation", "v" }};
    auto actual = Scatter(Orientation::V).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterGroupNorm)
{
    nlj::json expected = {{ "type", "scatter" }, { "groupnorm", "percent" }};
    auto actual = Scatter(GroupNorm::Percent).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterText)
{
    nlj::json expected = {{ "type", "scatter" }, { "text", "abc" }};
    auto actual = Scatter().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterMode)
{
    nlj::json expected = {{ "type", "scatter" }, { "mode", "markers" }};
    auto actual = Scatter(Mode::Markers).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterLine)
{
    nlj::json expected = {{ "type", "scatter" }, { "line", {{ "width", 2 }}}};
    auto actual = Scatter(Line().width(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterColor)
{
    nlj::json expected = {{ "type", "scatter" }, { "color", "rgb(1,2,3)" }};
    auto actual = Scatter(Color(RGB(1,2,3))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



