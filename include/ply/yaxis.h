// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/axis.h"

namespace ply
{

struct YAxis : Axis<YAxis>, Axis<YAxis>::Members<>, virtual Data
{ };

template<> inline string as_string<YAxis>() { return "yaxis"; }
inline core::json as_json(const YAxis& axis) { return axis.json; }

}; // ply

