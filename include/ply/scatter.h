// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/color.h"
#include "ply/line.h"
#include "ply/members.h"
#include "ply/name.h"

namespace ply
{

struct Scatter : Members<Scatter,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>, Trace
{
    using MembersBase = Members<Scatter,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>;
    using MembersBase::MembersBase;
    
    Scatter() { json = base(); }
    static nlj::json base() { return {{ "type", "scatter" }}; }
    
    Scatter& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    Scatter& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    Scatter& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    Scatter& stackgroup(string_view name) { json["stackgroup"] = name; return *this; }

    template<class C> Scatter& x(const C& data) { json["x"] = data; return *this; }
    template<Arithmetic T> Scatter& x0(T x0) { json["x0"] = x0; return *this; }
    template<Arithmetic T> Scatter& dx(T dx) { json["dx"] = dx; return *this; }
    
    template<class C> Scatter& y(const C& data) { json["y"] = data; return *this; }
    template<Arithmetic T> Scatter& y0(T y0) { json["y0"] = y0; return *this; }
    template<Arithmetic T> Scatter& dy(T dy) { json["dy"] = dy; return *this; }

    Scatter& text(string_view str) { json["text"] = str; return *this; }
};

template<> string as_string<Scatter>() { return "scatter"; }

}; // ply

