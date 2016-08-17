//
// Created by pat on 17.08.16.
//

#ifndef DATASTRUCTURES_AVL_H_H
#define DATASTRUCTURES_AVL_H_H

#include <algorithm>
#include "bst.h"
#include "avl_node.h"

using std::max;

template <typename Object, typename Comparator=less<Object>>
class AvlTree : public BinarySearchTree<Object> {
public:
    AvlTree() : root(nullptr) {};
    AvlTree(const AvlTree &rhs) : root(nullptr) {
        root = clone(rhs.root);
    };

    void insert(const Object& x) {
        insert(x, root);
    }

    const Object& findMin() const {
        return findMin(root)->element;
    }

    const Object& findMax() const {
        return findMax(root)->element;
    }

    void printTree() {
        printTree(root);
    }

    bool contains(const Object &x) const override {
        return contains(x, root);
    }

    int height(AvlNode<Object>* t) const {
        return t == nullptr ? -1 : t->height;
    }

    void remove(const Object &x) override {
        remove(x, root);
    }

private:
    AvlNode<Object>* root;
    Comparator isLessThan;
    static const int ALLOWED_IMBALANCE = 1;

    void insert(const Object& x, AvlNode<Object>*& t) {
        if (t == nullptr) {
            t = new AvlNode<Object>{x, nullptr, nullptr};
        } else if (isLessThan(x, t->element)) {
            insert(x, t->left);
        } else if (isLessThan(t->element, x)) {
            insert(x, t->right);
        }

        balance(t);
    }

    void balance(AvlNode<Object>*& t) {
        if (t == nullptr) {
            return;
        }

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
            if (height(t->left->left) >= height(t->left->right)) {
                rotateWithLeftChild(t);
            } else {
                doubleRotateWithLeftChild(t);
            }
        } else {
            if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
                if (height(t->right->right) >= height(t->right->left)) {
                    rotateWithRightChild(t);
                } else {
                    doubleRotateWithRightChild(t);
                }
            }
        }

        t->height = max(height(t->left), height(t->right) + 1);
    };

    AvlNode<Object>* clone(AvlNode<Object>* t) const {
        if (t == nullptr) {
            return nullptr;
        } else {
            return new AvlNode<Object>{t->element, clone(t->left), clone(t->right)};
        }
    };

    void printTree(AvlNode<Object> *t) {
        if (t == nullptr) {
            return;
        }
        queue<AvlNode<Object> *> currentLevel, nextLevel;
        currentLevel.push(t);
        while (!currentLevel.empty()) {
            auto currNode = currentLevel.front();
            currentLevel.pop();

            if (currNode != nullptr) {
                cout << currNode->element << ' ';
                nextLevel.push(currNode->left);
                nextLevel.push(currNode->right);
            } else {
                cout << "_ ";
            }
            if (currentLevel.empty()) {
                cout << endl;
                std::swap(currentLevel, nextLevel);
            }
        }
    }

    void rotateWithLeftChild(AvlNode<Object>*& k2) {
        auto k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right) + 1);
        k1->height = max(height(k1->left), height(k1->right) + 1);
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode<Object>*& k2) {
        auto k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2->height = max(height(k2->left), height(k2->right) + 1);
        k1->height = max(height(k1->left), height(k1->right) + 1);
        k2 = k1;
    }

    void doubleRotateWithLeftChild(AvlNode<Object>*& k3) {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    void doubleRotateWithRightChild(AvlNode<Object>*& k3) {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    AvlNode<Object>* findMin(AvlNode<Object>* t) const {
        if (t == nullptr) {
            return nullptr;
        }
        if (t->left == nullptr) {
            return t;
        }
        return findMin(t->left);
    };

    AvlNode<Object>* findMax(AvlNode<Object>* t) const {
        if (t == nullptr) {
            return nullptr;
        }
        if (t->right == nullptr) {
            return t;
        }
        return findMax(t->right);
    };


    bool contains(const Object& x, AvlNode<Object>* t) const {
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


    void remove(const Object& x, AvlNode<Object>*& t) {
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
};

#endif //DATASTRUCTURES_AVL_H_H
