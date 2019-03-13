// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/font.h"
#include "ply/members.h"
#include "ply/pad.h"

namespace ply
{

template<class D>
struct Text : virtual Data
{
    D& text(string_view text) { json["text"] = text; return *static_cast<D*>(this); }
};

struct Title : Members<Title,Font,Pad,XAnchor,YAnchor>, Text<Title>, virtual Data
{
    using MembersBase = Members<Title,Font,Pad,XAnchor,YAnchor>;
    using MembersBase::MembersBase;
    
    Title(string_view text) { json["text"] = text; }
    Title& xRef(Ref xref) { json["xref"] = as_json(xref); return *this; }
    Title& yRef(Ref yref) { json["yref"] = as_json(yref); return *this; }
    template<Arithmetic T> Title& x(T x) { json["x"] = x; return *this; }
    template<Arithmetic T> Title& y(T y) { json["y"] = y; return *this; }
};

template<> inline string as_string<Title>() { return "title"; }
inline core::json as_json(const Title& title) { return title.json; }

}; // ply

