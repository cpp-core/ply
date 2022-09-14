// Copyright (C) 2019, 2021, 2022 by Mark Melton
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
    json expected = {{ "type", "heatmap" }};
    auto actual = HeatMap().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapPlotVisible)
{
    json expected = {{ "type", "heatmap" }, { "visible", false }};
    auto actual = HeatMap(PlotVisible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapShowLegend)
{
    json expected = {{ "type", "heatmap" }, { "showlegend", false }};
    auto actual = HeatMap().showlegend(false).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapLegendGroup)
{
    json expected = {{ "type", "heatmap" }, { "legendgroup", "abc" }};
    auto actual = HeatMap().legendgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapOpacity)
{
    json expected = {{ "type", "heatmap" }, { "opacity", 0.5 }};
    auto actual = HeatMap().opacity(0.5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapName)
{
    json expected = {{ "type", "heatmap" }, { "name", "abc" }};
    auto actual = HeatMap(Name("abc")).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapX)
{
    json expected = {{ "type", "heatmap" }, { "x", {1, 2, 3, 4} }};
    auto actual = HeatMap().x(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapX0)
{
    json expected = {{ "type", "heatmap" }, { "x0", 1 }};
    auto actual = HeatMap().x0(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapDx)
{
    json expected = {{ "type", "heatmap" }, { "dx", 0.1 }};
    auto actual = HeatMap().dx(0.1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapY)
{
    json expected = {{ "type", "heatmap" }, { "y", {1, 2, 3, 4} }};
    auto actual = HeatMap().y(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapY0)
{
    json expected = {{ "type", "heatmap" }, { "y0", 1 }};
    auto actual = HeatMap().y0(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapDy)
{
    json expected = {{ "type", "heatmap" }, { "dy", 0.1 }};
    auto actual = HeatMap().dy(0.1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapZ)
{
    json expected = {{ "type", "heatmap" }, { "z", {1, 2, 3, 4} }};
    auto actual = HeatMap().z(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapStackGroup)
{
    json expected = {{ "type", "heatmap" }, { "stackgroup", "abc" }};
    auto actual = HeatMap().stackgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapOrientation)
{
    json expected = {{ "type", "heatmap" }, { "orientation", "v" }};
    auto actual = HeatMap(Orientation::V).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapGroupNorm)
{
    json expected = {{ "type", "heatmap" }, { "groupnorm", "percent" }};
    auto actual = HeatMap(GroupNorm::Percent).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapText)
{
    json expected = {{ "type", "heatmap" }, { "text", "abc" }};
    auto actual = HeatMap().text("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapMode)
{
    json expected = {{ "type", "heatmap" }, { "mode", "markers" }};
    auto actual = HeatMap(Mode::Markers).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapLine)
{
    json expected = {{ "type", "heatmap" }, { "line", {{ "width", 2 }}}};
    auto actual = HeatMap(Line().width(2)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, HeatMapColor)
{
    json expected = {{ "type", "heatmap" }, { "color", "rgb(1,2,3)" }};
    auto actual = HeatMap(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



