//
// Created by pat on 01.09.16.
//

#include "../includes/DisjSets.h"

DisjSets::DisjSets(int numElements) : s(numElements, -1) {}

void DisjSets::unionSets(int root1, int root2) {
    s[root2] = root1;
}

int DisjSets::find(int x) const {
    if (s[x] < 0) {
        return x;
    } else {
        return find(s[x]);
    }
}
