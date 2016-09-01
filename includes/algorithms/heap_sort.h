//
// Created by pat on 01.09.16.
//

#ifndef DATASTRUCTURES_HEAP_SORT_H
#define DATASTRUCTURES_HEAP_SORT_H

#include <vector>

using std::vector;

unsigned long leftChild(unsigned long i) {
    return 2 * i + 1;
}

template <typename Comparable>
void percDown(vector<Comparable> &a, unsigned long i, unsigned long size) {
    unsigned long child;
    Comparable tmp;

    for (tmp = std::move(a[i]); leftChild(i) < size; i = child) {
        child = leftChild(i);
        if ((child != size - 1) && (a[child] < a[child + 1])) {
            ++child;
        }
        if (tmp < a[child]) {
            a[i] = std::move(a[child]);
        } else {
            break;
        }
    }

    a[i] = std::move(tmp);
}

template <typename Comparable>
void heapSort(vector<Comparable>& a) {
    for (unsigned long i = a.size() / 2 - 1; i >= 0; --i) {
        percDown(a, i, a.size());
    }
    for (unsigned long j = a.size() - 1; j > 0; --j) {
        std::swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}

#endif //DATASTRUCTURES_HEAP_SORT_H
