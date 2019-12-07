// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/xaxis.h"

using namespace ply;

TEST(Ply, XAxis)
{
    EXPECT_EQ(as_string<XAxis>(), "xaxis");
    
    auto expected = nlj::json::object();
    auto actual = XAxis().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisVisible)
{
    nlj::json expected = {{ "visible", false }};
    auto actual = XAxis(Visible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisColor)
{
    nlj::json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = XAxis(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTitle)
{
    nlj::json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = XAxis(Title(Text("abc"))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisType)
{
    nlj::json expected = {{ "type", "-" }};
    auto actual = XAxis(AxisType::Dash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisAutoRange)
{
    nlj::json expected = {{ "autorange", false }};
    auto actual = XAxis(AutoRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRangeMode)
{
    nlj::json expected = {{ "rangemode", "tozero" }};
    auto actual = XAxis(RangeMode::ToZero).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRange)
{
    nlj::json expected = {{ "range", {1,2,3} }};
    auto actual = XAxis(Range(ints{1,2,3})).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisFixedRange)
{
    nlj::json expected = {{ "fixedrange", false }};
    auto actual = XAxis(FixedRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisConstrain)
{
    nlj::json expected = {{ "constrain", "domain" }};
    auto actual = XAxis(Constrain::Domain).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisConstrainToward)
{
    nlj::json expected = {{ "constraintoward", "center" }};
    auto actual = XAxis(ConstrainToward::Center).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTickMode)
{
    nlj::json expected = {{ "tickmode", "auto" }};
    auto actual = XAxis(TickMode::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTicks)
{
    nlj::json expected = {{ "ticks", "inside" }};
    auto actual = XAxis(Ticks::Inside).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTicksOn)
{
    nlj::json expected = {{ "tickson", "labels" }};
    auto actual = XAxis(TicksOn::Labels).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisMirror)
{
    nlj::json expected = {{ "mirror", false }};
    auto actual = XAxis(Mirror::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowTickPrefix)
{
    nlj::json expected = {{ "showtickprefix", "last" }};
    auto actual = XAxis(ShowTickPrefix::Last).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowTickSuffix)
{
    nlj::json expected = {{ "showticksuffix", "first" }};
    auto actual = XAxis(ShowTickSuffix::First).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowExponent)
{
    nlj::json expected = {{ "showexponent", "none" }};
    auto actual = XAxis(ShowExponent::None).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisExponentFormat)
{
    nlj::json expected = {{ "exponentformat", "power" }};
    auto actual = XAxis(ExponentFormat::Power).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRangeSlider)
{
    nlj::json expected = {{ "rangeslider", {{ "visible", true }}}};
    auto actual = XAxis(RangeSlider(Visible::True)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



