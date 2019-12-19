// Copyright (C) 2019 by Mark Melton
//

#include <stdio.h>
#include <regex>
#include <inja/inja.hpp>
#include <range/v3/view.hpp>
#include "ply/generate.h"
#include "ply/config.h"
#include "core/guid.h"
#include "core/string/join.h"
#include "core/string/slurp.h"

namespace ply
{

static auto html_page_tmpl = R"XX(
<html>
  <head>
    <meta charset="utf-8" />
  </head>
  <body>
    {{body_include}}

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

static constexpr auto html_script_src_tmpl = R"XX(
    <script src={{cdn}}></script>;
)XX";

static constexpr auto html_script_inline_tmpl = R"XX(
<script type="text/javascript">
{{inline_js}}
</script>
)XX";

static constexpr auto plotly_js_cdn = "https://cdn.plot.ly/plotly-latest.min.js";
static constexpr auto plotly_js_file_tmpl = "{share:}/ply/js/plotly-latest.min.js";

string construct_plot_args(const Traces& traces, const Layout& layout)
{
    auto strs = v::transform(traces, [](const auto& trace) { return trace.json.dump(); })
	| r::to<strings>();
    auto args = "[" + core::join(strs, ",") + "]";
    if (not layout.json.is_null())
	args += "," + layout.json.dump();
    return args;
}

void generate_html(const Traces& traces, const ply::Layout& layout, std::ostream& os, bool cdn)
{
    string body_include;
    if (cdn)
    {
	body_include = inja::render(html_script_src_tmpl, {{ "cdn", plotly_js_cdn }});
    }
    else
    {
	auto js_file = fmt::format(plotly_js_file_tmpl, fmt::arg("share", PlyShareDirectory));
	auto js = core::slurp_into_string(js_file);
	body_include = inja::render(html_script_inline_tmpl, {{ "inline_js", js }});
    }
    
    auto guid = core::Guid::generate().as_string();
    auto args = construct_plot_args(traces, layout);
    auto html = inja::render(html_page_tmpl,
			     {{ "guid", guid },
			      { "json", args },
			      { "body_include", body_include }});			     
    os << html << endl;
}

}; // ply
