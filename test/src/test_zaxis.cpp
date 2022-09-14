// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/zaxis.h"

using namespace ply;

TEST(Ply, ZAxis)
{
    EXPECT_EQ(as_string<ZAxis>(), "zaxis");
    
    auto expected = json::object();
    auto actual = ZAxis().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisVisible)
{
    json expected = {{ "visible", false }};
    auto actual = ZAxis(Visible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisColor)
{
    json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = ZAxis(Color(RGB(32,64,128))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTitle)
{
    json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = ZAxis(Title(Text("abc"))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisType)
{
    json expected = {{ "type", "-" }};
    auto actual = ZAxis(AxisType::Dash).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisAutoRange)
{
    json expected = {{ "autorange", false }};
    auto actual = ZAxis(AutoRange::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRangeMode)
{
    json expected = {{ "rangemode", "tozero" }};
    auto actual = ZAxis(RangeMode::ToZero).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRange)
{
    json expected = {{ "range", {1,2,3} }};
    auto actual = ZAxis(Range(std::vector<int>{1,2,3})).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisFixedRange)
{
    json expected = {{ "fixedrange", false }};
    auto actual = ZAxis(FixedRange::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisConstrain)
{
    json expected = {{ "constrain", "domain" }};
    auto actual = ZAxis(Constrain::Domain).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisConstrainToward)
{
    json expected = {{ "constraintoward", "center" }};
    auto actual = ZAxis(ConstrainToward::Center).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTickMode)
{
    json expected = {{ "tickmode", "auto" }};
    auto actual = ZAxis(TickMode::Auto).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTicks)
{
    json expected = {{ "ticks", "inside" }};
    auto actual = ZAxis(Ticks::Inside).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisTicksOn)
{
    json expected = {{ "tickson", "labels" }};
    auto actual = ZAxis(TicksOn::Labels).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisMirror)
{
    json expected = {{ "mirror", false }};
    auto actual = ZAxis(Mirror::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowTickPrefix)
{
    json expected = {{ "showtickprefix", "last" }};
    auto actual = ZAxis(ShowTickPrefix::Last).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowTickSuffix)
{
    json expected = {{ "showticksuffix", "first" }};
    auto actual = ZAxis(ShowTickSuffix::First).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisShowExponent)
{
    json expected = {{ "showexponent", "none" }};
    auto actual = ZAxis(ShowExponent::None).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisExponentFormat)
{
    json expected = {{ "exponentformat", "power" }};
    auto actual = ZAxis(ExponentFormat::Power).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ZAxisRangeSlider)
{
    json expected = {{ "rangeslider", {{ "visible", true }}}};
    auto actual = ZAxis(RangeSlider(Visible::True)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



