// Copyright (C) 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/heatmap.h"

using namespace ply;

TEST(Ply, HeatMap)
{
    auto expected = "heatmap";
    auto actual = as_string<HeatMap>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, HeatMapDefault)
{
    nlj::json expected = {{ "type", "heatmap" }};
    auto actual = HeatMap().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapPlotVisible)
{
    nlj::json expected = {{ "type", "heatmap" }, { "visible", false }};
    auto actual = HeatMap(PlotVisible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapShowLegend)
{
    nlj::json expected = {{ "type", "heatmap" }, { "showlegend", false }};
    auto actual = HeatMap().showlegend(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapLegendGroup)
{
    nlj::json expected = {{ "type", "heatmap" }, { "legendgroup", "abc" }};
    auto actual = HeatMap().legendgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapOpacity)
{
    nlj::json expected = {{ "type", "heatmap" }, { "opacity", 0.5 }};
    auto actual = HeatMap().opacity(0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapName)
{
    nlj::json expected = {{ "type", "heatmap" }, { "name", "abc" }};
    auto actual = HeatMap(Name("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapX)
{
    nlj::json expected = {{ "type", "heatmap" }, { "x", {1, 2, 3, 4} }};
    auto actual = HeatMap().x(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapX0)
{
    nlj::json expected = {{ "type", "heatmap" }, { "x0", 1 }};
    auto actual = HeatMap().x0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapDx)
{
    nlj::json expected = {{ "type", "heatmap" }, { "dx", 0.1 }};
    auto actual = HeatMap().dx(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapY)
{
    nlj::json expected = {{ "type", "heatmap" }, { "y", {1, 2, 3, 4} }};
    auto actual = HeatMap().y(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapY0)
{
    nlj::json expected = {{ "type", "heatmap" }, { "y0", 1 }};
    auto actual = HeatMap().y0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapDy)
{
    nlj::json expected = {{ "type", "heatmap" }, { "dy", 0.1 }};
    auto actual = HeatMap().dy(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapZ)
{
    nlj::json expected = {{ "type", "heatmap" }, { "z", {1, 2, 3, 4} }};
    auto actual = HeatMap().z(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapStackGroup)
{
    nlj::json expected = {{ "type", "heatmap" }, { "stackgroup", "abc" }};
    auto actual = HeatMap().stackgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapOrientation)
{
    nlj::json expected = {{ "type", "heatmap" }, { "orientation", "v" }};
    auto actual = HeatMap(Orientation::V).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapGroupNorm)
{
    nlj::json expected = {{ "type", "heatmap" }, { "groupnorm", "percent" }};
    auto actual = HeatMap(GroupNorm::Percent).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapText)
{
    nlj::json expected = {{ "type", "heatmap" }, { "text", "abc" }};
    auto actual = HeatMap().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapMode)
{
    nlj::json expected = {{ "type", "heatmap" }, { "mode", "markers" }};
    auto actual = HeatMap(Mode::Markers).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapLine)
{
    nlj::json expected = {{ "type", "heatmap" }, { "line", {{ "width", 2 }}}};
    auto actual = HeatMap(Line().width(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapColor)
{
    nlj::json expected = {{ "type", "heatmap" }, { "color", "rgb(1,2,3)" }};
    auto actual = HeatMap(Color(RGB(1,2,3))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



