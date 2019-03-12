// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/font.h"
#include "ply/margin.h"
#include "ply/title.h"
#include "core/mp/contains.h"

namespace ply
{

struct Layout
{
    Layout() { json = core::json::object(); }

    Layout& width(real px) { json["width"] = px; return *this; }
    Layout& height(real px) { json["height"] = px; return *this; }
    Layout& autosize(bool autosize) { json["autosize"] = autosize; return *this; }
    Layout& width(uint pixels) { json["width"] = pixels; return *this; }
    Layout& height(uint pixels) { json["height"] = pixels; return *this; }
    Layout& paper_bgcolor(const Color& c) { json["paper_bgcolor"] = as_json(c); return *this; }
    Layout& plot_bgcolor(const Color& c) { json["plot_bgcolor"] = as_json(c); return *this; }
    Layout& separators(string_view sep) { json["separators"] = sep; return *this; }
    Layout& showlegend(bool showlegend) { json["showlegend"] = showlegend; return *this; }

    
    template<class T>
    requires core::mp::is_member_v<T,Font,Margin,Title>
    Layout& operator()(const T& obj) { json[as_string<T>()] = as_json(obj); return *this; }
    
    core::json json;
};

template<> inline string as_string<Layout>() { return "layout"; }
inline core::json as_json(const Layout& layout) { return layout.json; }

}; // ply

