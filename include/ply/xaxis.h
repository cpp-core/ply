// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/axis.h"
#include "ply/range_slider.h"

namespace ply
{

struct XAxis : Axis<XAxis>, Axis<XAxis>::Members<RangeSlider>, virtual Data
{ };

template<> inline string as_string<XAxis>() { return "xaxis"; }
inline core::json as_json(const XAxis& axis) { return axis.json; }

}; // ply

