// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/zaxis.h"

using namespace ply;

TEST(Ply, ZAxis)
{
    EXPECT_EQ(as_string<ZAxis>(), "zaxis");
    
    auto expected = core::json::object();
    auto actual = ZAxis().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisVisible)
{
    core::json expected = {{ "visible", false }};
    auto actual = ZAxis(Visible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisColor)
{
    core::json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = ZAxis(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTitle)
{
    core::json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = ZAxis(Title(Text("abc"))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisType)
{
    core::json expected = {{ "type", "-" }};
    auto actual = ZAxis(AxisType::Dash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisAutoRange)
{
    core::json expected = {{ "autorange", false }};
    auto actual = ZAxis(AutoRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRangeMode)
{
    core::json expected = {{ "rangemode", "tozero" }};
    auto actual = ZAxis(RangeMode::ToZero).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRange)
{
    core::json expected = {{ "range", {1,2,3} }};
    auto actual = ZAxis(Range(ints{1,2,3})).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisFixedRange)
{
    core::json expected = {{ "fixedrange", false }};
    auto actual = ZAxis(FixedRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisConstrain)
{
    core::json expected = {{ "constrain", "domain" }};
    auto actual = ZAxis(Constrain::Domain).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisConstrainToward)
{
    core::json expected = {{ "constraintoward", "center" }};
    auto actual = ZAxis(ConstrainToward::Center).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTickMode)
{
    core::json expected = {{ "tickmode", "auto" }};
    auto actual = ZAxis(TickMode::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTicks)
{
    core::json expected = {{ "ticks", "inside" }};
    auto actual = ZAxis(Ticks::Inside).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTicksOn)
{
    core::json expected = {{ "tickson", "labels" }};
    auto actual = ZAxis(TicksOn::Labels).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisMirror)
{
    core::json expected = {{ "mirror", false }};
    auto actual = ZAxis(Mirror::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowTickPrefix)
{
    core::json expected = {{ "showtickprefix", "last" }};
    auto actual = ZAxis(ShowTickPrefix::Last).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowTickSuffix)
{
    core::json expected = {{ "showticksuffix", "first" }};
    auto actual = ZAxis(ShowTickSuffix::First).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowExponent)
{
    core::json expected = {{ "showexponent", "none" }};
    auto actual = ZAxis(ShowExponent::None).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisExponentFormat)
{
    core::json expected = {{ "exponentformat", "power" }};
    auto actual = ZAxis(ExponentFormat::Power).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRangeSlider)
{
    core::json expected = {{ "rangeslider", {{ "visible", true }}}};
    auto actual = ZAxis(RangeSlider(Visible::True)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



