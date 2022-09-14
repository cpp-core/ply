// Copyright (C) 2019, 2021, 2022 by Mark Melton
//

#include <vector>
#include "core/util/tool.h"
#include "ply/ply.h"

using namespace ply;

int tool_main(int argc, const char *argv[])
{
    std::vector<double> x = {1.0,2.0,3.0}, y = {4.0,5.0,4.0};
    Traces traces;
    traces.emplace_back(Scatter().x(x).y(y));
    generate_html(traces, Layout());
    return 0;
}

