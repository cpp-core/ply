// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/scatter3d.h"

using namespace ply;

TEST(Ply, Scatter3d)
{
    auto expected = "scatter3d";
    auto actual = as_string<Scatter3d>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, Scatter3dDefault)
{
    json expected = {{ "type", "scatter3d" }};
    auto actual = Scatter3d().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dPlotVisible)
{
    json expected = {{ "type", "scatter3d" }, { "visible", false }};
    auto actual = Scatter3d(PlotVisible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dShowLegend)
{
    json expected = {{ "type", "scatter3d" }, { "showlegend", false }};
    auto actual = Scatter3d().showlegend(false).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dLegendGroup)
{
    json expected = {{ "type", "scatter3d" }, { "legendgroup", "abc" }};
    auto actual = Scatter3d().legendgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dOpacity)
{
    json expected = {{ "type", "scatter3d" }, { "opacity", 0.5 }};
    auto actual = Scatter3d().opacity(0.5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterMarker)
{
    json expected = {{ "marker", {{ "size", 2 }}}, { "type", "scatter3d" }};
    auto actual = Scatter3d(Marker().size(2)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dName)
{
    json expected = {{ "type", "scatter3d" }, { "name", "abc" }};
    auto actual = Scatter3d(Name("abc")).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dX)
{
    json expected = {{ "type", "scatter3d" }, { "x", {1, 2, 3, 4} }};
    auto actual = Scatter3d().x(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dY)
{
    json expected = {{ "type", "scatter3d" }, { "y", {1, 2, 3, 4} }};
    auto actual = Scatter3d().y(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dZ)
{
    json expected = {{ "type", "scatter3d" }, { "z", {1, 2, 3, 4} }};
    auto actual = Scatter3d().z(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dStackGroup)
{
    json expected = {{ "type", "scatter3d" }, { "stackgroup", "abc" }};
    auto actual = Scatter3d().stackgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dOrientation)
{
    json expected = {{ "type", "scatter3d" }, { "orientation", "v" }};
    auto actual = Scatter3d(Orientation::V).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dGroupNorm)
{
    json expected = {{ "type", "scatter3d" }, { "groupnorm", "percent" }};
    auto actual = Scatter3d(GroupNorm::Percent).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dText)
{
    json expected = {{ "type", "scatter3d" }, { "text", "abc" }};
    auto actual = Scatter3d().text("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dMode)
{
    json expected = {{ "type", "scatter3d" }, { "mode", "markers" }};
    auto actual = Scatter3d(Mode::Markers).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dLine)
{
    json expected = {{ "type", "scatter3d" }, { "line", {{ "width", 2 }}}};
    auto actual = Scatter3d(Line().width(2)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dColor)
{
    json expected = {{ "type", "scatter3d" }, { "color", "rgb(1,2,3)" }};
    auto actual = Scatter3d(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



