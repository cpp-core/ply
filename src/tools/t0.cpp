// Copyright (C) 2019 by Mark Melton
//

#include <regex>
#include "core/tool.h"
#include "core/guid.h"
#include "ply/ply.h"

auto html_template = R"XX(
<html>
  <head>
    <meta charset="utf-8" />
  </head>
  <body>
    <script src="https://cdn.plot.ly/plotly-1.5.0.min.js"></script>

    <div id="%%GUID%%"
	 style="height: 100%; width: 100%;"
	 class="plotly-graph-div">
    </div>

    <script type="text/javascript">
      window.PLOTLYENV=window.PLOTLYENV || {};
      window.PLOTLYENV.BASE_URL="https://plot.ly";
      Plotly.newPlot("%%GUID%%", %%JSON%%)
    </script>

    <script type="text/javascript">window.removeEventListener("resize");
      window.addEventListener("resize", function(){
	  Plotly.Plots.resize(document.getElementById("%%GUID%%"));
      });
    </script>
    
  </body>
</html>
  )XX";

int tool_main(int argc, const char *argv[])
{
    core::POpt opts;
    opts.process(argc, argv);

    auto s = ply::Scatter()
	.name("trace1")
	.showlegend()
	.x({1, 2, 3, 4})
	.y({1, 2, 2, 3})
	;
    
    cout << s.json.dump(4) << endl;
    // auto s = Scatter("trace1").x({1, 2, 3, 4}).y({1, 2, 2, 3});

    // auto guid = core::Guid::generate();
    // core::json j =
    // 	{
    // 	 {
    // 	  { "showlegend", true },
    // 	  { "name", "Trace_1" },
    // 	  { "type", "scatter" },
    // 	  { "x", { 0, 1, 2, 3 }},
    // 	  { "y", { 1, 3, 4, 5 }}
    // 	 },
    // 	 {
    // 	  { "showlegend", true },
    // 	  { "name", "Trace_2" },
    // 	  { "type", "scatter" },
    // 	  { "x", { 0, 1, 2, 3 }},
    // 	  { "y", { 2, 2, 3, 1 }}
    // 	 }
    // 	};
	 

    // auto json_str = j.dump(4);
    // auto s1 = std::regex_replace(html_template, std::regex("%%GUID%%"), guid.as_string());
    // auto s2 = std::regex_replace(s1, std::regex("%%JSON%%"), j.dump(4));
    // cout << s2 << endl;
    
    return 0;
}

