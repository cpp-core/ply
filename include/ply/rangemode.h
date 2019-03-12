// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"
#include "core/pp.h"

// namespace ply
// {

// enum class RangeMode { Normal, ToZero, NonNegative };

// template<> inline string as_string<RangeMode>() { return "rangemode"; }

// inline core::json as_json(RangeMode o)
// {
//     switch (o)
//     {
//     case RangeMode::Normal: return "normal";
//     case RangeMode::ToZero: return "tozero";
//     case RangeMode::NonNegative: return "nonnegative";
//     }
//     throw std::runtime_error("RangeMode::as_json: unknown enum value");
// }

// }; // ply

#define CODE_CASE(name, seq) case name::HEAD_SEQ(seq): return SECOND_SEQ(seq);

#define CODE(name, jname, seq)						\
    namespace ply {							\
    enum class name { MAP_INFIX_SEQ(HEAD_SEQ, COMMA, seq) };		\
    template<> inline string as_string<name>() { return jname; }	\
    inline core::json as_json(name o) {					\
    	switch(o) { MAP_WITH_SEQ(CODE_CASE,name,seq) }			\
     	throw std::runtime_error(#name "::as_json: unknown enum value"); \
    }}; // ply 

EVAL(CODE(RangeMode, "rangemode", ((Normal,"normal"),(ToZero,"tozero"),(NonNegative,"nonnegative"))))



