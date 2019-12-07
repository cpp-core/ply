// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/members.h"
#include "ply/range.h"

namespace ply
{

struct SliderYAxis : Members<SliderYAxis,Range,SliderRangeMode>, virtual Data
{
    using MembersBase = Members<SliderYAxis,Range,SliderRangeMode>;
    using MembersBase::MembersBase;
};

template<> inline string as_string<SliderYAxis>() { return "yaxis"; }
inline nlj::json as_json(const SliderYAxis& axis) { return axis.json; }

struct RangeSlider : Members<RangeSlider,Range,SliderYAxis,Visible>, virtual Data
{
    using MembersBase = Members<RangeSlider,Range,SliderYAxis,Visible>;
    using MembersBase::MembersBase;
    
    RangeSlider& bgcolor(const Color& c) { json["bgcolor"] = as_json(c); return *this; }
    RangeSlider& bordercolor(const Color& c) { json["bordercolor"] = as_json(c); return *this; }
    RangeSlider& borderwidth(int w) { json["borderwidth"] = w; return *this; }
    RangeSlider& autorange(bool b) { json["autorange"] = b; return *this; }
    template<Arithmetic T> RangeSlider& thickness(T x) { json["thickness"] = x; return *this; }
};

template<> inline string as_string<RangeSlider>() { return "rangeslider"; }
inline nlj::json as_json(const RangeSlider& slider) { return slider.json; }

}; // ply

