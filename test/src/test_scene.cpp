// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/scene.h"

using namespace ply;

TEST(Ply, Scene)
{
    EXPECT_EQ(as_string<Scene>(), "scene");
    
    auto expected = nlj::json::object();
    auto actual = Scene().json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneXAxisVisibleFalse)
{
    nlj::json expected = {{ "xaxis", {{ "visible", false }}}};
    auto actual = Scene(XAxis(Visible::False)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneYAxisVisibleFalse)
{
    nlj::json expected = {{ "yaxis", {{ "visible", false }}}};
    auto actual = Scene(YAxis(Visible::False)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneZAxisVisibleFalse)
{
    nlj::json expected = {{ "zaxis", {{ "visible", false }}}};
    auto actual = Scene(ZAxis(Visible::False)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneAllAxisVisibleFalse)
{
    nlj::json expected = {{ "xaxis", {{ "visible", false }}},
			   { "yaxis", {{ "visible", false }}},
			   { "zaxis", {{ "visible", false }}}};
    auto actual = Scene(XAxis(Visible::False), YAxis(Visible::False), ZAxis(Visible::False)).json;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



