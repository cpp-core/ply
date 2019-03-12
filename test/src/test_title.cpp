// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/title.h"

TEST(Ply, Title)
{
    EXPECT_EQ(ply::as_string<ply::Title>(), "title");
    
    auto expected = core::json::object();
    auto actual = ply::Title().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleText)
{
    core::json expected = {{ "text", "abc" }};
    auto actual = ply::Title().text("abc").json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleFont)
{
    core::json expected = {{ "font", {{ "family", "verdana" }, { "size", 5 }} }};
    auto actual = ply::Title()(ply::Font().verdana().size(5)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleXRef)
{
    core::json expected = {{ "xref", "container" }};
    auto actual = ply::Title().xRef(ply::Ref::Container).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleYRef)
{
    core::json expected = {{ "yref", "paper" }};
    auto actual = ply::Title().yRef(ply::Ref::Paper).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleX)
{
    core::json expected = {{ "x", 1 }};
    auto actual = ply::Title().x(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleY)
{
    core::json expected = {{ "y", 1 }};
    auto actual = ply::Title().y(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleXAnchor)
{
    core::json expected = {{ "xanchor", "auto" }};
    auto actual = ply::Title()(ply::XAnchor::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleYAnchor)
{
    core::json expected = {{ "yanchor", "bottom" }};
    auto actual = ply::Title()(ply::YAnchor::Bottom).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitlePad)
{
    core::json expected = {{ "pad", {{ "l", 1 }, { "r", 2 }, { "t", 3 }, { "b", 4 }} }};
    auto actual = ply::Title()(ply::Pad().l(1).r(2).t(3).b(4)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



