#include <gtest/gtest.h>
#include "../../includes/container/lock_based_queue.h"

class LockBasedQueueTest : public ::testing::Test {
public:
    LockBasedQueue<int> queue;
};

TEST_F(LockBasedQueueTest, TestEmpty) {
    ASSERT_TRUE(queue.empty());
}

TEST_F(LockBasedQueueTest, TestSize) {
    ASSERT_EQ(queue.size(), 0);
}

TEST_F(LockBasedQueueTest, TestPush) {
    queue.push(1);

    ASSERT_FALSE(queue.empty());
    ASSERT_EQ(queue.size(), 1);
}

TEST_F(LockBasedQueueTest, TestBack) {
    queue.push(1);
    queue.push(2);

    ASSERT_EQ(*queue.back(), 2);
}

TEST_F(LockBasedQueueTest, TestFront) {
    queue.push(1);
    queue.push(2);

    ASSERT_EQ(*queue.front(), 1);
}

TEST_F(LockBasedQueueTest, TestPop) {
    queue.push(1);
    queue.pop();
    ASSERT_TRUE(queue.empty());
}