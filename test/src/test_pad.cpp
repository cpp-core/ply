// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/pad.h"

TEST(Ply, Pad)
{
    EXPECT_EQ(ply::as_string<ply::Pad>(), "pad");
    
    auto expected = json::object();
    auto actual = ply::Pad().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, PadT)
{
    json expected = {{ "t", 1 }};
    auto actual = ply::Pad().t(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, PadR)
{
    json expected = {{ "r", 1 }};
    auto actual = ply::Pad().r(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, PadB)
{
    json expected = {{ "b", 1 }};
    auto actual = ply::Pad().b(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, PadL)
{
    json expected = {{ "l", 1 }};
    auto actual = ply::Pad().l(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



