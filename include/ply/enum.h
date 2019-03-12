// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"
#include "core/pp.h"

#define CODE_CASE(name, seq) case name::HEAD_SEQ(seq): return SECOND_SEQ(seq);

#define CODE(name, jname, seq)						\
    namespace ply {							\
    enum class name { MAP_INFIX_SEQ(HEAD_SEQ, COMMA, seq) };		\
    template<> inline string as_string<name>() { return jname; }	\
    inline core::json as_json(name o) {					\
    	switch(o) { MAP_WITH_SEQ(CODE_CASE,name,seq) }			\
     	throw std::runtime_error(#name "::as_json: unknown enum value"); \
    }}; // ply

// Anchor
EVAL(CODE(Anchor, "anchor",
	  ((Auto, "auto"),
	   (Left, "left"),
	   (Center, "center"),
	   (Right, "right"))))

// AutoRange
EVAL(CODE(AutoRange, "autorange",
	  ((True, true),
	   (False, false),
	   (Reversed, "reversed"))))

// AxisType
EVAL(CODE(AxisType, "type",
	  ((Dash, "-"),
	   (Linear, "linear"),
	   (Log, "log"),
	   (Date, "date"),
	   (Category, "category"),
	   (MultiCategory, "multicategory"))))

// Dash
EVAL(CODE(Dash, "dash", 
	  ((Solid, "solid"),
	   (Dot, "dot"),
	   (Dash, "dash"),
	   (LongDash, "longdash"),
	   (DashDot, "dashdot"),
	   (LongDashDot, "longdashdot"))))

// GroupNorm
EVAL(CODE(GroupNorm, "groupnorm",
	  ((None, ""),
	   (Fraction, "fraction"),
	   (Percent, "percent"))))

// Orientation
EVAL(CODE(Orientation, "orientation",
	  ((H, "h"),
	   (V, "v"))))

// Ref
EVAL(CODE(Ref, "ref",
	  ((Container, "container"),
	   (Paper, "paper"))))

// RangeMode
EVAL(CODE(RangeMode, "rangemode",
	  ((Normal,"normal"),
	   (ToZero,"tozero"),
	   (NonNegative,"nonnegative"))))

// Shape
EVAL(CODE(Shape, "shape",
	  ((Linear, "linear"),
	   (Spline, "spline"),
	   (HV, "hv"),
	   (VH, "vh"),
	   (HVH, "hvh"),
	   (VHV, "vhv"))))

// TickMode
EVAL(CODE(TickMode, "tickmode",
	  ((Auto, "auto"),
	   (Linear, "linear"),
	   (Array, "array"))))

#undef CODE
#undef CODE_CASE

