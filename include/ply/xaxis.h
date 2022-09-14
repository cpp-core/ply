// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/axis.h"
#include "ply/range_slider.h"

namespace ply
{

struct XAxis : Axis<XAxis>, Axis<XAxis>::Members<RangeSlider>, virtual Data
{
    using MembersBase = Axis<XAxis>::Members<RangeSlider>;
    using MembersBase::MembersBase;
};

template<> inline std::string as_string<XAxis>() { return "xaxis"; }
inline json as_json(const XAxis& axis) { return axis.json_; }

}; // ply

