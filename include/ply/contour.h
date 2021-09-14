// Copyright (C) 2019, 2021 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/color.h"
#include "ply/line.h"
#include "ply/members.h"
#include "ply/name.h"

namespace ply
{

struct Contour : Members<Contour,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>, Trace
{
    using MembersBase = Members<Contour,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>;
    using MembersBase::MembersBase;
    
    Contour() { json = base(); }
    static nlj::json base() { return {{ "type", "contour" }}; }

    Contour& xaxis(const string& axis) { json["xaxis"] = axis; return *this; }
    Contour& yaxis(const string& axis) { json["yaxis"] = axis; return *this; }
    Contour& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    Contour& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    Contour& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    Contour& stackgroup(string_view name) { json["stackgroup"] = name; return *this; }

    template<class C> Contour& x(const C& data) { json["x"] = data; return *this; }
    template<class T> Contour& x0(T x0) { json["x0"] = x0; return *this; }
    template<class T> Contour& dx(T dx) { json["dx"] = dx; return *this; }
    
    template<class C> Contour& y(const C& data) { json["y"] = data; return *this; }
    template<class T> Contour& y0(T y0) { json["y0"] = y0; return *this; }
    template<class T> Contour& dy(T dy) { json["dy"] = dy; return *this; }

    template<class C> Contour& z(const C& data) { json["z"] = data; return *this; }
    
    Contour& text(string_view str) { json["text"] = str; return *this; }
};

template<> string as_string<Contour>() { return "contour"; }

}; // ply

