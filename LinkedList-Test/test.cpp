#include "gtest/gtest.h"

extern "C" {
#include "List.h"
#include "Student.h"
}

LinkedList_t list;

class ProductionTest : public ::testing::Test {
protected:
	void SetUp() override {
		list = create();
	}
	void TearDown() override {}
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST_F(ProductionTest, list_can_be_created) {
	EXPECT_FALSE(NULL == list);
}

TEST_F(ProductionTest, list_can_be_destroied) {
	EXPECT_EQ(OK, linked_list_destroy(&list));
	EXPECT_TRUE(NULL == list);
}

// Test exceptionel behaviour
TEST_F(ProductionTest, list_destroied_twice) {
	EXPECT_EQ(OK, linked_list_destroy(&list));
	EXPECT_TRUE(NULL == list);
	EXPECT_EQ(OK, linked_list_destroy(&list));
	EXPECT_TRUE(NULL == list);
}

// Test exceptionel behaviour
TEST_F(ProductionTest, list_not_accessable_after_destruction) {
	EXPECT_EQ(OK, linked_list_destroy(&list));
	EXPECT_TRUE(NULL == list);
	EXPECT_EQ(Empty, linked_list_containsItem(list, "strin"));
}

TEST_F(ProductionTest, Test_balance_is_zero_on_new_account) {
	EXPECT_EQ(NOT_FOUND, linked_list_containsItem(list, "strin"));
}


TEST_F(ProductionTest, Test_deposit_on_account) {
	EXPECT_EQ(OK, push(list, "strin"));
}

TEST_F(ProductionTest, List_lenght_on_empty) {
	EXPECT_EQ(0, linked_list_length(list));
}

TEST_F(ProductionTest, List_lenght_on_not_empty) {
	EXPECT_EQ(OK, push(list, "stri"));
	EXPECT_EQ(OK, push(list, "strin"));
	EXPECT_EQ(OK, push(list, "string"));
	EXPECT_EQ(3, linked_list_length(list));
}

TEST_F(ProductionTest, Test_contains_item_while_it_contains_item) {
	EXPECT_EQ(OK, push(list, "str"));
	EXPECT_EQ(4, linked_list_containsItem(list, "str"));
}

// Test exceptionel behaviour
TEST_F(ProductionTest, Test_withdraw_more_than_balance) {
	EXPECT_EQ(OK, push(list, "strin"));
	EXPECT_EQ(FOUND, linked_list_containsItem(list, "strin"));
	printf("3 Equality\n");
	EXPECT_EQ(OK, removeItem(list, "strin"));

}
