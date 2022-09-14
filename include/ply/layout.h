// Copyright (C) 2019, 2022 by Mark Melton
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
    
    Layout& width(double px) { json_["width"] = px; return *this; }
    Layout& height(double px) { json_["height"] = px; return *this; }
    Layout& autosize(bool autosize) { json_["autosize"] = autosize; return *this; }
    Layout& paper_bgcolor(const Color& c) { json_["paper_bgcolor"] = as_json(c); return *this; }
    Layout& plot_bgcolor(const Color& c) { json_["plot_bgcolor"] = as_json(c); return *this; }
    Layout& separators(std::string_view sep) { json_["separators"] = sep; return *this; }
    Layout& showlegend(bool showlegend) { json_["showlegend"] = showlegend; return *this; }
};

template<> inline std::string as_string<Layout>() { return "layout"; }
inline json as_json(const Layout& layout) { return layout.json_; }

}; // ply

