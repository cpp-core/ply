// Copyright (C) 2019, 2021 by Mark Melton
//

#include "core/tool.h"
#include "ply/ply.h"

using namespace ply;

int tool_main(int argc, const char *argv[])
{
    std::vector<reals> x = {{1.0,2.0,3.0},
	       {1.0,2.0,3.0},
	       {1.0,1.0,2.0},
	       {1.0,1.0,1.0}};
    Traces traces;
    traces.emplace_back(Contour().z(x));
    generate_html(traces, Layout());
    return 0;
}

