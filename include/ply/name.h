// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Name : virtual Data
{
    Name(std::string_view name) { json_ = name; }
};

template<> inline std::string as_string<Name>() { return "name"; }
inline json as_json(const Name& name) { return name.json_; }

}; // ply

