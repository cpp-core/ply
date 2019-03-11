// Copyright (C) 2019 by Mark Melton
//

#pragma once
#include "ply/base.h"

namespace ply
{

enum class Anchor { Auto, Left, Center, Right };

inline core::json as_json(Anchor d)
{
    switch (d)
    {
    case Anchor::Auto: return "auto";
    case Anchor::Left: return "left";
    case Anchor::Center: return "center";
    case Anchor::Right: return "right";
    }
    throw std::runtime_error("Anchor::as_json: unknown enum value");
}

}; // ply

