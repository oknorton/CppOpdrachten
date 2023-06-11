#include "pch.h"
#include <gtest/gtest.h>
#include <fstream>

class MyTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        output_file.open("test_results.txt");
    }

    virtual void TearDown() {
        output_file.close();
    }

    std::ofstream output_file;
};

int Add(int a, int b) {
    return a + b;
}

int Sub(int a, int b) {
    return a - b;
}

int Divide(int a, int b) {
    return a / b;
}

int Multiply(int a, int b) {
    return a * b;
}

TEST_F(MyTest, TestAddition) {
    ASSERT_EQ(Add(2, 2), 4);

    output_file << "TestAddition: Passed" << std::endl;
}

TEST_F(MyTest, TestSubtraction) {
    ASSERT_EQ(Sub(5, 3), 2);
    output_file << "TestSubtraction: Passed" << std::endl;
}

TEST_F(MyTest, TestDivision) {
    ASSERT_EQ(Divide(10, 2), 5);

    output_file << "TestDivision: Passed" << std::endl;
}

TEST_F(MyTest, TestMultiplication) {
    ASSERT_EQ(Multiply(4, 3), 12);

    output_file << "TestMultiplication: Passed" << std::endl;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    int result = RUN_ALL_TESTS();

    return result;
}
