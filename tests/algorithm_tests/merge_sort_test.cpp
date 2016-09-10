#include <gmock/gmock-matchers.h>
#include "sort_test.h"
#include "../../includes/algorithm/merge_sort.h"

TEST_F(SortTest, TestMergeSort) {
    mergeSort(sorted);
    ASSERT_THAT(sorted, testing::Eq(check));

    mergeSort(reversed);
    ASSERT_THAT(reversed, testing::Eq(check));

    mergeSort(random);
    ASSERT_THAT(random, testing::Eq(check));
}
