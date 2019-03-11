// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/anchor.h"

TEST(Ply, AnchorAuto)
{
    core::json expected = "auto";
    auto actual = as_json(ply::Anchor::Auto);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AnchorLeft)
{
    core::json expected = "left";
    auto actual = as_json(ply::Anchor::Left);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AnchorCenter)
{
    core::json expected = "center";
    auto actual = as_json(ply::Anchor::Center);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AnchorRight)
{
    core::json expected = "right";
    auto actual = as_json(ply::Anchor::Right);
    EXPECT_EQ(actual.dump(), expected.dump());
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



