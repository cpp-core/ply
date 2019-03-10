// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/shape.h"

TEST(Ply, Shape)
{
    auto expected = "shape";
    auto actual = ply::as_string<ply::Shape>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, ShapeLinear)
{
    core::json expected = "linear";
    auto actual = as_json(ply::Shape::Linear);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ShapeSpline)
{
    core::json expected = "spline";
    auto actual = as_json(ply::Shape::Spline);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ShapeHV)
{
    core::json expected = "hv";
    auto actual = as_json(ply::Shape::HV);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ShapeVH)
{
    core::json expected = "vh";
    auto actual = as_json(ply::Shape::VH);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ShapeHVH)
{
    core::json expected = "hvh";
    auto actual = as_json(ply::Shape::HVH);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, ShapeVHV)
{
    core::json expected = "vhv";
    auto actual = as_json(ply::Shape::VHV);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



