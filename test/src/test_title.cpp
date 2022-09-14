// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/title.h"

using namespace ply;

TEST(Ply, Title)
{
    EXPECT_EQ(as_string<Title>(), "title");
    
    auto expected = json::object();
    auto actual = Title().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleText)
{
    json expected = {{ "text", "abc" }};
    auto actual = Title(Text("abc")).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleFont)
{
    json expected = {{ "font", {{ "family", "verdana" }, { "size", 5 }} }};
    auto actual = Title(Font().verdana().size(5)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleXRef)
{
    json expected = {{ "xref", "container" }};
    auto actual = Title().xRef(Ref::Container).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleYRef)
{
    json expected = {{ "yref", "paper" }};
    auto actual = Title().yRef(Ref::Paper).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleX)
{
    json expected = {{ "x", 1 }};
    auto actual = Title().x(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleY)
{
    json expected = {{ "y", 1 }};
    auto actual = Title().y(1).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleXAnchor)
{
    json expected = {{ "xanchor", "auto" }};
    auto actual = Title(XAnchor::Auto).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitleYAnchor)
{
    json expected = {{ "yanchor", "bottom" }};
    auto actual = Title(YAnchor::Bottom).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, TitlePad)
{
    json expected = {{ "pad", {{ "l", 1 }, { "r", 2 }, { "t", 3 }, { "b", 4 }} }};
    auto actual = Title(Pad().l(1).r(2).t(3).b(4)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



