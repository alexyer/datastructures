#include <gmock/gmock-matchers.h>
#include "sort_test.h"
#include "../../includes/algorithm/insertion_sort.h"

TEST_F(SortTest, TestInsertionSort) {
    insertionSort(sorted.begin(), sorted.end());
    ASSERT_THAT(sorted, testing::Eq(check));

    insertionSort(reversed.begin(), reversed.end());
    ASSERT_THAT(reversed, testing::Eq(check));

    insertionSort(random.begin(), random.end());
    ASSERT_THAT(random, testing::Eq(check));
}
