// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class Shape { Linear, Spline, HV, VH, HVH, VHV };

template<> string as_string<Shape>() { return "shape"; }

core::json as_json(Shape s)
{
    switch (s)
    {
    case Shape::Linear: return "linear";
    case Shape::Spline: return "spline";
    case Shape::HV: return "hv";
    case Shape::VH: return "vh";
    case Shape::HVH: return "hvh";
    case Shape::VHV: return "vhv";
    }
    throw std::runtime_error("Shape::as_json: unknown enum value");
}

}; // ply

