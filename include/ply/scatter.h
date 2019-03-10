// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/line.h"
#include "ply/group_norm.h"
#include "ply/orientation.h"
#include "core/mp/contains.h"

namespace ply
{

struct Scatter
{
    Scatter() { json = {{ "type", "scatter" }}; }

    Scatter& visible(bool b) { json["visible"] = b; return *this; }
    Scatter& visible_legend() { json["visible"] = "legendonly"; return *this; }
    Scatter& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    Scatter& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    Scatter& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    Scatter& name(string_view name) { json["name"] = name; return *this; }
    Scatter& stackgroup(string_view name) { json["stackgroup"] = name; return *this; }

    template<class C> Scatter& x(const C& data) { json["x"] = data; return *this; }
    template<Arithmetic T> Scatter& x0(T x0) { json["x0"] = x0; return *this; }
    template<Arithmetic T> Scatter& dx(T dx) { json["dx"] = dx; return *this; }
    
    template<class C> Scatter& y(const C& data) { json["y"] = data; return *this; }
    template<Arithmetic T> Scatter& y0(T y0) { json["y0"] = y0; return *this; }
    template<Arithmetic T> Scatter& dy(T dy) { json["dy"] = dy; return *this; }

    template<class T>
    requires core::mp::is_member_v<T,Color,GroupNorm,Line,Orientation>
    Scatter& set(T obj) { json[as_string<T>()] = as_json(obj); return *this; }

    Scatter& text(string_view str) { json["text"] = str; return *this; }

    core::json json;
};

template<> string as_string<Scatter>() { return "scatter"; }

}; // ply

