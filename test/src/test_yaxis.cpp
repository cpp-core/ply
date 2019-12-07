// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/yaxis.h"

using namespace ply;

TEST(Ply, YAxis)
{
    EXPECT_EQ(as_string<YAxis>(), "yaxis");
    
    auto expected = nlj::json::object();
    auto actual = YAxis().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisVisible)
{
    nlj::json expected = {{ "visible", false }};
    auto actual = YAxis(Visible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisColor)
{
    nlj::json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = YAxis(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTitle)
{
    nlj::json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = YAxis(Title(Text("abc"))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisType)
{
    nlj::json expected = {{ "type", "-" }};
    auto actual = YAxis(AxisType::Dash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisAutoRange)
{
    nlj::json expected = {{ "autorange", false }};
    auto actual = YAxis(AutoRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisRangeMode)
{
    nlj::json expected = {{ "rangemode", "tozero" }};
    auto actual = YAxis(RangeMode::ToZero).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisRange)
{
    nlj::json expected = {{ "range", {1,2,3} }};
    auto actual = YAxis(Range(ints{1,2,3})).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisFixedRange)
{
    nlj::json expected = {{ "fixedrange", false }};
    auto actual = YAxis(FixedRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisConstrain)
{
    nlj::json expected = {{ "constrain", "domain" }};
    auto actual = YAxis(Constrain::Domain).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisConstrainToward)
{
    nlj::json expected = {{ "constraintoward", "center" }};
    auto actual = YAxis(ConstrainToward::Center).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTickMode)
{
    nlj::json expected = {{ "tickmode", "auto" }};
    auto actual = YAxis(TickMode::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTicks)
{
    nlj::json expected = {{ "ticks", "inside" }};
    auto actual = YAxis(Ticks::Inside).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTicksOn)
{
    nlj::json expected = {{ "tickson", "labels" }};
    auto actual = YAxis(TicksOn::Labels).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisMirror)
{
    nlj::json expected = {{ "mirror", false }};
    auto actual = YAxis(Mirror::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowTickPrefix)
{
    nlj::json expected = {{ "showtickprefix", "last" }};
    auto actual = YAxis(ShowTickPrefix::Last).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowTickSuffix)
{
    nlj::json expected = {{ "showticksuffix", "first" }};
    auto actual = YAxis(ShowTickSuffix::First).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowExponent)
{
    nlj::json expected = {{ "showexponent", "none" }};
    auto actual = YAxis(ShowExponent::None).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisExponentFormat)
{
    nlj::json expected = {{ "exponentformat", "power" }};
    auto actual = YAxis(ExponentFormat::Power).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



