// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"
#include "core/pp.h"

#define PLY_ENUM_CASE(name, seq) case name::HEAD_SEQ(seq): return SECOND_SEQ(seq);

#define PLY_ENUM_DECL(name, jname, seq)						\
    namespace ply {							\
    enum class name { MAP_INFIX_SEQ(HEAD_SEQ, COMMA, seq) };		\
    template<> inline string as_string<name>() { return jname; }	\
    inline core::json as_json(name o) {					\
    	switch(o) { MAP_WITH_SEQ(PLY_ENUM_CASE,name,seq) }		\
     	throw std::runtime_error(#name "::as_json: unknown enum value"); \
    }}; // ply

#define PLY_DEFINE_ENUM(seq) EVAL(PLY_ENUM_DECL(HEAD_SEQ(seq), SECOND_SEQ(seq), THIRD_SEQ(seq)))

#define PLY_ENUM_ANCHOR \
    (Anchor, "anchor", ((Auto, "auto"), (Left, "left"), (Center, "center"), (Right, "right")))
PLY_DEFINE_ENUM(PLY_ENUM_ANCHOR)

#define PLY_ENUM_AUTO_RANGE \
    (AutoRange, "autorange", ((True, true), (False, false), (Reversed, "reversed")))
PLY_DEFINE_ENUM(PLY_ENUM_AUTO_RANGE)

#define PLY_ENUM_AXIS_TYPE \
    (AxisType, "type", ((Dash, "-"), (Linear, "linear"), (Log, "log"), (Date, "date"),\
	(Category, "category"), (MultiCategory, "multicategory")))
PLY_DEFINE_ENUM(PLY_ENUM_AXIS_TYPE)

#define PLY_ENUM_DASH \
    (Dash, "dash", ((Solid, "solid"), (Dot, "dot"), (Dash, "dash"), (LongDash, "longdash"), \
	(DashDot, "dashdot"), (LongDashDot, "longdashdot")))
PLY_DEFINE_ENUM(PLY_ENUM_DASH)

#define PLY_ENUM_GROUP_NORM \
    (GroupNorm, "groupnorm", ((None, ""), (Fraction, "fraction"), (Percent, "percent")))
PLY_DEFINE_ENUM(PLY_ENUM_GROUP_NORM)

#define PLY_ENUM_ORIENTATION (Orientation, "orientation", ((H, "h"), (V, "v")))
PLY_DEFINE_ENUM(PLY_ENUM_ORIENTATION)

#define PLY_ENUM_REF (Ref, "ref", ((Container, "container"), (Paper, "paper")))
PLY_DEFINE_ENUM(PLY_ENUM_REF)

#define PLY_ENUM_RANGE_MODE \
    (RangeMode, "rangemode", ((Normal,"normal"), (ToZero,"tozero"), (NonNegative,"nonnegative")))
PLY_DEFINE_ENUM(PLY_ENUM_RANGE_MODE)

#define PLY_ENUM_SHAPE \
    (Shape, "shape", ((Linear, "linear"), (Spline, "spline"), (HV, "hv"), (VH, "vh"),\
		      (HVH, "hvh"), (VHV, "vhv")))
PLY_DEFINE_ENUM(PLY_ENUM_SHAPE)

#define PLY_ENUM_TICK_MODE \
    (TickMode, "tickmode", ((Auto, "auto"), (Linear, "linear"), (Array, "array")))
PLY_DEFINE_ENUM(PLY_ENUM_TICK_MODE)
    

#undef PLY_DEFINE_ENUM
#undef PLY_ENUM_DECL
#undef PLY_ENUM_CASE

