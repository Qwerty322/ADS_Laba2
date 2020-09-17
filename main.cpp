#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    Tree<> tree;
    cout << boolalpha << tree.addNode(10,10);
    cout << boolalpha << tree.addNode(8,11);
    cout << boolalpha << tree.addNode(15,12) << endl;
    cout << boolalpha << tree.addNode(19,12) << endl;
    cout << boolalpha << tree.addNode(14,12) << endl;
    cout << boolalpha << tree.addNode(4,12) << endl;
    cout << boolalpha << tree.addNode(17,12) << endl;
    cout << boolalpha << tree.addNode(20,12) << endl;
    tree.printTree();
    cout << endl;
    tree.printKeys();
    cout << endl;
    cout << boolalpha << tree.removeNode(15) << endl;
    tree.printTree();
//    cout << tree.getData(8) << endl;
//    cout << tree.setNode(8,133) << endl;
//    cout << tree.getData(8) << endl;

    return 0;
}
