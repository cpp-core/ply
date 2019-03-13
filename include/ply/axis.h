// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/title.h"

namespace ply
{

template<class D>
struct Axis : Range<Axis<D>>, virtual Data
{
    template<class... Ts>
    using Members = ply::Members
	<D,
	 AutoRange, AxisType, Color, Constrain, ConstrainToward, Layer,
	 ExponentFormat, Mirror, RangeMode, Side, ShowExponent, ShowTickPrefix,
	 ShowTickSuffix, TickMode, Ticks, TicksOn, Title,
	 Ts...>;

    Axis& visible(bool b) { json["visible"] = b; return *this; }
    Axis& fixedrange(bool b) { json["fixedrange"] = b; return *this; }
};

}; // ply

