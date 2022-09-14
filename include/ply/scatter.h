// Copyright (C) 2019, 2022 by Mark Melton
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
    
    Scatter() { json_ = base(); }
    static json base() { return {{ "type", "scatter" }}; }

    Scatter& xaxis(const std::string& axis) { json_["xaxis"] = axis; return *this; }
    Scatter& yaxis(const std::string& axis) { json_["yaxis"] = axis; return *this; }
    Scatter& showlegend(bool b = true) { json_["showlegend"] = b; return *this; }
    Scatter& legendgroup(std::string_view name) { json_["legendgroup"] = name; return *this; }
    Scatter& opacity(double alpha) { json_["opacity"] = alpha; return *this; }
    Scatter& stackgroup(std::string_view name) { json_["stackgroup"] = name; return *this; }

    template<class C> Scatter& x(const C& data) { json_["x"] = data; return *this; }
    template<class T> Scatter& x0(T x0) { json_["x0"] = x0; return *this; }
    template<class T> Scatter& dx(T dx) { json_["dx"] = dx; return *this; }
    
    template<class C> Scatter& y(const C& data) { json_["y"] = data; return *this; }
    template<class T> Scatter& y0(T y0) { json_["y0"] = y0; return *this; }
    template<class T> Scatter& dy(T dy) { json_["dy"] = dy; return *this; }

    Scatter& text(std::string_view str) { json_["text"] = str; return *this; }
};

template<> std::string as_string<Scatter>() { return "scatter"; }

}; // ply

