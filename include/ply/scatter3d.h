// Copyright (C) 2019, 2022 by Mark Melton
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
    
    Scatter3d() { json_ = base(); }
    static json base() { return {{ "type", "scatter3d" }}; }
    
    Scatter3d& showlegend(bool b = true) { json_["showlegend"] = b; return *this; }
    Scatter3d& legendgroup(std::string_view name) { json_["legendgroup"] = name; return *this; }
    Scatter3d& opacity(double alpha) { json_["opacity"] = alpha; return *this; }
    Scatter3d& stackgroup(std::string_view name) { json_["stackgroup"] = name; return *this; }

    template<class C> Scatter3d& x(const C& data) { json_["x"] = data; return *this; }
    template<class C> Scatter3d& y(const C& data) { json_["y"] = data; return *this; }
    template<class C> Scatter3d& z(const C& data) { json_["z"] = data; return *this; }
    
    Scatter3d& text(std::string_view str) { json_["text"] = str; return *this; }
};

template<> std::string as_string<Scatter3d>() { return "scatter3d"; }

}; // ply

