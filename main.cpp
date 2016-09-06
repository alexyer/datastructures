#include <iostream>
#include <vector>
#include "includes/chaining_hashmap.h"

using std::cout;
using std::vector;

int main() {
    ChainingHashMap<std::string, std::string> hash;
    vector<std::string> v;

    for (int i = 0; i < 100; ++i) {
        hash.put(std::to_string(i), "test");
    }

    hash.print();
}