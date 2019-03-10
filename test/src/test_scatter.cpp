// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/scatter.h"

TEST(Ply, Scatter)
{
    auto expected = "scatter";
    auto actual = ply::as_string<ply::Scatter>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, ScatterDefault)
{
    core::json expected = {{ "type", "scatter" }};
    auto actual = ply::Scatter().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterVisible)
{
    core::json expected = {{ "type", "scatter" }, { "visible", false }};
    auto actual = ply::Scatter().visible(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterShowLegend)
{
    core::json expected = {{ "type", "scatter" }, { "showlegend", false }};
    auto actual = ply::Scatter().showlegend(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterLegendGroup)
{
    core::json expected = {{ "type", "scatter" }, { "legendgroup", "abc" }};
    auto actual = ply::Scatter().legendgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterOpacity)
{
    core::json expected = {{ "type", "scatter" }, { "opacity", 0.5 }};
    auto actual = ply::Scatter().opacity(0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterName)
{
    core::json expected = {{ "type", "scatter" }, { "name", "abc" }};
    auto actual = ply::Scatter().name("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterX)
{
    core::json expected = {{ "type", "scatter" }, { "x", {1, 2, 3, 4} }};
    auto actual = ply::Scatter().x(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterX0)
{
    core::json expected = {{ "type", "scatter" }, { "x0", 1 }};
    auto actual = ply::Scatter().x0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterDx)
{
    core::json expected = {{ "type", "scatter" }, { "dx", 0.1 }};
    auto actual = ply::Scatter().dx(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterY)
{
    core::json expected = {{ "type", "scatter" }, { "y", {1, 2, 3, 4} }};
    auto actual = ply::Scatter().y(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterY0)
{
    core::json expected = {{ "type", "scatter" }, { "y0", 1 }};
    auto actual = ply::Scatter().y0(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterDy)
{
    core::json expected = {{ "type", "scatter" }, { "dy", 0.1 }};
    auto actual = ply::Scatter().dy(0.1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterStackGroup)
{
    core::json expected = {{ "type", "scatter" }, { "stackgroup", "abc" }};
    auto actual = ply::Scatter().stackgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterOrientation)
{
    core::json expected = {{ "type", "scatter" }, { "orientation", "v" }};
    auto actual = ply::Scatter().set(ply::Orientation::V).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterGroupNorm)
{
    core::json expected = {{ "type", "scatter" }, { "groupnorm", "percent" }};
    auto actual = ply::Scatter().set(ply::GroupNorm::Percent).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterText)
{
    core::json expected = {{ "type", "scatter" }, { "text", "abc" }};
    auto actual = ply::Scatter().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterLine)
{
    core::json expected = {{ "type", "scatter" }, { "line", {{ "width", 2 }}}};
    auto actual = ply::Scatter().set(ply::Line().width(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ScatterColor)
{
    core::json expected = {{ "type", "scatter" }, { "color", "rgb(1,2,3)" }};
    auto actual = ply::Scatter().set(ply::Color().rgb(1,2,3)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



