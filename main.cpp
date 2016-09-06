#include <iostream>
#include <vector>
#include "includes/chaining_hashmap.h"
#include "includes/algorithms/quick_sort.h"

using std::cout;
using std::vector;

int main() {
    vector<int> v = {1, 4, 2 ,10, 3};
    quickSort(v.begin(), v.end());

    for (auto i: v) {
        std::cout << i << " ";
    }
}