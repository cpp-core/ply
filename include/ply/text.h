// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Text : virtual Data
{
    Text(string_view text) { json = text; }
};

template<> inline string as_string<Text>() { return "text"; }
inline nlj::json as_json(const Text& text) { return text.json; }

}; // ply

