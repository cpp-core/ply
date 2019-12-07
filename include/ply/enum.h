// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"
#include "core/pp/eval.h"
#include "core/pp/map.h"
#include "core/pp/seq.h"

#define PLY_ENUM_CASE(name, seq) case name::CORE_PP_HEAD_SEQ(seq): return CORE_PP_SECOND_SEQ(seq);

#define PLY_ENUM_DECL(name, jname, seq)					\
    namespace ply {							\
    enum class name { CORE_PP_MAP_INFIX_SEQ(CORE_PP_HEAD_SEQ, CORE_PP_COMMA, seq) }; \
    template<> inline string as_string<name>() { return jname; }	\
    inline nlj::json as_json(name o) {					\
    	switch(o) { CORE_PP_MAP_WITH_SEQ(PLY_ENUM_CASE,name,seq) }	\
     	throw std::runtime_error(#name "::as_json: unknown enum value"); \
    }}; // ply

#define PLY_DEFINE_ENUM(seq) \
    CORE_PP_EVAL(PLY_ENUM_DECL(CORE_PP_HEAD_SEQ(seq), CORE_PP_SECOND_SEQ(seq), \
			       CORE_PP_THIRD_SEQ(seq)))

#define PLY_ENUM_AUTO_RANGE \
    (AutoRange, "autorange", ((True, true), (False, false), (Reversed, "reversed")))

#define PLY_ENUM_AXIS_TYPE \
    (AxisType, "type", ((Dash, "-"), (Linear, "linear"), (Log, "log"), (Date, "date"),\
	(Category, "category"), (MultiCategory, "multicategory")))

#define PLY_ENUM_CLICK_MODE \
    (ClickMode, "clickmode", ((Event,"event"), (Select,"select"),\
			      (EventAndSelect, "event+select"), (None, "none")))

#define PLY_ENUM_CONSTRAIN \
    (Constrain, "constrain", ((Range, "range"), (Domain, "domain")))

#define PLY_ENUM_CONSTRAIN_TOWARD \
    (ConstrainToward, "constraintoward", ((Left, "left"), (Center, "center"), (Right, "right"), \
					  (Top, "top"), (Middle, "middle"), (Bottom, "bottom")))

#define PLY_ENUM_DASH \
    (Dash, "dash", ((Solid, "solid"), (Dot, "dot"), (Dash, "dash"), (LongDash, "longdash"), \
	(DashDot, "dashdot"), (LongDashDot, "longdashdot")))

#define PLY_ENUM_DRAG_MODE \
    (DragMode, "dragmode", ((Zoom, "zoom"), (Pan, "pan"), (Select, "select"), (Lasso, "lasso"), \
			   (Orbit, "orbit"), (TurnTable, "turntable"), (False, false)))

#define PLY_ENUM_EXPONENT_FORMAT \
    (ExponentFormat, "exponentformat", ((None, "none"), (e, "e"), (E, "E"), (Power, "power"), \
					(SI, "si"), (B, "B")))

#define PLY_ENUM_FIXED_RANGE \
    (FixedRange, "fixedrange", ((True, true), (False, false)))

#define PLY_ENUM_GROUP_NORM \
    (GroupNorm, "groupnorm", ((None, ""), (Fraction, "fraction"), (Percent, "percent")))

#define PLY_ENUM_HOVER_MODE \
    (HoverMode, "hovermode", ((X, "x"), (Y, "y"), (Closest, "closest"), (False, false)))

#define PLY_ENUM_LAYER \
    (Layer, "layer", ((AboveTraces, "above traces"), (BelowTraces, "below traces")))

#define PLY_ENUM_MIRROR \
    (Mirror, "mirror", ((True, true), (Ticks, "ticks"), (False, false), (All, "all"), \
			(AllTicks, "allticks")))

#define PLY_ENUM_ORIENTATION \
    (Orientation, "orientation", ((H, "h"), (V, "v")))

#define PLY_ENUM_PATTERN \
    (Pattern, "pattern", ((Independent, "independent"), (Coupled, "coupled")))
    
#define PLY_ENUM_PLOT_VISIBLE \
    (PlotVisible, "visible", ((True, true), (False, false), (LegendOnly, "legendonly")))

#define PLY_ENUM_RANGE_MODE \
    (RangeMode, "rangemode", ((Normal,"normal"), (ToZero,"tozero"), (NonNegative,"nonnegative")))

#define PLY_ENUM_REF \
    (Ref, "ref", ((Container, "container"), (Paper, "paper")))

#define PLY_ENUM_ROW_ORDER \
    (RowOrder, "roworder", ((TopToBottom, "top to bottom"), (BottomToTop, "bottom to top")))

#define PLY_ENUM_SELECT_DIRECTION \
    (SelectDirection, "selectdirection", ((H, "h"), (V, "v"), (D, "d"), (Any, "any")))

#define PLY_ENUM_SHAPE \
    (Shape, "shape", ((Linear, "linear"), (Spline, "spline"), (HV, "hv"), (VH, "vh"),\
		      (HVH, "hvh"), (VHV, "vhv")))

#define PLY_ENUM_SHOW_EXPONENT \
    (ShowExponent, "showexponent", ((All, "all"), (First, "first"), (Last, "last"), \
				    (None, "none")))

#define PLY_ENUM_MODE \
    (Mode, "mode", ((None, "none"), (Lines, "lines"), (Markers, "markers"), (Text, "text"), \
		    (LinesAndMarkers, "lines+markers"), (MarkersAndText, "markers+text"), \
		    (LinesAndText, "lines+text"), (All, "lines+markers+text")))

#define PLY_ENUM_SHOW_TICK_PREFIX \
    (ShowTickPrefix, "showtickprefix", ((All, "all"), (First, "first"), (Last, "last"), \
					(None, "none")))

#define PLY_ENUM_SHOW_TICK_SUFFIX \
    (ShowTickSuffix, "showticksuffix", ((All, "all"), (First, "first"), (Last, "last"), \
					(None, "none")))

#define PLY_ENUM_SIDE \
    (Side, "side", ((Top, "top"), (Bottom, "bottom"), (Left, "left"), (Right, "right")))

#define PLY_ENUM_SLIDER_RANGE_MODE \
    (SliderRangeMode, "rangemode", ((Auto,"auto"), (Fixed,"fixed"), (Match,"match")))

#define PLY_ENUM_STEP \
    (Step, "step", ((Month, "month"), (Year, "year"), (Day, "day"), (Hour, "hour"), \
		    (Minute, "minute"), (Second, "second"), (All, "all")))

#define PLY_ENUM_STEP_MODE						\
    (StepMode, "stepmode", ((Backward, "backward"), (ToDate, "todate")))

#define PLY_ENUM_SYMBOL							\
    (Symbol, "symbol", ((Circle, "circle"), (CircleOpen, "circle-open"), (Square, "square"), \
			(SquareOpen, "square-open"), (Diamond, "diamond"), \
			(DiamondOpen, "diamond-open"), (Cross, "cross"), (X, "x")))

#define PLY_ENUM_TITLE_TYPE \
    (TitleType, "type", ((Dash, "-"), (Linear, "linear"), (Log, "log"), (Date, "date"), \
			 (Category, "category"), (MultiCategory, "multicategory")))

#define PLY_ENUM_TICKS \
    (Ticks, "ticks", ((Outside, "outside"), (Inside, "inside"), (None, "")))

#define PLY_ENUM_TICKS_ON \
    (TicksOn, "tickson", ((Labels, "labels"), (Boundaries, "boundaries")))

#define PLY_ENUM_TICK_MODE \
    (TickMode, "tickmode", ((Auto, "auto"), (Linear, "linear"), (Array, "array")))

#define PLY_ENUM_VISIBLE \
    (Visible, "visible", ((True, true), (False, false)))

#define PLY_ENUM_XANCHOR \
    (XAnchor, "xanchor", ((Auto, "auto"), (Left, "left"), (Center, "center"), (Right, "right")))

#define PLY_ENUM_XSIDE \
    (XSide, "xside", ((Bottom, "bottom"), (BottomPlot, "bottom plot"), (TopPlot, "top plot"), \
		      (Top, "top")))

#define PLY_ENUM_YANCHOR \
    (YAnchor, "yanchor", ((Auto, "auto"), (Top, "top"), (Middle, "middle"), (Bottom, "bottom")))

#define PLY_ENUM_YSIDE \
    (YSide, "yside", ((Left, "left"), (LeftPlot, "left plot"), (RightPlot, "right plot"), \
		      (Right, "right")))


PLY_DEFINE_ENUM(PLY_ENUM_AUTO_RANGE)
PLY_DEFINE_ENUM(PLY_ENUM_AXIS_TYPE)
PLY_DEFINE_ENUM(PLY_ENUM_CLICK_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_CONSTRAIN)
PLY_DEFINE_ENUM(PLY_ENUM_CONSTRAIN_TOWARD)
PLY_DEFINE_ENUM(PLY_ENUM_DASH)
PLY_DEFINE_ENUM(PLY_ENUM_DRAG_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_EXPONENT_FORMAT)
PLY_DEFINE_ENUM(PLY_ENUM_FIXED_RANGE)
PLY_DEFINE_ENUM(PLY_ENUM_GROUP_NORM)
PLY_DEFINE_ENUM(PLY_ENUM_HOVER_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_LAYER)
PLY_DEFINE_ENUM(PLY_ENUM_MIRROR)
PLY_DEFINE_ENUM(PLY_ENUM_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_ORIENTATION)
PLY_DEFINE_ENUM(PLY_ENUM_PATTERN)
PLY_DEFINE_ENUM(PLY_ENUM_PLOT_VISIBLE)
PLY_DEFINE_ENUM(PLY_ENUM_RANGE_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_REF)
PLY_DEFINE_ENUM(PLY_ENUM_ROW_ORDER)
PLY_DEFINE_ENUM(PLY_ENUM_SELECT_DIRECTION)
PLY_DEFINE_ENUM(PLY_ENUM_SHAPE)
PLY_DEFINE_ENUM(PLY_ENUM_SHOW_EXPONENT)
PLY_DEFINE_ENUM(PLY_ENUM_SHOW_TICK_PREFIX)
PLY_DEFINE_ENUM(PLY_ENUM_SHOW_TICK_SUFFIX)
PLY_DEFINE_ENUM(PLY_ENUM_SIDE)
PLY_DEFINE_ENUM(PLY_ENUM_SLIDER_RANGE_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_STEP)
PLY_DEFINE_ENUM(PLY_ENUM_STEP_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_SYMBOL)
PLY_DEFINE_ENUM(PLY_ENUM_TICKS)
PLY_DEFINE_ENUM(PLY_ENUM_TICKS_ON)
PLY_DEFINE_ENUM(PLY_ENUM_TICK_MODE)
PLY_DEFINE_ENUM(PLY_ENUM_TITLE_TYPE)
PLY_DEFINE_ENUM(PLY_ENUM_VISIBLE)
PLY_DEFINE_ENUM(PLY_ENUM_XANCHOR)
PLY_DEFINE_ENUM(PLY_ENUM_XSIDE)
PLY_DEFINE_ENUM(PLY_ENUM_YANCHOR)
PLY_DEFINE_ENUM(PLY_ENUM_YSIDE)
    

#undef PLY_DEFINE_ENUM
#undef PLY_ENUM_DECL
#undef PLY_ENUM_CASE

