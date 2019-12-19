// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/font.h"
#include "ply/members.h"
#include "ply/pad.h"
#include "ply/text.h"

namespace ply
{

struct Title : Members<Title,Font,Pad,Text,XAnchor,YAnchor>, virtual Data
{
    using MembersBase = Members<Title,Font,Pad,Text,XAnchor,YAnchor>;
    using MembersBase::MembersBase;
    
    Title& xRef(Ref xref) { json["xref"] = as_json(xref); return *this; }
    Title& yRef(Ref yref) { json["yref"] = as_json(yref); return *this; }
    template<class T> Title& x(T x) { json["x"] = x; return *this; }
    template<class T> Title& y(T y) { json["y"] = y; return *this; }
};

template<> inline string as_string<Title>() { return "title"; }
inline nlj::json as_json(const Title& title) { return title.json; }

}; // ply

