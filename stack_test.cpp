#include "stack.h"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(StackTest, Push) {
	Stack<int> s;
    s.push(5);
    s.push(-1);
	EXPECT_EQ(-1, s.top());
    s.push(7980987);
	EXPECT_EQ(7980987, s.top());
    s.push(0);
	EXPECT_EQ(0, s.top());
}

TEST(StackTest, Pop) {
	Stack<int> s;
    s.push(3);
    s.push(-4);
    s.push(0);
    s.pop();
	EXPECT_EQ(-4, s.top());
    s.pop();
	EXPECT_EQ(3, s.top());
    s.pop();
    EXPECT_THROW(s.top(), std::underflow_error);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}