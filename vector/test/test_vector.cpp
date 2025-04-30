#include "vector.hpp"
#include "vector.cpp"
#include <gtest/gtest.h>
#include <string>

namespace {

class VectorTest : public ::testing::Test {
protected:
    biv::Vector<int> int_vec;
    biv::Vector<std::string> str_vec;

    void SetUp() override {

        int_vec.push_back(1);
        int_vec.push_back(2);
        int_vec.push_back(3);
        
        str_vec.push_back("first");
        str_vec.push_back("second");
    }
};

TEST_F(VectorTest, InitialState) {
    biv::Vector<int> empty_vec;
    EXPECT_EQ(empty_vec.get_size(), 0);
    EXPECT_FALSE(empty_vec.has_item(1));
}

TEST_F(VectorTest, PushBackIncreasesSize) {
    EXPECT_EQ(int_vec.get_size(), 3);
    int_vec.push_back(4);
    EXPECT_EQ(int_vec.get_size(), 4);
    EXPECT_TRUE(int_vec.has_item(4));
}

TEST_F(VectorTest, HasItemWorks) {
    EXPECT_TRUE(int_vec.has_item(2));
    EXPECT_FALSE(int_vec.has_item(5));
    
    EXPECT_TRUE(str_vec.has_item("first"));
    EXPECT_FALSE(str_vec.has_item("missing"));
}


TEST_F(VectorTest, InsertAtBeginning) {
    EXPECT_TRUE(int_vec.insert(0, 0));
    EXPECT_EQ(int_vec.get_size(), 4);
    EXPECT_TRUE(int_vec.has_item(0));
}

TEST_F(VectorTest, InsertAtEnd) {
    EXPECT_TRUE(int_vec.insert(3, 4));
    EXPECT_EQ(int_vec.get_size(), 4);
    EXPECT_TRUE(int_vec.has_item(4));
}

TEST_F(VectorTest, InsertAtInvalidPosition) {
    EXPECT_FALSE(int_vec.insert(10, 5));
    EXPECT_EQ(int_vec.get_size(), 3);
}



TEST_F(VectorTest, RemoveFirstItem) {
    EXPECT_TRUE(int_vec.remove_first(1));
    EXPECT_EQ(int_vec.get_size(), 2);
    EXPECT_FALSE(int_vec.has_item(1));
}

TEST_F(VectorTest, RemoveMiddleItem) {
    EXPECT_TRUE(int_vec.remove_first(2));
    EXPECT_EQ(int_vec.get_size(), 2);
    EXPECT_FALSE(int_vec.has_item(2));
}

TEST_F(VectorTest, RemoveNonExistentItem) {
    EXPECT_FALSE(int_vec.remove_first(5));
    EXPECT_EQ(int_vec.get_size(), 3);
}

TEST_F(VectorTest, RemoveFromEmptyVector) {
    biv::Vector<int> empty_vec;
    EXPECT_FALSE(empty_vec.remove_first(1));
    EXPECT_EQ(empty_vec.get_size(), 0);
}

TEST_F(VectorTest, PrintOutput) {
    testing::internal::CaptureStdout();
    int_vec.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[1, 2, 3]\n");
}

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
