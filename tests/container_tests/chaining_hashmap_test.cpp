#include <gtest/gtest.h>
#include "../../includes/container/chaining_hashmap.h"

class ChainingHashmapTest : public ::testing::Test {
public:
    ChainingHashMap<int, std::string> hashmap;
};

TEST_F(ChainingHashmapTest, Test) {
    hashmap.put(1, "test");

    ASSERT_EQ(*hashmap.get(1), "test");
    ASSERT_EQ(hashmap.get(2), nullptr);

    auto res = hashmap.get(1);
    hashmap.del(1);
    ASSERT_EQ(*res, "test");
    ASSERT_EQ(hashmap.get(1), nullptr);
}
