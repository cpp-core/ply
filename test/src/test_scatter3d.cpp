// Copyright (C) 2019 by Mark Melton
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
    nlj::json expected = {{ "type", "scatter3d" }};
    auto actual = Scatter3d().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dPlotVisible)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "visible", false }};
    auto actual = Scatter3d(PlotVisible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dShowLegend)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "showlegend", false }};
    auto actual = Scatter3d().showlegend(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dLegendGroup)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "legendgroup", "abc" }};
    auto actual = Scatter3d().legendgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dOpacity)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "opacity", 0.5 }};
    auto actual = Scatter3d().opacity(0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterMarker)
{
    nlj::json expected = {{ "marker", {{ "size", 2 }}}, { "type", "scatter3d" }};
    auto actual = Scatter3d(Marker().size(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dName)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "name", "abc" }};
    auto actual = Scatter3d(Name("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dX)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "x", {1, 2, 3, 4} }};
    auto actual = Scatter3d().x(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dY)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "y", {1, 2, 3, 4} }};
    auto actual = Scatter3d().y(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dZ)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "z", {1, 2, 3, 4} }};
    auto actual = Scatter3d().z(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dStackGroup)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "stackgroup", "abc" }};
    auto actual = Scatter3d().stackgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dOrientation)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "orientation", "v" }};
    auto actual = Scatter3d(Orientation::V).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dGroupNorm)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "groupnorm", "percent" }};
    auto actual = Scatter3d(GroupNorm::Percent).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dText)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "text", "abc" }};
    auto actual = Scatter3d().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dMode)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "mode", "markers" }};
    auto actual = Scatter3d(Mode::Markers).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dLine)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "line", {{ "width", 2 }}}};
    auto actual = Scatter3d(Line().width(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, Scatter3dColor)
{
    nlj::json expected = {{ "type", "scatter3d" }, { "color", "rgb(1,2,3)" }};
    auto actual = Scatter3d(Color(RGB(1,2,3))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



