#include <iostream>
#include <vector>
#include "includes/algorithm/heap_sort.h"
#include "includes/algorithm/insertion_sort.h"
#include "includes/algorithm/merge_sort.h"
#include "includes/algorithm/quick_sort.h"
#include "includes/container/chaining_hashmap.h"

using std::cout;
using std::vector;

int main() {
    vector<int> v = {1, 4, 2 ,10, 3, 100, 42, 434, 32};
    ChainingHashMap<int, std::string> map;

    quickSort(v.begin(), v.end());
    insertionSort(v.begin(), v.end());
    mergeSort(v);

    for (auto i: v) {
        std::cout << i << " ";
    }
}