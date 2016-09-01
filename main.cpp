#include <iostream>
#include <vector>
#include "includes/DisjSets.h"

using std::cout;
using std::vector;

int main() {
    DisjSets d(10);
    d.unionSets(2, 3);
    d.unionSets(2, 4);
    d.unionSets(3, 5);
    cout << d.find(5);
}