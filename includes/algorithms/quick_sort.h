//
// Created by pat on 01.09.16.
//

#ifndef DATASTRUCTURES_QUICKSORT_H
#define DATASTRUCTURES_QUICKSORT_H

#include <vector>
#include "insertion_sort.h"

using std::vector;

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a, unsigned long left, unsigned long right) {
    auto center = (left + right) / 2;

    if (a[center] < a[left]) {
        std::swap(a[left], a[center]);
    }
    if (a[right] < a[left]) {
        std::swap(a[left], a[right]);
    }
    if (a[right] < a[center]) {
        std::swap(a[center], a[right]);
    }

    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

template <typename Comparable>
void quickSort(vector<Comparable> &a, unsigned long left, unsigned long right) {
    if (left + 10 <= right) {
        auto pivot = median3(a, left, right);

        unsigned long i = left;
        unsigned long j = right - 1;

        for (;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            if (i < j) {
                std::swap(a[i], a[j]);
            } else {
                break;
            }
        }

        std::swap(a[i], a[right - 1]);
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    } else {
        insertionSort(a.begin(), a.end());
    }
}

template <typename Comparable>
void quickSort(vector<Comparable>& a) {
    quickSort(a, 0, a.size() - 1);
}

#endif //DATASTRUCTURES_QUICKSORT_H
