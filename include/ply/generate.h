// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "core/common.h"
#include "core/json.h"

void generate_html(const core::json& json, std::ostream& os, const string& pattern);
void generate_html(const core::json& json, std::ostream& os);
void generate_html(const core::json& json);
