// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/line.h"
#include "ply/group_norm.h"
#include "ply/orientation.h"

namespace ply
{

struct Scatter
{
    Scatter() { json = {{ "type", "scatter" }}; }

    Scatter& visible(bool b) { json["visible"] = b; return *this; }
    Scatter& visible_legend() { json["visible"] = "ledendonly"; return *this; }
    Scatter& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    Scatter& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    Scatter& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    Scatter& name(string_view name) { json["name"] = name; return *this; }

    Scatter& x(const reals& data) { json["x"] = data; return *this; }
    Scatter& x0(real x0) { json["x0"] = x0; return *this; }
    Scatter& dx(real dx) { json["dx"] = dx; return *this; }
    
    Scatter& y(const reals& data) { json["y"] = data; return *this; }
    Scatter& y0(real y0) { json["y0"] = y0; return *this; }
    Scatter& dy(real dy) { json["dy"] = dy; return *this; }

    template<class Enum>
    Scatter& set(Enum e) { json[as_string<Enum>()] = as_json(e); return *this; }

    Scatter& text(string_view str) { json["text"] = str; return *this; }
    Scatter& line(const Line& l) { json["line"] = l.json; return *this; }

    core::json json;
};

}; // ply

