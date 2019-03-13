// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "core/common.h"
#include "core/json.h"

namespace ply
{

template<class T> string as_string();

struct Data
{
    Data() { json = core::json::object(); }
    core::json json;
};

struct Trace : virtual Data { };
using Traces = vector<Trace>;

template<class Derived>
struct Range : virtual Data
{
    template<class C>
    Derived& range(const C& data) { json["range"] = data; return *static_cast<Derived*>(this); }
};

}; // ply

