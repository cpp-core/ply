// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/range_slider.h"

using namespace ply;

TEST(Ply, RangeSlider)
{
    EXPECT_EQ(as_string<RangeSlider>(), "rangeslider");
    
    auto expected = core::json::object();
    auto actual = RangeSlider().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBGColor)
{
    core::json expected = {{ "bgcolor", "rgb(32,64,128)" }};
    auto actual = RangeSlider().bgcolor(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBorderColor)
{
    core::json expected = {{ "bordercolor", "rgb(32,64,128)" }};
    auto actual = RangeSlider().bordercolor(Color(RGB(32,64,128))).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBorderWidth)
{
    core::json expected = {{ "borderwidth", 5 }};
    auto actual = RangeSlider().borderwidth(5).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderAutoRange)
{
    core::json expected = {{ "autorange", false }};
    auto actual = RangeSlider().autorange(false).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderRange)
{
    core::json expected = {{ "range", {1,2,3} }};
    auto actual = RangeSlider(Range(ints{1,2,3})).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBorderThickness)
{
    core::json expected = {{ "thickness", 0.25 }};
    auto actual = RangeSlider().thickness(0.25).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderVisible)
{
    core::json expected = {{ "visible", false }};
    auto actual = RangeSlider(Visible::False).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderYAxis)
{
    core::json expected = {{ "yaxis", {{ "rangemode", "fixed" }}}};
    auto actual = RangeSlider()(SliderYAxis()(SliderRangeMode::Fixed)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



