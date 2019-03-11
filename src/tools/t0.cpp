// Copyright (C) 2019 by Mark Melton
//

#include "core/tool.h"
#include "ply/ply.h"

int tool_main(int argc, const char *argv[])
{
    core::POpt opts;
    opts.process(argc, argv);

    auto s = ply::Scatter()
	.name("trace1")
	.showlegend()
	.x0(1)
	.dx(1)
	.y(ints{1, 2, 2, 3, 4, 5, 3, 2, 1})
	;

    ply::generate_html(s);
    
    return 0;
}

