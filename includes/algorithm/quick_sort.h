#ifndef DATASTRUCTURES_QUICKSORT_H
#define DATASTRUCTURES_QUICKSORT_H

#include "insertion_sort.h"

template <typename Iterator>
auto median3(const Iterator& left, const Iterator& right) -> decltype(*left) {
    Iterator center = left;
    std::advance(center, std::distance(left, right));

    if (*center < *left) {
        std::swap(*left, *center);
    }
    if (*right < *left) {
        std::swap(*left, *right);
    }
    if (*right < *center) {
        std::swap(*center, *right);
    }

    std::swap(*center, *right);

    return *(right - 1);
}

template <typename Iterator, typename Comparator>
void quickSort(const Iterator& left, const Iterator& right, Comparator lessThan) {
    if (left + 10 <= right) {
        auto pivot = median3(left, right);

        auto i = left;
        auto j = right - 1;

        for (;;) {
            while (*++i < pivot) {}
            while (pivot < *--j) {}
            if (i < j) {
                std::swap(*i, *j);
            } else {
                break;
            }
        }

        std::swap(*i, *(right - 1));
        quickSort(left, i - 1, lessThan);
        quickSort(i + 1, right, lessThan);
    } else {
        insertionSort(left, right);
    }
}

template <typename Iterator>
void quickSort(const Iterator& begin, const Iterator& end) {
    quickSort(begin, end, std::less<decltype(*begin)>{});
}

#endif //DATASTRUCTURES_QUICKSORT_H
