// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "core/common.h"
#include "core/json.h"
#include "core/mp/append.h"
#include "core/mp/contains.h"

namespace ply
{

template<class... Ts> 
using list = core::mp::list<Ts...>;

template<class... Ts>
using append_t = core::mp::append_t<Ts...>;

template<class T> string as_string();

struct Data
{
    Data() { json = core::json::object(); }
    core::json json;
};

struct Trace : virtual Data { };
using Traces = vector<Trace>;

template<class D, class... Ts>
struct Members : virtual Data
{
    static core::json base() { return core::json::object(); }

    Members()
    { }

    template<class... Us>
    requires (core::mp::is_member_v<Us,Ts...> && ...)
    Members(const Us&... obj)
    {
	json = D::base();
	((json[as_string<Us>()] = as_json(obj)), ...);
    }

    template<class... Us>
    requires (core::mp::is_member_v<Us,Ts...> && ...)
    D& operator()(const Us&... obj)
    {
	((json[as_string<Us>()] = as_json(obj)), ...);
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

