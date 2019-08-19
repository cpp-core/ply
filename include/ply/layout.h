// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/font.h"
#include "ply/margin.h"
#include "ply/members.h"
#include "ply/scene.h"
#include "ply/title.h"
#include "ply/xaxis.h"
#include "ply/yaxis.h"

namespace ply
{

struct Layout : Members<Layout,Font,Margin,Scene,Title,XAxis,YAxis>, virtual Data
{
    using MembersBase = Members<Layout,Font,Margin,Scene,Title,XAxis,YAxis>;
    using MembersBase::MembersBase;
    
    Layout& width(real px) { json["width"] = px; return *this; }
    Layout& height(real px) { json["height"] = px; return *this; }
    Layout& autosize(bool autosize) { json["autosize"] = autosize; return *this; }
    Layout& paper_bgcolor(const Color& c) { json["paper_bgcolor"] = as_json(c); return *this; }
    Layout& plot_bgcolor(const Color& c) { json["plot_bgcolor"] = as_json(c); return *this; }
    Layout& separators(string_view sep) { json["separators"] = sep; return *this; }
    Layout& showlegend(bool showlegend) { json["showlegend"] = showlegend; return *this; }
};

template<> inline string as_string<Layout>() { return "layout"; }
inline core::json as_json(const Layout& layout) { return layout.json; }

}; // ply

