// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include "core/utility/common.h"
#include "core/json/nljson.h"

namespace ply
{

template<class T> string as_string();

struct Data
{
    Data() { json = nlj::json::object(); }
    nlj::json json;
};

struct Trace : virtual Data { };
using Traces = vector<Trace>;

}; // ply

