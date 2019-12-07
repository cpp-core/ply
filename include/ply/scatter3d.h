// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/color.h"
#include "ply/line.h"
#include "ply/marker.h"
#include "ply/members.h"
#include "ply/name.h"

namespace ply
{

struct Scatter3d : Members<Scatter3d,Color,GroupNorm,Line,Marker,Mode,Name,Orientation,PlotVisible>, Trace
{
    using MembersBase = Members<Scatter3d,Color,GroupNorm,Line,Marker,Mode,Name,Orientation,PlotVisible>;
    using MembersBase::MembersBase;
    
    Scatter3d() { json = base(); }
    static nlj::json base() { return {{ "type", "scatter3d" }}; }
    
    Scatter3d& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    Scatter3d& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    Scatter3d& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    Scatter3d& stackgroup(string_view name) { json["stackgroup"] = name; return *this; }

    template<class C> Scatter3d& x(const C& data) { json["x"] = data; return *this; }
    template<class C> Scatter3d& y(const C& data) { json["y"] = data; return *this; }
    template<class C> Scatter3d& z(const C& data) { json["z"] = data; return *this; }
    
    Scatter3d& text(string_view str) { json["text"] = str; return *this; }
};

template<> string as_string<Scatter3d>() { return "scatter3d"; }

}; // ply

