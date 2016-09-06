#include "../includes/container/disj_sets.h"

disj_sets::disj_sets(int numElements) : s(numElements, -1) {}

void disj_sets::unionSets(int root1, int root2) {
    s[root2] = root1;
}

int disj_sets::find(int x) const {
    if (s[x] < 0) {
        return x;
    } else {
        return find(s[x]);
    }
}
