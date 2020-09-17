#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    Tree<> tree;
    cout << boolalpha << tree.addNode(10,10);
    cout << boolalpha << tree.addNode(8,11);
    cout << boolalpha << tree.addNode(15,12) << endl;
    tree.printTree();
    cout << endl;
    tree.printKeys();
    cout << endl;
    cout << tree.getData(8) << endl;
    cout << tree.setNode(8,133) << endl;
    cout << tree.getData(8) << endl;
    cout << tree.getData(8) << endl;
    return 0;
}
