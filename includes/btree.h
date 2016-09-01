//
// Created by pat on 18.08.16.
//

#ifndef DATASTRUCTURES_BTREE_H
#define DATASTRUCTURES_BTREE_H

#include "btree_node.h"

class BTree {
    BTreeNode* root;
    int t;

public:
    BTree(int t) : root(nullptr), t(t) {}

    void traverse() {
        if (root != nullptr) {
            root->traverse();
        }
    }

    const BTreeNode& search(int k) const {
        return (root == nullptr) ? nullptr : root->search(k);
    }
};


#endif //DATASTRUCTURES_BTREE_H
