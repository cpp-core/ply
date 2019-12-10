// Copyright (C) 2019 by Mark Melton
//

#include <stdio.h>
#include <regex>
#include <inja/inja.hpp>
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
    <script src="{{plotly_js}}"></script>

    <div id="{{guid}}"
	 style="height: 100%; width: 100%;"
	 class="plotly-graph-div">
    </div>

    <script type="text/javascript">
      window.PLOTLYENV=window.PLOTLYENV || {};
      window.PLOTLYENV.BASE_URL="https://plot.ly";
      Plotly.newPlot("{{guid}}", {{json}})
    </script>

    <script type="text/javascript">
      window.removeEventListener("resize");
      window.addEventListener("resize", function(){
	  Plotly.Plots.resize(document.getElementById("{{guid}}"));
      });
    </script>
    
  </body>
</html>
  )XX";

static constexpr auto plotly_js_url = "https://cdn.plot.ly/plotly-latest.min.js";
static constexpr auto plotly_js_file = "file:///Users/mmelton/work/cxx-ply/plotly-latest.min.js";

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
    auto guid = core::Guid::generate().as_string();
    auto args = construct_plot_args(traces, layout);
    nlj::json data = {{ "guid", guid }, { "json", args }, { "plotly_js", plotly_js_url }};
    auto html = inja::render(html_cdn_template, data);
    os << html << endl;
}

}; // ply
