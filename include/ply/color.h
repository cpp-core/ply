// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include <fmt/format.h>
#include "ply/base.h"

namespace ply
{

struct RGB
{
    RGB(int arg_red, int arg_green, int arg_blue)
	: red(arg_red)
	, green(arg_green)
	, blue(arg_blue)
    { }
    int red, green, blue;
};

struct RGBA
{
    RGBA(int arg_red, int arg_green, int arg_blue, double arg_alpha)
	: red(arg_red)
	, green(arg_green)
	, blue(arg_blue)
	, alpha(arg_alpha)
    { }
    int red, green, blue;
    double alpha;
};

struct Color : virtual Data
{
    Color()
    { }
    
    Color(const RGB& c)
    { rgb(c.red, c.green, c.blue); }

    Color(const RGBA& c)
    { rgba(c.red, c.green, c.blue, c.alpha); }

    Color& rgb(int red, int green, int blue)
    { json_ = fmt::format("rgb({:d},{:d},{:d})", red, green, blue); return *this; }
    
    Color& rgba(int red, int green, int blue, double alpha)
    { json_ = fmt::format("rgba({:d},{:d},{:d},{})", red, green, blue, alpha); return *this; }
};

template<> inline std::string as_string<Color>() { return "color"; }
inline json as_json(const Color& c) { return c.json_; }

}; // ply

