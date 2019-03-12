// Copyright (C) 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/enum.h"
#include "core/pp.h"

#define PLY_TEST_ENUM_CASE(name, seq)					\
    TEST(CAT(Ply,name), HEAD_SEQ(seq)) {				\
     	core::json expected = SECOND_SEQ(seq);				\
	auto actual = as_json(ply::name::HEAD_SEQ(seq));		\
	EXPECT_EQ(actual.dump(), expected.dump());			\
    }

#define PLY_TEST_ENUM(name, jname, seq)	\
    TEST(CAT(Ply,name), CAT(name,AsString)) {		\
    	auto expected = jname;				\
     	auto actual = ply::as_string<ply::name>();	\
     	EXPECT_EQ(actual, expected);			\
    }							\
    MAP_WITH_SEQ(PLY_TEST_ENUM_CASE,name,seq)

#define PLY_ENUM_TEST(seq) EVAL(PLY_TEST_ENUM(HEAD_SEQ(seq), SECOND_SEQ(seq), THIRD_SEQ(seq)))

PLY_ENUM_TEST(PLY_ENUM_ANCHOR)
PLY_ENUM_TEST(PLY_ENUM_AUTO_RANGE)
PLY_ENUM_TEST(PLY_ENUM_AXIS_TYPE)
PLY_ENUM_TEST(PLY_ENUM_DASH)
PLY_ENUM_TEST(PLY_ENUM_GROUP_NORM)
PLY_ENUM_TEST(PLY_ENUM_ORIENTATION)
PLY_ENUM_TEST(PLY_ENUM_REF)
PLY_ENUM_TEST(PLY_ENUM_RANGE_MODE)
PLY_ENUM_TEST(PLY_ENUM_SHAPE)
PLY_ENUM_TEST(PLY_ENUM_TICK_MODE)

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

