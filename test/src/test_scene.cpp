// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/scene.h"

using namespace ply;

TEST(Ply, Scene)
{
    EXPECT_EQ(as_string<Scene>(), "scene");
    
    auto expected = json::object();
    auto actual = Scene().json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneXAxisVisibleFalse)
{
    json expected = {{ "xaxis", {{ "visible", false }}}};
    auto actual = Scene(XAxis(Visible::False)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneYAxisVisibleFalse)
{
    json expected = {{ "yaxis", {{ "visible", false }}}};
    auto actual = Scene(YAxis(Visible::False)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneZAxisVisibleFalse)
{
    json expected = {{ "zaxis", {{ "visible", false }}}};
    auto actual = Scene(ZAxis(Visible::False)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

TEST(Ply, SceneAllAxisVisibleFalse)
{
    json expected = {{ "xaxis", {{ "visible", false }}},
			   { "yaxis", {{ "visible", false }}},
			   { "zaxis", {{ "visible", false }}}};
    auto actual = Scene(XAxis(Visible::False), YAxis(Visible::False), ZAxis(Visible::False)).json_;
    EXPECT_EQ(actual.dump(), expected.dump());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



