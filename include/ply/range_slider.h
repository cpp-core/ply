// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/members.h"

namespace ply
{

struct SliderYAxis : Members<SliderYAxis, SliderRangeMode>, Range<SliderYAxis>, virtual Data
{
    using MembersBase = Members<SliderYAxis, SliderRangeMode>;
    using MembersBase::MembersBase;
};

template<> inline string as_string<SliderYAxis>() { return "yaxis"; }
inline core::json as_json(const SliderYAxis& axis) { return axis.json; }

struct RangeSlider : Members<RangeSlider,SliderYAxis,Visible>, Range<RangeSlider>, virtual Data
{
    using MembersBase = Members<RangeSlider,SliderYAxis,Visible>;
    using MembersBase::MembersBase;
    
    RangeSlider& bgcolor(const Color& c) { json["bgcolor"] = as_json(c); return *this; }
    RangeSlider& bordercolor(const Color& c) { json["bordercolor"] = as_json(c); return *this; }
    RangeSlider& borderwidth(int w) { json["borderwidth"] = w; return *this; }
    RangeSlider& autorange(bool b) { json["autorange"] = b; return *this; }
    template<Arithmetic T> RangeSlider& thickness(T x) { json["thickness"] = x; return *this; }
    RangeSlider& visible(bool b) { json["visible"] = b; return *this; }
};

template<> inline string as_string<RangeSlider>() { return "rangeslider"; }
inline core::json as_json(const RangeSlider& slider) { return slider.json; }

}; // ply

