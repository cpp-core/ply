// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/zaxis.h"

using namespace ply;

TEST(Ply, ZAxis)
{
    EXPECT_EQ(as_string<ZAxis>(), "zaxis");
    
    auto expected = nlj::json::object();
    auto actual = ZAxis().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisVisible)
{
    nlj::json expected = {{ "visible", false }};
    auto actual = ZAxis(Visible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisColor)
{
    nlj::json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = ZAxis(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTitle)
{
    nlj::json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = ZAxis(Title(Text("abc"))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisType)
{
    nlj::json expected = {{ "type", "-" }};
    auto actual = ZAxis(AxisType::Dash).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisAutoRange)
{
    nlj::json expected = {{ "autorange", false }};
    auto actual = ZAxis(AutoRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRangeMode)
{
    nlj::json expected = {{ "rangemode", "tozero" }};
    auto actual = ZAxis(RangeMode::ToZero).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRange)
{
    nlj::json expected = {{ "range", {1,2,3} }};
    auto actual = ZAxis(Range(ints{1,2,3})).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisFixedRange)
{
    nlj::json expected = {{ "fixedrange", false }};
    auto actual = ZAxis(FixedRange::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisConstrain)
{
    nlj::json expected = {{ "constrain", "domain" }};
    auto actual = ZAxis(Constrain::Domain).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisConstrainToward)
{
    nlj::json expected = {{ "constraintoward", "center" }};
    auto actual = ZAxis(ConstrainToward::Center).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTickMode)
{
    nlj::json expected = {{ "tickmode", "auto" }};
    auto actual = ZAxis(TickMode::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTicks)
{
    nlj::json expected = {{ "ticks", "inside" }};
    auto actual = ZAxis(Ticks::Inside).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTicksOn)
{
    nlj::json expected = {{ "tickson", "labels" }};
    auto actual = ZAxis(TicksOn::Labels).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisMirror)
{
    nlj::json expected = {{ "mirror", false }};
    auto actual = ZAxis(Mirror::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowTickPrefix)
{
    nlj::json expected = {{ "showtickprefix", "last" }};
    auto actual = ZAxis(ShowTickPrefix::Last).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowTickSuffix)
{
    nlj::json expected = {{ "showticksuffix", "first" }};
    auto actual = ZAxis(ShowTickSuffix::First).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowExponent)
{
    nlj::json expected = {{ "showexponent", "none" }};
    auto actual = ZAxis(ShowExponent::None).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisExponentFormat)
{
    nlj::json expected = {{ "exponentformat", "power" }};
    auto actual = ZAxis(ExponentFormat::Power).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRangeSlider)
{
    nlj::json expected = {{ "rangeslider", {{ "visible", true }}}};
    auto actual = ZAxis(RangeSlider(Visible::True)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



