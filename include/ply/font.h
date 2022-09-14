// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"

namespace ply
{

struct Font : virtual Data
{
    Font& family(std::string_view s) { json_["family"] = s; return *this; }
    Font& arial() { json_["family"] = "arial"; return *this; }
    Font& balto() { json_["family"] = "balto"; return *this; }
    Font& courierNew() { json_["family"] = "courier new"; return *this; }
    Font& driodSans() { json_["family"] = "droid sans"; return *this; }
    Font& driodSerif() { json_["family"] = "droid serif"; return *this; }
    Font& driodSansMono() { json_["family"] = "droid sans mono"; return *this; }
    Font& gravitasOne() { json_["family"] = "gravitas one"; return *this; }
    Font& oldStandardTT() { json_["family"] = "old standard tt"; return *this; }
    Font& openSans() { json_["family"] = "opens sans"; return *this; }
    Font& overpass() { json_["family"] = "overpass"; return *this; }
    Font& ptSansNarrow() { json_["family"] = "pt sans narrow"; return *this; }
    Font& raleway() { json_["family"] = "raleway"; return *this; }
    Font& timeNewRoman() { json_["family"] = "time new roman"; return *this; }
    Font& verdana() { json_["family"] = "verdana"; return *this; }
    
    Font& size(uint n) { json_["size"] = n; return *this; }
    Font& color(const Color& color) { json_["color"] = as_json(color); return *this; }
};

template<> inline std::string as_string<Font>() { return "font"; }
inline json as_json(const Font& font) { return font.json_; }

}; // ply

