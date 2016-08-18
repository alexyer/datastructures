//
// Created by pat on 18.08.16.
//

#ifndef DATASTRUCTURES_INSERTIONS_SORT_H
#define DATASTRUCTURES_INSERTIONS_SORT_H

#include <vector>

using std::vector;

template <typename Comparable>
void insertionSort(vector<Comparable>& a) {
    for (int p = 1; p < a.size(); ++p) {
        Comparable tmp = std::move(a[p]);

        int j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j) {
            a[j] = std::move(a[j - 1]);
        }
        a[j] = std::move(tmp);
    }
}

#endif //DATASTRUCTURES_INSERTIONS_SORT_H
