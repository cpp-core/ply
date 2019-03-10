// Copyright (C) 2019 by Mark Melton
//

#include <regex>
#include "ply/generate.h"
#include "core/guid.h"

static auto html_cdn_template = R"XX(
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
      Plotly.newPlot("%%GUID%%", [%%JSON%%])
    </script>

    <script type="text/javascript">window.removeEventListener("resize");
      window.addEventListener("resize", function(){
	  Plotly.Plots.resize(document.getElementById("%%GUID%%"));
      });
    </script>
    
  </body>
</html>
  )XX";

void generate_html(const core::json& json, std::ostream& os, const string& pattern)
{
    auto guid = core::Guid::generate();
    auto jstr = json.dump();
    auto s1 = std::regex_replace(pattern, std::regex("%%GUID%%"), guid.as_string());
    auto s2 = std::regex_replace(s1, std::regex("%%JSON%%"), jstr);
    os << s2 << endl;
}

void generate_html(const core::json& json, std::ostream& os)
{ generate_html(json, os, html_cdn_template); }

void generate_html(const core::json& json)
{ generate_html(json, cout); }

