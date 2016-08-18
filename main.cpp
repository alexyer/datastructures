#include <iostream>
#include <vector>
#include "includes/bst.h"
#include "includes/avl.h"
#include "includes/algorithms/insertions_sort.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vec = {4, 2, 6, 10, 1};

    insertionSort(vec);

    for (auto i : vec) {
        cout << i << ' ';
    }
    return 0;
}