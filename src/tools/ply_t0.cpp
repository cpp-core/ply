// Copyright (C) 2019, 2021, 2022 by Mark Melton
//

#include "core/utility/tool.h"
#include "ply/ply.h"

using namespace ply;

int tool_main(int argc, const char *argv[])
{
    reals x = {1.0,2.0,3.0}, y = {4.0,5.0,4.0};
    Traces traces;
    traces.emplace_back(Scatter().x(x).y(y));
    generate_html(traces, Layout());
    return 0;
}

