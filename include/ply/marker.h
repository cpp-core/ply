// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/color.h"
#include "ply/enum.h"
#include "ply/line.h"
#include "ply/members.h"

namespace ply
{

struct Marker : Members<Marker,Color,Line,Symbol>, virtual Data
{
    using MembersBase = Members<Marker,Color,Line,Symbol>;
    using MembersBase::MembersBase;
    
    template<class T>
    Marker& size(T w) { json_["size"] = w; return *this; }
};

template<> inline std::string as_string<Marker>() { return "marker"; }
inline json as_json(const Marker& marker) { return marker.json_; }

}; // ply

