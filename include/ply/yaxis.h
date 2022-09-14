// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/axis.h"

namespace ply
{

struct YAxis : Axis<YAxis>, Axis<YAxis>::Members<>, virtual Data
{
    using MembersBase = Axis<YAxis>::Members<>;
    using MembersBase::MembersBase;
};

template<> inline std::string as_string<YAxis>() { return "yaxis"; }
inline json as_json(const YAxis& axis) { return axis.json_; }

}; // ply

