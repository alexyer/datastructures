#ifndef DATASTRUCTURES_DISJSETS_H
#define DATASTRUCTURES_DISJSETS_H

#include <vector>

using std::vector;


class disj_sets {
public:
    explicit disj_sets(int numElements);

    int find(int x) const;
    void unionSets(int root1, int root2);

private:
    vector<int> s;
};


#endif //DATASTRUCTURES_DISJSETS_H
