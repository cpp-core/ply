// Copyright (C) 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "ply/ply.h"

using namespace ply;

TEST(Ply, Generate)
{
    std::vector<double> data = { 1, 2, 3, 3, 2, 1 };
    Trace trace{Scatter(Name{"test-data"}).y(data)};

    std::stringstream ss;
    generate_html({trace}, Layout(), ss);
    EXPECT_GT(ss.str().size(), 100);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



