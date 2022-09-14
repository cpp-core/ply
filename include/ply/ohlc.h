// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include "ply/enum.h"
#include "ply/line.h"
#include "ply/members.h"
#include "ply/name.h"

namespace ply
{

struct OHLC : Members<OHLC,Color,Line,Name,PlotVisible>, Trace
{
    using MembersBase = Members<OHLC,Color,Line,Name,PlotVisible>;
    using MembersBase::MembersBase;
    
    OHLC() { json_ = base(); }
    static json base() { return {{ "type", "ohlc" }}; }

    OHLC& showlegend(bool b = true) { json_["showlegend"] = b; return *this; }
    OHLC& legendgroup(std::string_view name) { json_["legendgroup"] = name; return *this; }
    OHLC& opacity(double alpha) { json_["opacity"] = alpha; return *this; }
    OHLC& stackgroup(std::string_view name) { json_["stackgroup"] = name; return *this; }
    OHLC& text(std::string_view str) { json_["text"] = str; return *this; }

    template<class C> OHLC& x(const C& data) { json_["x"] = data; return *this; }
    template<class C> OHLC& open(const C& data) { json_["open"] = data; return *this; }
    template<class C> OHLC& high(const C& data) { json_["high"] = data; return *this; }
    template<class C> OHLC& low(const C& data) { json_["low"] = data; return *this; }
    template<class C> OHLC& close(const C& data) { json_["close"] = data; return *this; }
};

template<> inline std::string as_string<OHLC>() { return "ohlc"; }

}; // ply

