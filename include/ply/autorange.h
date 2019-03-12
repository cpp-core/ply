// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class AutoRange { True, False, Reversed };

template<> inline string as_string<AutoRange>() { return "autorange"; }

inline core::json as_json(AutoRange o)
{
    switch (o)
    {
    case AutoRange::True: return true;
    case AutoRange::False: return false;
    case AutoRange::Reversed: return "reversed";
    }
    throw std::runtime_error("AutoRange::as_json: unknown enum value");
}

}; // ply

