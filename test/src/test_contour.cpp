// Copyright (C) 2019, 2021, 2022 by Mark Melton
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
    json expected = {{ "type", "contour" }};
    auto actual = Contour().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourPlotVisible)
{
    json expected = {{ "type", "contour" }, { "visible", false }};
    auto actual = Contour(PlotVisible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourShowLegend)
{
    json expected = {{ "type", "contour" }, { "showlegend", false }};
    auto actual = Contour().showlegend(false).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourLegendGroup)
{
    json expected = {{ "type", "contour" }, { "legendgroup", "abc" }};
    auto actual = Contour().legendgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourOpacity)
{
    json expected = {{ "type", "contour" }, { "opacity", 0.5 }};
    auto actual = Contour().opacity(0.5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourName)
{
    json expected = {{ "type", "contour" }, { "name", "abc" }};
    auto actual = Contour(Name("abc")).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourX)
{
    json expected = {{ "type", "contour" }, { "x", {1, 2, 3, 4} }};
    auto actual = Contour().x(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourX0)
{
    json expected = {{ "type", "contour" }, { "x0", 1 }};
    auto actual = Contour().x0(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourDx)
{
    json expected = {{ "type", "contour" }, { "dx", 0.1 }};
    auto actual = Contour().dx(0.1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourY)
{
    json expected = {{ "type", "contour" }, { "y", {1, 2, 3, 4} }};
    auto actual = Contour().y(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourY0)
{
    json expected = {{ "type", "contour" }, { "y0", 1 }};
    auto actual = Contour().y0(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourDy)
{
    json expected = {{ "type", "contour" }, { "dy", 0.1 }};
    auto actual = Contour().dy(0.1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourZ)
{
    json expected = {{ "type", "contour" }, { "z", {1, 2, 3, 4} }};
    auto actual = Contour().z(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourStackGroup)
{
    json expected = {{ "type", "contour" }, { "stackgroup", "abc" }};
    auto actual = Contour().stackgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourOrientation)
{
    json expected = {{ "type", "contour" }, { "orientation", "v" }};
    auto actual = Contour(Orientation::V).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourGroupNorm)
{
    json expected = {{ "type", "contour" }, { "groupnorm", "percent" }};
    auto actual = Contour(GroupNorm::Percent).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourText)
{
    json expected = {{ "type", "contour" }, { "text", "abc" }};
    auto actual = Contour().text("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourMode)
{
    json expected = {{ "type", "contour" }, { "mode", "markers" }};
    auto actual = Contour(Mode::Markers).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourLine)
{
    json expected = {{ "type", "contour" }, { "line", {{ "width", 2 }}}};
    auto actual = Contour(Line().width(2)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ContourColor)
{
    json expected = {{ "type", "contour" }, { "color", "rgb(1,2,3)" }};
    auto actual = Contour(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



