// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include <iostream>
#include "ply/base.h"
#include "ply/layout.h"

namespace ply
{

void generate_html(const Traces& traces, const ply::Layout& layout,
		   std::ostream& os = std::cout, bool cdn = true);

// template<class... Ts>
// void generate_html(const Ts&... traces, const ply::Layout& layout)
// { generate_html(Traces{traces...}, layout); }

// template<class... Ts>
// void generate_html(const Ts&... traces, std::ostream& os)
// { generate_html(Traces{traces...}, Layout{}, os); }

// template<class... Ts>
// void generate_html(const Ts&... traces)
// { generate_html(Traces{traces...}, Layout{}, cout); }

}; // ply

