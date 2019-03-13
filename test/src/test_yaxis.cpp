// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/yaxis.h"

using namespace ply;

TEST(Ply, YAxis)
{
    EXPECT_EQ(as_string<YAxis>(), "yaxis");
    
    auto expected = core::json::object();
    auto actual = YAxis().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisVisible)
{
    core::json expected = {{ "visible", false }};
    auto actual = YAxis().visible(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisColor)
{
    core::json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = YAxis()(Color().rgb(32,64,128)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTitle)
{
    core::json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = YAxis()(Title().text("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisType)
{
    core::json expected = {{ "type", "-" }};
    auto actual = YAxis()(AxisType::Dash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisAutoRange)
{
    core::json expected = {{ "autorange", false }};
    auto actual = YAxis()(AutoRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisRangeMode)
{
    core::json expected = {{ "rangemode", "tozero" }};
    auto actual = YAxis()(RangeMode::ToZero).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisRange)
{
    core::json expected = {{ "range", {1,2,3} }};
    auto actual = YAxis().range(ints{1,2,3}).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisFixedRange)
{
    core::json expected = {{ "fixedrange", false }};
    auto actual = YAxis().fixedrange(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisConstrain)
{
    core::json expected = {{ "constrain", "domain" }};
    auto actual = YAxis()(Constrain::Domain).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisConstrainToward)
{
    core::json expected = {{ "constraintoward", "center" }};
    auto actual = YAxis()(ConstrainToward::Center).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTickMode)
{
    core::json expected = {{ "tickmode", "auto" }};
    auto actual = YAxis()(TickMode::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTicks)
{
    core::json expected = {{ "ticks", "inside" }};
    auto actual = YAxis()(Ticks::Inside).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTicksOn)
{
    core::json expected = {{ "tickson", "labels" }};
    auto actual = YAxis()(TicksOn::Labels).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisMirror)
{
    core::json expected = {{ "mirror", false }};
    auto actual = YAxis()(Mirror::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowTickPrefix)
{
    core::json expected = {{ "showtickprefix", "last" }};
    auto actual = YAxis()(ShowTickPrefix::Last).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowTickSuffix)
{
    core::json expected = {{ "showticksuffix", "first" }};
    auto actual = YAxis()(ShowTickSuffix::First).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowExponent)
{
    core::json expected = {{ "showexponent", "none" }};
    auto actual = YAxis()(ShowExponent::None).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisExponentFormat)
{
    core::json expected = {{ "exponentformat", "power" }};
    auto actual = YAxis()(ExponentFormat::Power).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



