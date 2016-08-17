#include <iostream>
#include "includes/bst.h"

using std::cout;
using std::endl;

int main() {
    BinarySearchTree<int> bst;

    bst.insert(2);
    bst.insert(3);
    bst.insert(100);
    bst.insert(-100);
    bst.insert(24);
    bst.insert(45);
    bst.insert(434);
    bst.insert(10);

    bst.printTree();
    return 0;
}