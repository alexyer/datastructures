//
// Created by pat on 18.08.16.
//

#ifndef DATASTRUCTURES_BTREE_NODE_H
#define DATASTRUCTURES_BTREE_NODE_H

#include <iostream>
#include <vector>

using std::cout;
using std::vector;


class BTreeNode {
    bool leaf;
    int currentKeysNum;
    int minimumDegree;
    vector<int> keys;
    vector<BTreeNode*> children;

public:
    BTreeNode::BTreeNode(bool leaf, int minimumDegree) : leaf(leaf), minimumDegree(minimumDegree),
                                                         currentKeysNum(0) {}

    void traverse() {
        int i = 0;
        for (i; i < currentKeysNum; ++i) {
            if (!leaf) {
                children[i]->traverse();
            }
            cout << ' ' << keys[i];
        }

        if (!leaf) {
            children[i]->traverse();
        }
    }

    const BTreeNode& search(int k) const;
    friend class BTree;
};

#endif //DATASTRUCTURES_BTREE_NODE_H
