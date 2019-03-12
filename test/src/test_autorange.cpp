// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/autorange.h"

TEST(Ply, AutoRange)
{
    auto expected = "autorange";
    auto actual = ply::as_string<ply::AutoRange>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, AutoRangeTrue)
{
    core::json expected = true;
    auto actual = as_json(ply::AutoRange::True);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AutoRangeFalse)
{
     core::json expected = false;
    auto actual = as_json(ply::AutoRange::False);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AutoRangeReversed)
{
    core::json expected = "reversed";
    auto actual = as_json(ply::AutoRange::Reversed);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



