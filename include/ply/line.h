// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/dash.h"

namespace ply
{

struct Line
{
    Line() = default;
    Line& color(const Color& c) { json["color"] = c.json; return *this; }
    Line& width(uint w) { json["width"] = w; return *this; }
    Line& width(real w) { json["width"] = w; return *this; }
    Line& smoothing(real s) { json["smoothing"] = s; return *this; }
    Line& simplify(bool b) { json["simplify"] = b; return *this; }

    template<class Enum>
    Line& set(Enum e) { json[as_string<Enum>()] = as_string(e); return *this; }

    core::json json;
};

}; // ply

