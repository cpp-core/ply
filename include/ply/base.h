// Copyright (C) 2019, 2022 by Mark Melton
//

#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace ply
{

template<class T> std::string as_string();

struct Data
{
    Data() { json_ = json::object(); }
    json json_;
};

struct Trace : virtual Data { };
using Traces = std::vector<Trace>;

}; // ply

