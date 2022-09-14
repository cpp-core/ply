// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/range_slider.h"

using namespace ply;

TEST(Ply, RangeSlider)
{
    EXPECT_EQ(as_string<RangeSlider>(), "rangeslider");
    
    auto expected = json::object();
    auto actual = RangeSlider().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBGColor)
{
    json expected = {{ "bgcolor", "rgb(32,64,128)" }};
    auto actual = RangeSlider().bgcolor(Color(RGB(32,64,128))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBorderColor)
{
    json expected = {{ "bordercolor", "rgb(32,64,128)" }};
    auto actual = RangeSlider().bordercolor(Color(RGB(32,64,128))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBorderWidth)
{
    json expected = {{ "borderwidth", 5 }};
    auto actual = RangeSlider().borderwidth(5).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderAutoRange)
{
    json expected = {{ "autorange", false }};
    auto actual = RangeSlider().autorange(false).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderRange)
{
    json expected = {{ "range", {1,2,3} }};
    auto actual = RangeSlider(Range(std::vector<int>{1,2,3})).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderBorderThickness)
{
    json expected = {{ "thickness", 0.25 }};
    auto actual = RangeSlider().thickness(0.25).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderVisible)
{
    json expected = {{ "visible", false }};
    auto actual = RangeSlider(Visible::False).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RangeSliderYAxis)
{
    json expected = {{ "yaxis", {{ "rangemode", "fixed" }}}};
    auto actual = RangeSlider()(SliderYAxis()(SliderRangeMode::Fixed)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



