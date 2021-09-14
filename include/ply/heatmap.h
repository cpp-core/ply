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

struct HeatMap : Members<HeatMap,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>, Trace
{
    using MembersBase = Members<HeatMap,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>;
    using MembersBase::MembersBase;
    
    HeatMap() { json = base(); }
    static nlj::json base() { return {{ "type", "heatmap" }}; }

    HeatMap& xaxis(const string& axis) { json["xaxis"] = axis; return *this; }
    HeatMap& yaxis(const string& axis) { json["yaxis"] = axis; return *this; }
    HeatMap& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    HeatMap& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    HeatMap& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    HeatMap& stackgroup(string_view name) { json["stackgroup"] = name; return *this; }

    template<class C> HeatMap& x(const C& data) { json["x"] = data; return *this; }
    template<class T> HeatMap& x0(T x0) { json["x0"] = x0; return *this; }
    template<class T> HeatMap& dx(T dx) { json["dx"] = dx; return *this; }
    
    template<class C> HeatMap& y(const C& data) { json["y"] = data; return *this; }
    template<class T> HeatMap& y0(T y0) { json["y0"] = y0; return *this; }
    template<class T> HeatMap& dy(T dy) { json["dy"] = dy; return *this; }

    template<class C> HeatMap& z(const C& data) { json["z"] = data; return *this; }
    
    HeatMap& text(string_view str) { json["text"] = str; return *this; }
};

template<> string as_string<HeatMap>() { return "heatmap"; }

}; // ply

