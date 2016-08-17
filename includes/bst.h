//
// Created by pat on 16.08.16.
//

#ifndef DATASTRUCTURES_BST_H
#define DATASTRUCTURES_BST_H

#include <functional>
#include <iostream>
#include "binary_node.h"

using std::ostream;
using std::cout;
using std::less;

template <typename Object, typename Comparator=less<Object>>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {};
    BinarySearchTree(const BinarySearchTree& rhs) : root(nullptr) {
        root = clone(rhs.root);
    };

    ~BinarySearchTree() {
        makeEmpty();
    };

    const Object& findMin() const {
        return findMin(root)->element;
    };

    const Object& findMax() const {
        return findMax(root)->element;
    };

    bool contains(const Object& x) const {
        return contains(x, root);
    };

    bool isEmpty() const {
        return root == nullptr;
    };

    void makeEmpty() {
        makeEmpty(root);
    };

    void insert(const Object& x) {
        insert(x, root);
    };

    void insert(Object&& x) {
        insert(x, root);
    };

    void remove(const Object& x) {
        remove(x, root);
    };

private:
    BinaryNode<Object> *root;
    Comparator isLessThan;

    void insert(const Object& x, BinaryNode<Object>*& t) {
        if (t == nullptr) {
            t = new BinaryNode<Object>{x, nullptr, nullptr};
        } else if (isLessThan(x, t->element)) {
            insert(x, t->left);
        } else if (isLessThan(t->element, x)) {
            insert(x, t->right);
        }
    };

    void insert(Object&& x, BinaryNode<Object>*& t) {
        if (t == nullptr) {
            t = new BinaryNode<Object>{x, nullptr, nullptr};
        } else if (isLessThan(x, t->element)) {
            insert(std::move(x), t->left);
        } else if (isLessThan(t->element, x)) {
            insert(std::move(x), t->right);
        }
    };

    void remove(const Object& x, BinaryNode<Object>*& t) {
        if (t == nullptr) {
            return;
        }

        if (isLessThan(x, t->element)) {
            remove(x, t->left);
        } else if (isLessThan(t->element,x )) {
            remove(x, t->right);
        } else if (t->left != nullptr && t->right != nullptr) {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        } else {
            auto oldNote = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNote;
        }
    };

    BinaryNode<Object>* findMin(BinaryNode<Object>* t) const {
        if (t == nullptr) {
            return nullptr;
        }
        if (t->left == nullptr) {
            return t;
        }
        return findMin(t->left);
    };

    BinaryNode<Object>* findMax(BinaryNode<Object>* t) const {
        if (t == nullptr) {
            return nullptr;
        }
        if (t->right == nullptr) {
            return t;
        }
        return findMax(t->right);
    };

    bool contains(const Object& x, BinaryNode<Object>* t) const {
        if (t == nullptr) {
            return false;
        } else if (isLessThan(x, t->element)) {
            return contains(x, t->left);
        } else if (isLessThan(t->element, x)) {
            return contains(x, t->right);
        } else {
            return true;
        }
    };

    void makeEmpty(BinaryNode<Object>*& t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    };

    BinaryNode<Object>* clone(BinaryNode<Object>* t) const {
        if (t == nullptr) {
            return nullptr;
        } else {
            return new BinaryNode<Object>{t->element, clone(t->left), clone(t->right)};
        }
    };
};

#endif //DATASTRUCTURES_BST_H
