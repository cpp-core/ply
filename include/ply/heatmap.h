// Copyright (C) 2019, 2021, 2022 by Mark Melton
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
    
    HeatMap() { json_ = base(); }
    static json base() { return {{ "type", "heatmap" }}; }

    HeatMap& xaxis(const std::string& axis) { json_["xaxis"] = axis; return *this; }
    HeatMap& yaxis(const std::string& axis) { json_["yaxis"] = axis; return *this; }
    HeatMap& showlegend(bool b = true) { json_["showlegend"] = b; return *this; }
    HeatMap& legendgroup(std::string_view name) { json_["legendgroup"] = name; return *this; }
    HeatMap& opacity(double alpha) { json_["opacity"] = alpha; return *this; }
    HeatMap& stackgroup(std::string_view name) { json_["stackgroup"] = name; return *this; }

    template<class C> HeatMap& x(const C& data) { json_["x"] = data; return *this; }
    template<class T> HeatMap& x0(T x0) { json_["x0"] = x0; return *this; }
    template<class T> HeatMap& dx(T dx) { json_["dx"] = dx; return *this; }
    
    template<class C> HeatMap& y(const C& data) { json_["y"] = data; return *this; }
    template<class T> HeatMap& y0(T y0) { json_["y0"] = y0; return *this; }
    template<class T> HeatMap& dy(T dy) { json_["dy"] = dy; return *this; }

    template<class C> HeatMap& z(const C& data) { json_["z"] = data; return *this; }
    
    HeatMap& text(std::string_view str) { json_["text"] = str; return *this; }
};

template<> std::string as_string<HeatMap>() { return "heatmap"; }

}; // ply

