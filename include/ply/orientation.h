// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class Orientation { H, V };

template<> inline string as_string<Orientation>() { return "orientation"; }

inline core::json as_json(Orientation o)
{
    switch (o)
    {
    case Orientation::H: return "h";
    case Orientation::V: return "v";
    }
    throw std::runtime_error("Orientation::as_json: unknown enum value");
}

}; // ply

