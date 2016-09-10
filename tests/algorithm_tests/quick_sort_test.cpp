#include <gmock/gmock-matchers.h>
#include "sort_test.h"
#include "../../includes/algorithm/quick_sort.h"

TEST_F(SortTest, TestQuickSort) {
    quickSort(sorted.begin(), sorted.end());
    ASSERT_THAT(sorted, testing::Eq(check));

    quickSort(reversed.begin(), reversed.end());
    ASSERT_THAT(reversed, testing::Eq(check));

    quickSort(random.begin(), random.end());
    ASSERT_THAT(random, testing::Eq(check));
}
