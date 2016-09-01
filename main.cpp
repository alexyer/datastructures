#include <iostream>
#include <vector>
#include "includes/algorithms/heap_sort.h"
#include "includes/algorithms/merge_sort.h"
#include "includes/algorithms/quick_sort.h"

using std::cout;
using std::vector;

int main() {
    vector<int> vec = {31, 41, 59, 26, 53, 58, 97};
    quickSort(vec);
    for (auto i : vec) {
        cout << i << ' ';
    }
}