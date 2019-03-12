// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/enum.h"

TEST(Ply, AxisType)
{
    auto expected = "type";
    auto actual = ply::as_string<ply::AxisType>();
    EXPECT_EQ(actual, expected);
}

TEST(Ply, AxisTypeDash)
{
    core::json expected = "-";
    auto actual = as_json(ply::AxisType::Dash);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AxisTypeLinear)
{
     core::json expected = "linear";
    auto actual = as_json(ply::AxisType::Linear);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AxisTypeLog)
{
    core::json expected = "log";
    auto actual = as_json(ply::AxisType::Log);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AxisTypeDate)
{
    core::json expected = "date";
    auto actual = as_json(ply::AxisType::Date);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AxisTypeCategory)
{
    core::json expected = "category";
    auto actual = as_json(ply::AxisType::Category);
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, AxisTypeMultiCategory)
{
    core::json expected = "multicategory";
    auto actual = as_json(ply::AxisType::MultiCategory);
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



