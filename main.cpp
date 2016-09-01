#include <iostream>
#include <vector>
#include "includes/bst.h"
#include "includes/avl.h"
#include "includes/algorithms/heap_sort.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
    vector<int> vec = {31, 41, 59, 26, 53, 58, 97};
    heapSort(vec);
    for (auto i : vec) {
        cout << i << ' ';
    }
}