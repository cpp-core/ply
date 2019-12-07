// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"
#include "core/mp/contains.h"

namespace ply
{

template<class D, class... Ts>
struct Members : virtual Data
{
    static nlj::json base() { return nlj::json::object(); }

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

}; // ply

