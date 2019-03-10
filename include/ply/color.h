// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

struct Color
{
    Color() = default;
    
    Color& rgb(int red, int green, int blue)
    { json = fmt::format("rgb({:d},{:d},{:d})", red, green, blue); return *this; }
    
    Color& rgba(int red, int green, int blue, real alpha)
    { json = fmt::format("rgb({:d},{:d},{:d},{})", red, green, blue, alpha); return *this; }
    
    core::json json;
};

}; // ply

