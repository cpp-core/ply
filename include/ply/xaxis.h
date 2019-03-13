// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/range_slider.h"
#include "ply/title.h"

namespace ply
{

using XAxisMembers = core::mp::list
    <AutoRange, AxisType, Color, Constrain, ConstrainToward, Layer, ExponentFormat, Mirror,
     RangeMode, RangeSlider, Side, ShowExponent, ShowTickPrefix, ShowTickSuffix,
     TickMode, Ticks, TicksOn, Title>;

struct XAxis : Member<XAxis,XAxisMembers>, Range<XAxis>, virtual Data
{
    XAxis() { json = core::json::object(); }
    XAxis& visible(bool b) { json["visible"] = b; return *this; }
    XAxis& fixedrange(bool b) { json["fixedrange"] = b; return *this; }
};

template<> inline string as_string<XAxis>() { return "xaxis"; }
inline core::json as_json(const XAxis& axis) { return axis.json; }

}; // ply

