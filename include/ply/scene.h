// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/xaxis.h"
#include "ply/yaxis.h"
#include "ply/zaxis.h"

namespace ply
{

struct Scene : Members<Scene,XAxis,YAxis,ZAxis>, virtual Data
{
    using MembersBase = Members<Scene,XAxis,YAxis,ZAxis>;
    using MembersBase::MembersBase;
};

template<> inline std::string as_string<Scene>() { return "scene"; }
inline json as_json(const Scene& scene) { return scene.json_; }

}; // ply

