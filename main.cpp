#include <iostream>
#include "includes/bst.h"
#include "includes/avl.h"

using std::cout;
using std::endl;

int main() {
    AvlTree<int> avl;

    avl.insert(2);
    avl.insert(3);
    avl.insert(100);
    avl.insert(-100);
    avl.insert(24);
    avl.insert(45);
    avl.insert(434);
    avl.insert(10);
    avl.insert(34);
    avl.insert(56);
    avl.insert(86);

    cout << "Min: " << avl.findMin() << " Max: " << avl.findMax() << endl;

    cout << avl.contains(2) << endl;
    avl.remove(2);
    cout << avl.contains(2) << endl;

    avl.printTree();
    return 0;
}