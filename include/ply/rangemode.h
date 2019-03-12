// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class RangeMode { Normal, ToZero, NonNegative };

template<> inline string as_string<RangeMode>() { return "rangemode"; }

inline core::json as_json(RangeMode o)
{
    switch (o)
    {
    case RangeMode::Normal: return "normal";
    case RangeMode::ToZero: return "tozero";
    case RangeMode::NonNegative: return "nonnegative";
    }
    throw std::runtime_error("RangeMode::as_json: unknown enum value");
}

}; // ply

