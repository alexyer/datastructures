#ifndef DATASTRUCTURES_AVL_NODE_H
#define DATASTRUCTURES_AVL_NODE_H

#include <utility>
#include "binary_node.h"

template <typename Object>
struct AvlNode : public BinaryNode<Object> {
    Object element;
    AvlNode<Object>* left;
    AvlNode<Object>* right;
    int height;

    AvlNode(const Object& element, AvlNode<Object>* left,
            AvlNode<Object>* right, int height = 0) : element(element), left(left),
                                                      right(right), height(height) {}
    AvlNode(Object&& element, AvlNode<Object>* left,
            AvlNode<Object>* right, int height = 0) : element(std::move(element)), left(left),
                                                      right(right), height(height) {}
};

#endif //DATASTRUCTURES_AVL_NODE_H
