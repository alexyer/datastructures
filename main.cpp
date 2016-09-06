#include <iostream>
#include <vector>
#include "includes/chaining_hashmap.h"

using std::cout;
using std::vector;

int main() {
    ChainingHashMap<int, std::string> hash;
    vector<std::string> v;

    for (int i = 0; i < 1000000; ++i) {
        hash.put(i, "test");
    }

    for (int i = 0; i < 1000000; ++i) {
        v.push_back(hash.get(i));
    }
}