// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/members.h"
#include "ply/pad.h"

namespace ply
{

struct Margin : Members<Margin,Pad>, virtual Data
{
    using MembersBase = Members<Margin,Pad>;
    using MembersBase::MembersBase;
    
    template<Arithmetic T> Margin& t(T px) { json["t"] = px; return *this; }
    template<Arithmetic T> Margin& r(T px) { json["r"] = px; return *this; }
    template<Arithmetic T> Margin& b(T px) { json["b"] = px; return *this; }
    template<Arithmetic T> Margin& l(T px) { json["l"] = px; return *this; }
    Margin& autoexpand(bool autoexpand) { json["autoexpand"] = autoexpand; return *this; }
};

template<> inline string as_string<Margin>() { return "margin"; }
inline core::json as_json(const Margin& margin) { return margin.json; }

}; // ply

