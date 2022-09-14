// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/layout.h"

using namespace ply;

TEST(Ply, Layout)
{
    EXPECT_EQ(as_string<Layout>(), "layout");
    
    auto expected = json::object();
    auto actual = Layout().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, LayoutScene)
{
    json expected = {{ "scene", {{ "xaxis", {{ "visible", false }}}}}};
    auto actual = Layout(Scene(XAxis(Visible::False))).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



