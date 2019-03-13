// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "core/mp/contains.h"

namespace ply
{

struct Line : Members<Line,Color,Dash,Shape>, virtual Data
{
    using MembersBase = Members<Line,Color,Dash,Shape>;
    using MembersBase::MembersBase;
    
    Line& smoothing(real s) { json["smoothing"] = s; return *this; }
    Line& simplify(bool b) { json["simplify"] = b; return *this; }

    template<Arithmetic T>
    Line& width(T w) { json["width"] = w; return *this; }
};

template<> inline string as_string<Line>() { return "line"; }
inline core::json as_json(const Line& line) { return line.json; }

}; // ply

