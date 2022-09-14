// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/members.h"

namespace ply
{

struct Line : Members<Line,Color,Dash,Shape>, virtual Data
{
    using MembersBase = Members<Line,Color,Dash,Shape>;
    using MembersBase::MembersBase;
    
    Line& smoothing(double s) { json_["smoothing"] = s; return *this; }
    Line& simplify(bool b) { json_["simplify"] = b; return *this; }

    template<class T>
    Line& width(T w) { json_["width"] = w; return *this; }
};

template<> inline std::string as_string<Line>() { return "line"; }
inline json as_json(const Line& line) { return line.json_; }

}; // ply

