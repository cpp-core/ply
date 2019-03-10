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
    Line& smoothing(real s) { json["smoothing"] = s; return *this; }
    Line& simplify(bool b) { json["simplify"] = b; return *this; }

    template<Arithmetic T>
    Line& width(T w) { json["width"] = w; return *this; }
    
    template<class T>
    requires std::is_same_v<T,Dash> or std::is_same_v<T,Shape> or std::is_same_v<T,Color>
    Line& set(T obj) { json[as_string<T>()] = as_json(obj); return *this; }

    core::json json;
};

}; // ply

