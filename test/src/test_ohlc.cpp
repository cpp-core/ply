// Copyright (C) 2019, 2022 by Mark Melton
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
    json expected = {{ "type", "ohlc" }};
    auto actual = OHLC().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcPlotVisible)
{
    json expected = {{ "type", "ohlc" }, { "visible", false }};
    auto actual = OHLC(PlotVisible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcShowLegend)
{
    json expected = {{ "type", "ohlc" }, { "showlegend", false }};
    auto actual = OHLC().showlegend(false).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcLegendGroup)
{
    json expected = {{ "type", "ohlc" }, { "legendgroup", "abc" }};
    auto actual = OHLC().legendgroup("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcOpacity)
{
    json expected = {{ "type", "ohlc" }, { "opacity", 0.5 }};
    auto actual = OHLC().opacity(0.5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcName)
{
    json expected = {{ "type", "ohlc" }, { "name", "abc" }};
    auto actual = OHLC(Name("abc")).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcX)
{
    json expected = {{ "type", "ohlc" }, { "x", {1, 2, 3, 4} }};
    auto actual = OHLC().x(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcOpen)
{
    json expected = {{ "type", "ohlc" }, { "open", {1, 2, 3, 4} }};
    auto actual = OHLC().open(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcHigh)
{
    json expected = {{ "type", "ohlc" }, { "high", {1, 2, 3, 4} }};
    auto actual = OHLC().high(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcLow)
{
    json expected = {{ "type", "ohlc" }, { "low", {1, 2, 3, 4} }};
    auto actual = OHLC().low(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcClose)
{
    json expected = {{ "type", "ohlc" }, { "close", {1, 2, 3, 4} }};
    auto actual = OHLC().close(std::vector<int>{1, 2, 3, 4}).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcText)
{
    json expected = {{ "type", "ohlc" }, { "text", "abc" }};
    auto actual = OHLC().text("abc").json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcLine)
{
    json expected = {{ "type", "ohlc" }, { "line", {{ "width", 2 }}}};
    auto actual = OHLC(Line().width(2)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, OhlcColor)
{
    json expected = {{ "type", "ohlc" }, { "color", "rgb(1,2,3)" }};
    auto actual = OHLC(Color(RGB(1,2,3))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



