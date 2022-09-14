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

template<> inline std::string as_string<SliderYAxis>() { return "yaxis"; }
inline json as_json(const SliderYAxis& axis) { return axis.json_; }

struct RangeSlider : Members<RangeSlider,Range,SliderYAxis,Visible>, virtual Data
{
    using MembersBase = Members<RangeSlider,Range,SliderYAxis,Visible>;
    using MembersBase::MembersBase;
    
    RangeSlider& bgcolor(const Color& c) { json_["bgcolor"] = as_json(c); return *this; }
    RangeSlider& bordercolor(const Color& c) { json_["bordercolor"] = as_json(c); return *this; }
    RangeSlider& borderwidth(int w) { json_["borderwidth"] = w; return *this; }
    RangeSlider& autorange(bool b) { json_["autorange"] = b; return *this; }
    template<class T> RangeSlider& thickness(T x) { json_["thickness"] = x; return *this; }
};

template<> inline std::string as_string<RangeSlider>() { return "rangeslider"; }
inline json as_json(const RangeSlider& slider) { return slider.json_; }

}; // ply

