// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class Dash { Solid, Dot, Dash, LongDash, DashDot, LongDashDot };

template<> string as_string<Dash>() { return "dash"; }

string as_string(Dash d)
{
    switch (d)
    {
    case Dash::Solid: return "solid";
    case Dash::Dot: return "dot";
    case Dash::Dash: return "dash";
    case Dash::LongDash: return "longdash";
    case Dash::DashDot: return "dashdot";
    case Dash::LongDashDot: return "longdashdot";
    }
    throw std::runtime_error("Dash::as_string: unknown enum value");
}

}; // ply

