// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/title.h"

using namespace ply;

TEST(Ply, Title)
{
    EXPECT_EQ(as_string<Title>(), "title");
    
    auto expected = nlj::json::object();
    auto actual = Title().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleText)
{
    nlj::json expected = {{ "text", "abc" }};
    auto actual = Title(Text("abc")).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleFont)
{
    nlj::json expected = {{ "font", {{ "family", "verdana" }, { "size", 5 }} }};
    auto actual = Title(Font().verdana().size(5)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleXRef)
{
    nlj::json expected = {{ "xref", "container" }};
    auto actual = Title().xRef(Ref::Container).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleYRef)
{
    nlj::json expected = {{ "yref", "paper" }};
    auto actual = Title().yRef(Ref::Paper).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleX)
{
    nlj::json expected = {{ "x", 1 }};
    auto actual = Title().x(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleY)
{
    nlj::json expected = {{ "y", 1 }};
    auto actual = Title().y(1).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleXAnchor)
{
    nlj::json expected = {{ "xanchor", "auto" }};
    auto actual = Title(XAnchor::Auto).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleYAnchor)
{
    nlj::json expected = {{ "yanchor", "bottom" }};
    auto actual = Title(YAnchor::Bottom).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitlePad)
{
    nlj::json expected = {{ "pad", {{ "l", 1 }, { "r", 2 }, { "t", 3 }, { "b", 4 }} }};
    auto actual = Title(Pad().l(1).r(2).t(3).b(4)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



