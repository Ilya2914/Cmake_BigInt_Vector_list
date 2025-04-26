#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

namespace {

class DoublyLinkedListTest : public ::testing::Test {
protected:
    biv::DoublyLinkedList<int> list;

    void SetUp() override {
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);
    }
};

TEST_F(DoublyLinkedListTest, InitialState) {
    biv::DoublyLinkedList<int> empty_list;
    EXPECT_EQ(empty_list.get_size(), 0);
    EXPECT_FALSE(empty_list.has_item(1));
}

TEST_F(DoublyLinkedListTest, PushBackIncreasesSize) {
    EXPECT_EQ(list.get_size(), 3);
    list.push_back(4);
    EXPECT_EQ(list.get_size(), 4);
}

TEST_F(DoublyLinkedListTest, HasItemWorks) {
    EXPECT_TRUE(list.has_item(2));
    EXPECT_FALSE(list.has_item(5));
}

TEST_F(DoublyLinkedListTest, RemoveFirstDecreasesSize) {
    EXPECT_TRUE(list.remove_first(2));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(2));
}

TEST_F(DoublyLinkedListTest, RemoveNonExistentItem) {
    EXPECT_FALSE(list.remove_first(5));
    EXPECT_EQ(list.get_size(), 3);
}

TEST_F(DoublyLinkedListTest, RemoveFromEmptyList) {
    biv::DoublyLinkedList<int> empty_list;
    EXPECT_FALSE(empty_list.remove_first(1));
}

TEST_F(DoublyLinkedListTest, RemoveFirstItem) {
    EXPECT_TRUE(list.remove_first(1));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(1));
    EXPECT_TRUE(list.has_item(2));
}

TEST_F(DoublyLinkedListTest, RemoveLastItem) {
    EXPECT_TRUE(list.remove_first(3));
    EXPECT_EQ(list.get_size(), 2);
    EXPECT_FALSE(list.has_item(3));
    EXPECT_TRUE(list.has_item(1));
}

TEST_F(DoublyLinkedListTest, PushBackToEmptyList) {
    biv::DoublyLinkedList<int> empty_list;
    empty_list.push_back(10);
    EXPECT_EQ(empty_list.get_size(), 1);
    EXPECT_TRUE(empty_list.has_item(10));
}

TEST_F(DoublyLinkedListTest, MultiplePushBack) {
    biv::DoublyLinkedList<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    EXPECT_EQ(lst.get_size(), 3);
    EXPECT_TRUE(lst.has_item(20));
}

TEST_F(DoublyLinkedListTest, ClearListWithDestructor) {
    {
        biv::DoublyLinkedList<int> temp_list;
        temp_list.push_back(100);
        temp_list.push_back(200);
    }

}

} 

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
