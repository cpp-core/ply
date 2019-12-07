// Copyright (C) 2019 by Mark Melton
//

#pragma once
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
    RGBA(int arg_red, int arg_green, int arg_blue, real arg_alpha)
	: red(arg_red)
	, green(arg_green)
	, blue(arg_blue)
	, alpha(arg_alpha)
    { }
    int red, green, blue;
    real alpha;
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
    { json = fmt::format("rgb({:d},{:d},{:d})", red, green, blue); return *this; }
    
    Color& rgba(int red, int green, int blue, real alpha)
    { json = fmt::format("rgba({:d},{:d},{:d},{})", red, green, blue, alpha); return *this; }
};

template<> inline string as_string<Color>() { return "color"; }
inline nlj::json as_json(const Color& c) { return c.json; }

}; // ply

