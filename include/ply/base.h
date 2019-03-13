// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "core/common.h"
#include "core/json.h"
#include "core/mp/contains.h"

namespace ply
{

template<class... Ts> 
using list = core::mp::list<Ts...>;

template<class T> string as_string();

struct Data
{
    Data() { json = core::json::object(); }
    core::json json;
};

struct Trace : virtual Data { };
using Traces = vector<Trace>;

template<class D, class L>
struct Member : virtual Data
{
    template<class T>
    requires core::mp::contains_v<T,L>
    D& operator()(const T& obj)
    {
	json[as_string<T>()] = as_json(obj);
	return *static_cast<D*>(this);
    }
};

template<class Derived>
struct Range : virtual Data
{
    template<class C>
    Derived& range(const C& data) { json["range"] = data; return *static_cast<Derived*>(this); }
};

}; // ply

