//
// Created by pat on 17.08.16.
//

#ifndef DATASTRUCTURES_BINARY_NODE_H
#define DATASTRUCTURES_BINARY_NODE_H

template <typename Object>
struct BinaryNode {
    Object element;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(const Object& element, BinaryNode *left, BinaryNode *right) : element(element), left(left),
                                                                             right(right) {}
    BinaryNode(Object&& element, BinaryNode* left, BinaryNode* right) : element(element), left(left),
                                                                        right(right) {}
};

#endif //DATASTRUCTURES_BINARY_NODE_H
