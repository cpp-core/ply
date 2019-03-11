// Copyright (C) 2019 by Mark Melton
//

#include <regex>
#include "ply/generate.h"
#include "core/guid.h"
#include "core/string/join.h"
#include "ranges/views.h"
#include "ranges/to.h"

namespace ply
{

static auto html_cdn_template = R"XX(
<html>
  <head>
    <meta charset="utf-8" />
  </head>
  <body>
    <script src="https://cdn.plot.ly/plotly-latest.min.js"></script>

    <div id="%%GUID%%"
	 style="height: 100%; width: 100%;"
	 class="plotly-graph-div">
    </div>

    <script type="text/javascript">
      window.PLOTLYENV=window.PLOTLYENV || {};
      window.PLOTLYENV.BASE_URL="https://plot.ly";
      Plotly.newPlot("%%GUID%%", %%JSON%%)
    </script>

    <script type="text/javascript">
      window.removeEventListener("resize");
      window.addEventListener("resize", function(){
	  Plotly.Plots.resize(document.getElementById("%%GUID%%"));
      });
    </script>
    
  </body>
</html>
  )XX";

string construct_plot_args(const Traces& traces, const Layout& layout)
{
    auto strs = v::transform(traces, [](const auto& trace) { return trace.json.dump(); })
	| r::to<strings>();
    auto args = "[" + core::join(strs, ",") + "]";
    if (not layout.json.is_null())
	args += "," + layout.json.dump();
    return args;
}

void generate_html(const Traces& traces, const ply::Layout& layout, std::ostream& os)
{
    auto guid = core::Guid::generate();
    auto args = construct_plot_args(traces, layout);
    auto s1 = std::regex_replace(html_cdn_template, std::regex("%%GUID%%"), guid.as_string());
    auto s2 = std::regex_replace(s1, std::regex("%%JSON%%"), args);
    os << s2 << endl;
}

}; // ply
