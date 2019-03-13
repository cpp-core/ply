// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/line.h"
#include "ply/members.h"

namespace ply
{

struct OHLC : Members<OHLC,Color,Line,PlotVisible>, Trace
{
    using MembersBase = Members<OHLC,Color,Line,PlotVisible>;
    using MembersBase::MembersBase;
    
    OHLC() { json = base(); }
    static core::json base() { return {{ "type", "ohlc" }}; }

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
};

template<> inline string as_string<OHLC>() { return "ohlc"; }

}; // ply

