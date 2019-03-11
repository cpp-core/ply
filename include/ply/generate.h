// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"
#include "ply/layout.h"

namespace ply
{

void generate_html(const Traces& traces, const ply::Layout& layout, std::ostream& os = cout);

template<class... Ts>
requires ((DerivedFrom<Ts,Trace> and ...))
void generate_html(const Ts&... traces, const ply::Layout& layout)
{ generate_html(Traces{traces...}, layout); }

template<class... Ts>
requires ((DerivedFrom<Ts,Trace> && ...))
void generate_html(const Ts&... traces, std::ostream& os)
{ generate_html(Traces{traces...}, Layout{}, os); }

template<class... Ts>
requires ((DerivedFrom<Ts,Trace> && ...))
void generate_html(const Ts&... traces)
{ generate_html(Traces{traces...}, Layout{}, cout); }

}; // ply

