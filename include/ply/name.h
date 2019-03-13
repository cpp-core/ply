// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Name : virtual Data
{
    Name(string_view name) { json = name; }
};

template<> inline string as_string<Name>() { return "name"; }
inline core::json as_json(const Name& name) { return name.json; }

}; // ply

