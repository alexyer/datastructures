//
// Created by pat on 01.09.16.
//

#ifndef DATASTRUCTURES_MERGE_SORT_H
#define DATASTRUCTURES_MERGE_SORT_H

#include <vector>

using std::vector;

template <typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &tmpArray, unsigned long leftPos, unsigned long rightPos,
           unsigned long rightEnd) {
    unsigned long leftEnd = rightPos - 1;
    unsigned long tmpPos = leftPos;
    unsigned long numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] <= a[rightPos]) {
            tmpArray[tmpPos++] = std::move(a[leftPos++]);
        } else {
            tmpArray[tmpPos++] = std::move(a[rightPos++]);
        }
    }

    while (leftPos <= leftEnd) {
        tmpArray[tmpPos++] = std::move(a[leftPos++]);
    }

    while (rightPos <= rightEnd) {
        tmpArray[tmpPos++] = std::move(a[rightPos++]);
    }

    for (int i = 0; i < numElements; ++i, --rightEnd) {
        a[rightEnd] = std::move(tmpArray[rightEnd]);
    }
}

template <typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray,
               unsigned long left, unsigned long right) {
    if (left < right) {
        unsigned long center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

template <typename Comparable>
void mergeSort(vector<Comparable>& a){
    vector<Comparable> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

#endif //DATASTRUCTURES_MERGE_SORT_H
