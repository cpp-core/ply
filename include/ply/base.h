// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "core/common.h"
#include "core/json.h"

namespace ply
{

template<class T> string as_string();

struct Trace
{ core::json json; };

using Traces = vector<Trace>;

struct Layout
{ core::json json; };

}; // ply

