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
    bst.remove(100);

    cout << bst.findMax();
    return 0;
}