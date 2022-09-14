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

struct Contour : Members<Contour,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>, Trace
{
    using MembersBase = Members<Contour,Color,GroupNorm,Line,Mode,Name,Orientation,PlotVisible>;
    using MembersBase::MembersBase;
    
    Contour() { json_ = base(); }
    static json base() { return {{ "type", "contour" }}; }

    Contour& xaxis(const std::string& axis) { json_["xaxis"] = axis; return *this; }
    Contour& yaxis(const std::string& axis) { json_["yaxis"] = axis; return *this; }
    Contour& showlegend(bool b = true) { json_["showlegend"] = b; return *this; }
    Contour& legendgroup(std::string_view name) { json_["legendgroup"] = name; return *this; }
    Contour& opacity(double alpha) { json_["opacity"] = alpha; return *this; }
    Contour& stackgroup(std::string_view name) { json_["stackgroup"] = name; return *this; }

    template<class C> Contour& x(const C& data) { json_["x"] = data; return *this; }
    template<class T> Contour& x0(T x0) { json_["x0"] = x0; return *this; }
    template<class T> Contour& dx(T dx) { json_["dx"] = dx; return *this; }
    
    template<class C> Contour& y(const C& data) { json_["y"] = data; return *this; }
    template<class T> Contour& y0(T y0) { json_["y0"] = y0; return *this; }
    template<class T> Contour& dy(T dy) { json_["dy"] = dy; return *this; }

    template<class C> Contour& z(const C& data) { json_["z"] = data; return *this; }
    
    Contour& text(std::string_view str) { json_["text"] = str; return *this; }
};

template<> std::string as_string<Contour>() { return "contour"; }

}; // ply

