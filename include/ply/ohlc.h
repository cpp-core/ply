// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/line.h"
#include "ply/group_norm.h"
#include "ply/orientation.h"
#include "core/mp/contains.h"

namespace ply
{

struct OHLC
{
    OHLC() { json = {{ "type", "ohlc" }}; }

    OHLC& visible(bool b) { json["visible"] = b; return *this; }
    OHLC& visible_legend() { json["visible"] = "legendonly"; return *this; }
    OHLC& showlegend(bool b = true) { json["showlegend"] = b; return *this; }
    OHLC& legendgroup(string_view name) { json["legendgroup"] = name; return *this; }
    OHLC& opacity(real alpha) { json["opacity"] = alpha; return *this; }
    OHLC& name(string_view name) { json["name"] = name; return *this; }
    OHLC& stackgroup(string_view name) { json["stackgroup"] = name; return *this; }
    OHLC& text(string_view str) { json["text"] = str; return *this; }

    template<class C> OHLC& x(const C& data) { json["x"] = data; return *this; }
    template<class C> OHLC& open(const C& data) { json["open"] = data; return *this; }
    template<class C> OHLC& high(const C& data) { json["high"] = data; return *this; }
    template<class C> OHLC& low(const C& data) { json["low"] = data; return *this; }
    template<class C> OHLC& close(const C& data) { json["close"] = data; return *this; }

    template<class T>
    requires core::mp::is_member_v<T,Color,Line>
    OHLC& set(T obj) { json[as_string<T>()] = as_json(obj); return *this; }

    core::json json;
};

template<> string as_string<OHLC>() { return "ohlc"; }

}; // ply

