// Copyright (C) 2019, 2022 by Mark Melton
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
    json expected = {{ "type", "scatter" }};
    auto actual = Scatter().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterPlotVisible)
{
    json expected = {{ "type", "scatter" }, { "visible", false }};
    auto actual = Scatter(PlotVisible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterShowLegend)
{
    json expected = {{ "type", "scatter" }, { "showlegend", false }};
    auto actual = Scatter().showlegend(false).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterLegendGroup)
{
    json expected = {{ "type", "scatter" }, { "legendgroup", "abc" }};
    auto actual = Scatter().legendgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterOpacity)
{
    json expected = {{ "type", "scatter" }, { "opacity", 0.5 }};
    auto actual = Scatter().opacity(0.5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterName)
{
    json expected = {{ "type", "scatter" }, { "name", "abc" }};
    auto actual = Scatter(Name("abc")).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterX)
{
    json expected = {{ "type", "scatter" }, { "x", {1, 2, 3, 4} }};
    auto actual = Scatter().x(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterX0)
{
    json expected = {{ "type", "scatter" }, { "x0", 1 }};
    auto actual = Scatter().x0(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterDx)
{
    json expected = {{ "type", "scatter" }, { "dx", 0.1 }};
    auto actual = Scatter().dx(0.1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterY)
{
    json expected = {{ "type", "scatter" }, { "y", {1, 2, 3, 4} }};
    auto actual = Scatter().y(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterY0)
{
    json expected = {{ "type", "scatter" }, { "y0", 1 }};
    auto actual = Scatter().y0(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterDy)
{
    json expected = {{ "type", "scatter" }, { "dy", 0.1 }};
    auto actual = Scatter().dy(0.1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterStackGroup)
{
    json expected = {{ "type", "scatter" }, { "stackgroup", "abc" }};
    auto actual = Scatter().stackgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterOrientation)
{
    json expected = {{ "type", "scatter" }, { "orientation", "v" }};
    auto actual = Scatter(Orientation::V).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterGroupNorm)
{
    json expected = {{ "type", "scatter" }, { "groupnorm", "percent" }};
    auto actual = Scatter(GroupNorm::Percent).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterText)
{
    json expected = {{ "type", "scatter" }, { "text", "abc" }};
    auto actual = Scatter().text("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterMode)
{
    json expected = {{ "type", "scatter" }, { "mode", "markers" }};
    auto actual = Scatter(Mode::Markers).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterLine)
{
    json expected = {{ "type", "scatter" }, { "line", {{ "width", 2 }}}};
    auto actual = Scatter(Line().width(2)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterColor)
{
    json expected = {{ "type", "scatter" }, { "color", "rgb(1,2,3)" }};
    auto actual = Scatter(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



