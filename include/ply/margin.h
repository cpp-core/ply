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
    
    template<class T> Margin& t(T px) { json_["t"] = px; return *this; }
    template<class T> Margin& r(T px) { json_["r"] = px; return *this; }
    template<class T> Margin& b(T px) { json_["b"] = px; return *this; }
    template<class T> Margin& l(T px) { json_["l"] = px; return *this; }
    Margin& autoexpand(bool autoexpand) { json_["autoexpand"] = autoexpand; return *this; }
};

template<> inline std::string as_string<Margin>() { return "margin"; }
inline json as_json(const Margin& margin) { return margin.json_; }

}; // ply

