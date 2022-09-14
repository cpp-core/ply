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
    static json base() { return json::object(); }

    Members()
    { }

    template<class... Us>
    requires (core::mp::is_member_v<Us,Ts...> && ...)
    Members(const Us&... obj)
    {
	json_ = D::base();
	((json_[as_string<Us>()] = as_json(obj)), ...);
    }

    template<class... Us>
    requires (core::mp::is_member_v<Us,Ts...> && ...)
    D& operator()(const Us&... obj)
    {
	((json_[as_string<Us>()] = as_json(obj)), ...);
	return *static_cast<D*>(this);
    }
};

}; // ply

