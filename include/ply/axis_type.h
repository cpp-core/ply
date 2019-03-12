// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class AxisType { Dash, Linear, Log, Date, Category, MultiCategory };

template<> inline string as_string<AxisType>() { return "type"; }

inline core::json as_json(AxisType o)
{
    switch (o)
    {
    case AxisType::Dash: return "-";
    case AxisType::Linear: return "linear";
    case AxisType::Log: return "log";
    case AxisType::Date: return "date";
    case AxisType::Category: return "category";
    case AxisType::MultiCategory: return "multicategory";
    }
    throw std::runtime_error("AxisType::as_json: unknown enum value");
}

}; // ply

