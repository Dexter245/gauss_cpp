#include <gtest/gtest.h>


TEST(ExampleTests, shouldPass){
    ASSERT_EQ(1 + 1, 2);
}

TEST(ExampleTests, shouldFail){
    ASSERT_EQ(1+1, 3);
}


TEST(ExampleTests, test_no_death){

    auto a = [] () {
        int a = 0;
        a = 7;
        int b = a;
        a = b;
        exit(0);
    };

    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), "");
}

TEST(ExampleTests, test_death){

    auto a = [] () {
        int *f = new int;
        f[5000] = 543;
        delete f;
        delete f;
        delete [] f;
    };

    ASSERT_DEATH(a(), "");
}

