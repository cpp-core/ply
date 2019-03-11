// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/anchor.h"
#include "ply/font.h"
#include "ply/pad.h"
#include "ply/ref.h"
#include "core/mp/contains.h"

namespace ply
{

struct Title
{
    Title() { json = core::json::object(); }
    Title& text(string_view text) { json["text"] = text; return *this; }
    Title& xRef(Ref xref) { json["xref"] = as_json(xref); return *this; }
    Title& yRef(Ref yref) { json["yref"] = as_json(yref); return *this; }
    template<Arithmetic T> Title& x(T x) { json["x"] = x; return *this; }
    template<Arithmetic T> Title& y(T y) { json["y"] = y; return *this; }
    Title& xAnchor(Anchor xanchor) { json["xanchor"] = as_json(xanchor); return *this; }
    Title& yAnchor(Anchor yanchor) { json["yanchor"] = as_json(yanchor); return *this; }

    template<class T>
    requires core::mp::is_member_v<T,Font,Pad>
    Title& operator()(const T& obj) { json[as_string<T>()] = as_json(obj); return *this; }
    
    core::json json;
};

template<> inline string as_string<Title>() { return "title"; }
inline core::json as_json(const Title& title) { return title.json; }

}; // ply

