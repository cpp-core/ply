// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/ref.h"

TEST(Ply, RefContainer)
{
    core::json expected = "container";
    auto actual = as_json(ply::Ref::Container);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, RefPaper)
{
    core::json expected = "paper";
    auto actual = as_json(ply::Ref::Paper);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



