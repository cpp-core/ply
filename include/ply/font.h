// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"

namespace ply
{

struct Font : virtual Data
{
    Font& family(string_view s) { json["family"] = s; return *this; }
    Font& arial() { json["family"] = "arial"; return *this; }
    Font& balto() { json["family"] = "balto"; return *this; }
    Font& courierNew() { json["family"] = "courier new"; return *this; }
    Font& driodSans() { json["family"] = "droid sans"; return *this; }
    Font& driodSerif() { json["family"] = "droid serif"; return *this; }
    Font& driodSansMono() { json["family"] = "droid sans mono"; return *this; }
    Font& gravitasOne() { json["family"] = "gravitas one"; return *this; }
    Font& oldStandardTT() { json["family"] = "old standard tt"; return *this; }
    Font& openSans() { json["family"] = "opens sans"; return *this; }
    Font& overpass() { json["family"] = "overpass"; return *this; }
    Font& ptSansNarrow() { json["family"] = "pt sans narrow"; return *this; }
    Font& raleway() { json["family"] = "raleway"; return *this; }
    Font& timeNewRoman() { json["family"] = "time new roman"; return *this; }
    Font& verdana() { json["family"] = "verdana"; return *this; }
    
    Font& size(uint n) { json["size"] = n; return *this; }
    Font& color(const Color& color) { json["color"] = as_json(color); return *this; }
};

template<> inline string as_string<Font>() { return "font"; }
inline core::json as_json(const Font& font) { return font.json; }

}; // ply

