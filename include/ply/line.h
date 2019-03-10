// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/dash.h"
#include "ply/shape.h"

namespace ply
{

struct Line
{
    Line() { json = core::json::object(); }
    Line& set(const Color& c) { json["color"] = c.json; return *this; }
    Line& smoothing(real s) { json["smoothing"] = s; return *this; }
    Line& simplify(bool b) { json["simplify"] = b; return *this; }


    template<Arithmetic T>
    Line& width(T w) { json["width"] = w; return *this; }
    
    template<class Enum>
    requires std::is_same_v<Enum,Dash> or std::is_same_v<Enum,Shape>
    Line& set(Enum e) { json[as_string<Enum>()] = as_string(e); return *this; }

    core::json json;
};

}; // ply

