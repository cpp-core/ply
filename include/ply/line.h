// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/dash.h"
#include "ply/shape.h"
#include "core/mp/contains.h"

namespace ply
{

struct Line
{
    Line() { json = core::json::object(); }
    Line& smoothing(real s) { json["smoothing"] = s; return *this; }
    Line& simplify(bool b) { json["simplify"] = b; return *this; }

    template<Arithmetic T>
    Line& width(T w) { json["width"] = w; return *this; }
    
    template<class T>
    requires core::mp::is_member_v<T,Color,Dash,Shape>
    Line& set(T obj) { json[as_string<T>()] = as_json(obj); return *this; }

    core::json json;
};

template<> string as_string<Line>() { return "line"; }
core::json as_json(const Line& line) { return line.json; }

}; // ply

