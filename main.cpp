#include <iostream>
#include "Tree.h"
#include "test.cpp"

using namespace std;

int main() {
    Tree<> tree;
    cout << boolalpha << tree.addNode(10, 10) << endl << tree.getViewNode();
    cout << boolalpha << tree.addNode(8, 11) << endl << tree.getViewNode();
    cout << boolalpha << tree.addNode(15, 12) << endl << tree.getViewNode();
    cout << boolalpha << tree.addNode(19, 12) << endl << tree.getViewNode();
    cout << boolalpha << tree.addNode(14, 12) << endl << tree.getViewNode();
    cout << boolalpha << tree.addNode(4, 12) << endl;
    cout << boolalpha << tree.addNode(17, 12) << endl;
    cout << boolalpha << tree.addNode(20, 12) << endl;
    tree.printTree();
    cout << endl;
    tree.printKeys();
    cout << endl;
    cout << boolalpha << tree.removeNode(19) << endl << tree.getViewNode();
    tree.printTree();
    tree.setNode(4, 123);
    try {
        cout << tree.getData(4) << endl;
    } catch (runtime_error error) {
        cout << error.what();
    }
    cout << endl;
    cout << tree.numberNode(17);

    return 0;
}
