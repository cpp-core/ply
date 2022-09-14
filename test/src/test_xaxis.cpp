// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/xaxis.h"

using namespace ply;

TEST(Ply, XAxis)
{
    EXPECT_EQ(as_string<XAxis>(), "xaxis");
    
    auto expected = json::object();
    auto actual = XAxis().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisVisible)
{
    json expected = {{ "visible", false }};
    auto actual = XAxis(Visible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisColor)
{
    json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = XAxis(Color(RGB(32,64,128))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTitle)
{
    json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = XAxis(Title(Text("abc"))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisType)
{
    json expected = {{ "type", "-" }};
    auto actual = XAxis(AxisType::Dash).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisAutoRange)
{
    json expected = {{ "autorange", false }};
    auto actual = XAxis(AutoRange::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRangeMode)
{
    json expected = {{ "rangemode", "tozero" }};
    auto actual = XAxis(RangeMode::ToZero).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRange)
{
    json expected = {{ "range", {1,2,3} }};
    auto actual = XAxis(Range(std::vector<int>{1,2,3})).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisFixedRange)
{
    json expected = {{ "fixedrange", false }};
    auto actual = XAxis(FixedRange::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisConstrain)
{
    json expected = {{ "constrain", "domain" }};
    auto actual = XAxis(Constrain::Domain).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisConstrainToward)
{
    json expected = {{ "constraintoward", "center" }};
    auto actual = XAxis(ConstrainToward::Center).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTickMode)
{
    json expected = {{ "tickmode", "auto" }};
    auto actual = XAxis(TickMode::Auto).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTicks)
{
    json expected = {{ "ticks", "inside" }};
    auto actual = XAxis(Ticks::Inside).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisTicksOn)
{
    json expected = {{ "tickson", "labels" }};
    auto actual = XAxis(TicksOn::Labels).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisMirror)
{
    json expected = {{ "mirror", false }};
    auto actual = XAxis(Mirror::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowTickPrefix)
{
    json expected = {{ "showtickprefix", "last" }};
    auto actual = XAxis(ShowTickPrefix::Last).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowTickSuffix)
{
    json expected = {{ "showticksuffix", "first" }};
    auto actual = XAxis(ShowTickSuffix::First).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisShowExponent)
{
    json expected = {{ "showexponent", "none" }};
    auto actual = XAxis(ShowExponent::None).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisExponentFormat)
{
    json expected = {{ "exponentformat", "power" }};
    auto actual = XAxis(ExponentFormat::Power).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, XAxisRangeSlider)
{
    json expected = {{ "rangeslider", {{ "visible", true }}}};
    auto actual = XAxis(RangeSlider(Visible::True)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



