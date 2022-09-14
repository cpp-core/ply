// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/yaxis.h"

using namespace ply;

TEST(Ply, YAxis)
{
    EXPECT_EQ(as_string<YAxis>(), "yaxis");
    
    auto expected = json::object();
    auto actual = YAxis().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisVisible)
{
    json expected = {{ "visible", false }};
    auto actual = YAxis(Visible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisColor)
{
    json expected = {{ "color", "rgb(32,64,128)" }};
    auto actual = YAxis(Color(RGB(32,64,128))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTitle)
{
    json expected = {{ "title", {{ "text", "abc" }}}};
    auto actual = YAxis(Title(Text("abc"))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisType)
{
    json expected = {{ "type", "-" }};
    auto actual = YAxis(AxisType::Dash).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisAutoRange)
{
    json expected = {{ "autorange", false }};
    auto actual = YAxis(AutoRange::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisRangeMode)
{
    json expected = {{ "rangemode", "tozero" }};
    auto actual = YAxis(RangeMode::ToZero).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisRange)
{
    json expected = {{ "range", {1,2,3} }};
    auto actual = YAxis(Range(std::vector<int>{1,2,3})).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisFixedRange)
{
    json expected = {{ "fixedrange", false }};
    auto actual = YAxis(FixedRange::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisConstrain)
{
    json expected = {{ "constrain", "domain" }};
    auto actual = YAxis(Constrain::Domain).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisConstrainToward)
{
    json expected = {{ "constraintoward", "center" }};
    auto actual = YAxis(ConstrainToward::Center).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTickMode)
{
    json expected = {{ "tickmode", "auto" }};
    auto actual = YAxis(TickMode::Auto).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTicks)
{
    json expected = {{ "ticks", "inside" }};
    auto actual = YAxis(Ticks::Inside).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisTicksOn)
{
    json expected = {{ "tickson", "labels" }};
    auto actual = YAxis(TicksOn::Labels).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisMirror)
{
    json expected = {{ "mirror", false }};
    auto actual = YAxis(Mirror::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowTickPrefix)
{
    json expected = {{ "showtickprefix", "last" }};
    auto actual = YAxis(ShowTickPrefix::Last).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowTickSuffix)
{
    json expected = {{ "showticksuffix", "first" }};
    auto actual = YAxis(ShowTickSuffix::First).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisShowExponent)
{
    json expected = {{ "showexponent", "none" }};
    auto actual = YAxis(ShowExponent::None).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, YAxisExponentFormat)
{
    json expected = {{ "exponentformat", "power" }};
    auto actual = YAxis(ExponentFormat::Power).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



