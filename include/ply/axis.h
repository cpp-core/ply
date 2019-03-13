// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/members.h"
#include "ply/range.h"
#include "ply/title.h"

namespace ply
{

template<class D>
struct Axis : virtual Data
{
    template<class... Ts>
    using Members = ply::Members
	<D,
	 AutoRange, AxisType, Color, Constrain, ConstrainToward, Layer,
	 ExponentFormat, Mirror, Range, RangeMode, Side, ShowExponent, ShowTickPrefix,
	 ShowTickSuffix, TickMode, Ticks, TicksOn, Title, Visible,
	 Ts...>;

    Axis& fixedrange(bool b) { json["fixedrange"] = b; return *this; }
};

}; // ply

