// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/axis.h"
#include "ply/range_slider.h"

namespace ply
{

struct ZAxis : Axis<ZAxis>, Axis<ZAxis>::Members<RangeSlider>, virtual Data
{
    using MembersBase = Axis<ZAxis>::Members<RangeSlider>;
    using MembersBase::MembersBase;
};

template<> inline std::string as_string<ZAxis>() { return "zaxis"; }
inline json as_json(const ZAxis& axis) { return axis.json_; }

}; // ply

