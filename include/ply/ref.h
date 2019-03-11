// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class Ref { Container, Paper };

inline core::json as_json(Ref d)
{
    switch (d)
    {
    case Ref::Container: return "container";
    case Ref::Paper: return "paper";
    }
    throw std::runtime_error("Ref::as_json: unknown enum value");
}

}; // ply

