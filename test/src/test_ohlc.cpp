// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/ohlc.h"

using namespace ply;

TEST(Ply, Ohlc)
{
    auto expected = "ohlc";
    auto actual = as_string<OHLC>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, OhlcDefault)
{
    nlj::json expected = {{ "type", "ohlc" }};
    auto actual = OHLC().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcPlotVisible)
{
    nlj::json expected = {{ "type", "ohlc" }, { "visible", false }};
    auto actual = OHLC(PlotVisible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcShowLegend)
{
    nlj::json expected = {{ "type", "ohlc" }, { "showlegend", false }};
    auto actual = OHLC().showlegend(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcLegendGroup)
{
    nlj::json expected = {{ "type", "ohlc" }, { "legendgroup", "abc" }};
    auto actual = OHLC().legendgroup("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcOpacity)
{
    nlj::json expected = {{ "type", "ohlc" }, { "opacity", 0.5 }};
    auto actual = OHLC().opacity(0.5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcName)
{
    nlj::json expected = {{ "type", "ohlc" }, { "name", "abc" }};
    auto actual = OHLC(Name("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcX)
{
    nlj::json expected = {{ "type", "ohlc" }, { "x", {1, 2, 3, 4} }};
    auto actual = OHLC().x(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcOpen)
{
    nlj::json expected = {{ "type", "ohlc" }, { "open", {1, 2, 3, 4} }};
    auto actual = OHLC().open(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcHigh)
{
    nlj::json expected = {{ "type", "ohlc" }, { "high", {1, 2, 3, 4} }};
    auto actual = OHLC().high(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcLow)
{
    nlj::json expected = {{ "type", "ohlc" }, { "low", {1, 2, 3, 4} }};
    auto actual = OHLC().low(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcClose)
{
    nlj::json expected = {{ "type", "ohlc" }, { "close", {1, 2, 3, 4} }};
    auto actual = OHLC().close(ints{1, 2, 3, 4}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcText)
{
    nlj::json expected = {{ "type", "ohlc" }, { "text", "abc" }};
    auto actual = OHLC().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcLine)
{
    nlj::json expected = {{ "type", "ohlc" }, { "line", {{ "width", 2 }}}};
    auto actual = OHLC(Line().width(2)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcColor)
{
    nlj::json expected = {{ "type", "ohlc" }, { "color", "rgb(1,2,3)" }};
    auto actual = OHLC(Color(RGB(1,2,3))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



