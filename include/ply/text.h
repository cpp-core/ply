// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Text : virtual Data
{
    Text(std::string_view text) { json_ = text; }
};

template<> inline std::string as_string<Text>() { return "text"; }
inline json as_json(const Text& text) { return text.json_; }

}; // ply

