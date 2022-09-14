// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Range : virtual Data
{
    template<class C>
    Range(const C& data) { json_ = data; }
};

template<> inline std::string as_string<Range>() { return "range"; }
inline json as_json(const Range& range) { return range.json_; }

}; // ply

