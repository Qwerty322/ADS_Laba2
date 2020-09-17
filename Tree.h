#ifndef ALGORITMLABA2_TREE_TREE_H
#define ALGORITMLABA2_TREE_TREE_H

#include <iostream>

using namespace std;

template<class Key = int, class Data = int>
class Tree {
private:
    class Node {
    private:

        Key key;
        Data data;

    public:
        Node *left;
        Node *right;

        explicit Node(Key key, Data data = Data(), Node *left = nullptr, Node *right = nullptr);

        Key getKey();

        Data getData();

        void setKey(Key k);

        void setData(Data d);

    };

    class Iterator {
    private:
        Tree *tree;
        Node *current;

    public:
        Iterator(Tree<Key, Data> &tree);

        Data &operator*();

        void operator++();

        void operator++(int);

        void operator--();

        void operator--(int);

        bool operator==(Iterator *right);

        bool operator!=(Iterator *right);

    };

    class Reverse_Iterator {
    private:
        Tree *tree;
        Node *current;

    public:
        Reverse_Iterator(Tree<Key, Data> &tree);

        Data &operator*();

        void operator++();

        void operator++(int);

        void operator--();

        void operator--(int);

        bool operator==(Reverse_Iterator *right);

        bool operator!=(Reverse_Iterator *right);
    };

    Node *root;
    int size;
    int count_view;

    Node *addNode(Node *node, Key key, Data data);

    Node *getNode(Node *node, Key key);

    void clear(Node *node);

    void out(Node *node, int k);

    void printKeys(Node *node);

    Node *findMaxNode();


public:

    Tree();

    Tree(Tree &Right);

    ~Tree();

    int getSize();

    void clear();

    bool isEmpty();

    Data getData(Key key);

    bool setNode(Key key, Data data);

    bool addNode(Key key, Data data);

    bool removeNode(Key key);

    void printKeys();

    void printTree();

    int numberNode(Key key);

    Tree::Iterator begin();

    Tree::Iterator end();

    Tree::Reverse_Iterator rbegin();

    Tree::Reverse_Iterator rend();


};

template<class Key, class Data>
Tree<Key, Data>::Tree() {
    root = nullptr;
    size = 0;
    count_view = 0;
}

template<class Key, class Data>
Tree<Key, Data>::Tree(Tree &Right) {
    root = Right.root;
    size = Right.size;
    count_view = 0;
}

template<class Key, class Data>
Tree<Key, Data>::~Tree() {

}

template<class Key, class Data>
int Tree<Key, Data>::getSize() {
    return size;
}

template<class Key, class Data>
bool Tree<Key, Data>::isEmpty() {
    return root == nullptr;
}


template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getNode(Tree::Node *node, Key key) {
    if (!node) {
        return nullptr;
    }
    if (node->getKey() > key) {
        node = getNode(node->left, key);
    } else if (node->getKey() < key) {
        node = getNode(node->right, key);
    } else return node;
    return node;

}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::addNode(Tree::Node *node, Key key, Data data) {
    if (root == nullptr) {
        Node *tmp = new Node(key, data);
        size++;
        root = tmp;
        return tmp;
    }
    if (node == nullptr) {
        Node *tmp = new Node(key, data);
        size++;
        return tmp;
    } else {
        if (key < node->getKey()) {
            node->left = addNode(node->left, key, data);
            return node;
        } else if (key > node->getKey()) {
            node->right = addNode(node->right, key, data);
            return node;
        } else return nullptr;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::clear(Node *node) {
    if (node) {
        if (node->left) clear(node->left);
        if (node->right) clear(node->right);
        delete node;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::clear() {
    if (isEmpty()) return;
    clear(root);
}

template<class Key, class Data>
void Tree<Key, Data>::out(Tree::Node *node, int k) {
    if (node) {
        out(node->right, k + 1);
        for (int i = 0; i < k; i++) {
            cout << "       ";
        }
        cout << node->getKey() << " (" << node->getData() << ")" << endl;
        out(node->left, k + 1);
    } else {
        for (int i = 0; i < k; i++) {
            cout << "       ";
        }
        cout << '*' << endl;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::printTree() {
    if (isEmpty()) return;
    out(root, 0);
}

template<class Key, class Data>
bool Tree<Key, Data>::addNode(Key key, Data data) {
    return addNode(root, key, data) != nullptr;
}

template<class Key, class Data>
void Tree<Key, Data>::printKeys() {
    if (isEmpty()) return;
    printKeys(root);
}

template<class Key, class Data>
void Tree<Key, Data>::printKeys(Tree::Node *node) {
    if (node) {
        cout << node->getKey() << " ";
        if (node->left) printKeys(node->left);
        if (node->right) printKeys(node->right);
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::setNode(Key key, Data data) {
    Node *tmp = getNode(root, key);
    if (tmp) {
        tmp->setData(data);
        return true;
    } else
        return false;
}

template<class Key, class Data>
Data Tree<Key, Data>::getData(Key key) {
    Node *tmp = getNode(root, key);
    if (tmp) {
        return tmp->getData();
    } else
        throw runtime_error("EXCEPTION!");
}

template<class Key, class Data>
Tree<Key, Data>::Node::Node(Key key, Data data, Tree::Node *left, Tree::Node *right) {
    this->key = key;
    this->data = data;
    this->left = left;
    this->right = right;
}

template<class Key, class Data>
Key Tree<Key, Data>::Node::getKey() {
    return this->key;
}

template<class Key, class Data>
Data Tree<Key, Data>::Node::getData() {
    return this->data;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setKey(Key k) {
    this->key = k;
}

template<class Key, class Data>
void Tree<Key, Data>::Node::setData(Data d) {
    this->data = d;
}

#endif //ALGORITMLABA2_TREE_TREE_H
