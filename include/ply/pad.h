// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Pad : virtual Data
{
    template<class T> Pad& t(T px) { json_["t"] = px; return *this; }
    template<class T> Pad& r(T px) { json_["r"] = px; return *this; }
    template<class T> Pad& b(T px) { json_["b"] = px; return *this; }
    template<class T> Pad& l(T px) { json_["l"] = px; return *this; }
};

template<> inline std::string as_string<Pad>() { return "pad"; }
inline json as_json(const Pad& pad) { return pad.json_; }

}; // ply

