// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class GroupNorm { None, Fraction, Percent };

string as_string(GroupNorm g)
{
    switch (g)
    {
    case GroupNorm::None: return "";
    case GroupNorm::Fraction: return "fraction";
    case GroupNorm::Percent: return "percent";
    }
    throw std::runtime_error("GroupNorm::as_string: unknown enum value");
}

}; // ply

