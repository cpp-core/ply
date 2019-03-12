// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class TickMode { Auto, Linear, Array };

template<> inline string as_string<TickMode>() { return "tickmode"; }

inline core::json as_json(TickMode o)
{
    switch (o)
    {
    case TickMode::Auto: return "auto";
    case TickMode::Linear: return "linear";
    case TickMode::Array: return "array";
    }
    throw std::runtime_error("TickMode::as_json: unknown enum value");
}

}; // ply


