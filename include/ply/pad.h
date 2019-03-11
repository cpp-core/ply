// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Pad
{
    Pad() { json = core::json::object(); }
    template<Arithmetic T> Pad& t(T px) { json["t"] = px; return *this; }
    template<Arithmetic T> Pad& r(T px) { json["r"] = px; return *this; }
    template<Arithmetic T> Pad& b(T px) { json["b"] = px; return *this; }
    template<Arithmetic T> Pad& l(T px) { json["l"] = px; return *this; }
    core::json json;
};

template<> inline string as_string<Pad>() { return "pad"; }
inline core::json as_json(const Pad& pad) { return pad.json; }

}; // ply
