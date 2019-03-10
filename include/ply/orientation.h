// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class Orientation { H, V };

template<class T> string as_string();
template<> string as_string<Orientation>() { return "orientation"; }

string as_string(Orientation o)
{
    switch (o)
    {
    case Orientation::H: return "h";
    case Orientation::V: return "v";
    }
    throw std::runtime_error("Orientation::as_string: unknown enum value");
}

}; // ply

