// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/xaxis.h"

using namespace ply;

TEST(Ply, XAxis)
{
    EXPECT_EQ(as_string<XAxis>(), "xaxis");
    
    auto expected = core::json::object();
    auto actual = XAxis().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisVisible)
{
    core::json expected = {{ "visible", false }};
    auto actual = XAxis(Visible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisColor)
{
    core::json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = XAxis(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTitle)
{
    core::json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = XAxis(Title(Text("abc"))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisType)
{
    core::json expected = {{ "type", "-" }};
    auto actual = XAxis(AxisType::Dash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisAutoRange)
{
    core::json expected = {{ "autorange", false }};
    auto actual = XAxis(AutoRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRangeMode)
{
    core::json expected = {{ "rangemode", "tozero" }};
    auto actual = XAxis(RangeMode::ToZero).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRange)
{
    core::json expected = {{ "range", {1,2,3} }};
    auto actual = XAxis(Range(ints{1,2,3})).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisFixedRange)
{
    core::json expected = {{ "fixedrange", false }};
    auto actual = XAxis(FixedRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisConstrain)
{
    core::json expected = {{ "constrain", "domain" }};
    auto actual = XAxis(Constrain::Domain).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisConstrainToward)
{
    core::json expected = {{ "constraintoward", "center" }};
    auto actual = XAxis(ConstrainToward::Center).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTickMode)
{
    core::json expected = {{ "tickmode", "auto" }};
    auto actual = XAxis(TickMode::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTicks)
{
    core::json expected = {{ "ticks", "inside" }};
    auto actual = XAxis(Ticks::Inside).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTicksOn)
{
    core::json expected = {{ "tickson", "labels" }};
    auto actual = XAxis(TicksOn::Labels).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisMirror)
{
    core::json expected = {{ "mirror", false }};
    auto actual = XAxis(Mirror::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowTickPrefix)
{
    core::json expected = {{ "showtickprefix", "last" }};
    auto actual = XAxis(ShowTickPrefix::Last).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowTickSuffix)
{
    core::json expected = {{ "showticksuffix", "first" }};
    auto actual = XAxis(ShowTickSuffix::First).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowExponent)
{
    core::json expected = {{ "showexponent", "none" }};
    auto actual = XAxis(ShowExponent::None).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisExponentFormat)
{
    core::json expected = {{ "exponentformat", "power" }};
    auto actual = XAxis(ExponentFormat::Power).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRangeSlider)
{
    core::json expected = {{ "rangeslider", {{ "visible", true }}}};
    auto actual = XAxis(RangeSlider(Visible::True)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



