#ifndef ALGORITMLABA2_TREE_TREE_H
#define ALGORITMLABA2_TREE_TREE_H

#include <iostream>
#include <stack>

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
        int count = 0;

        explicit Node(Key key, Data data = Data(), Node *left = nullptr, Node *right = nullptr);

        Key getKey();

        Data &getData();

        void setKey(Key k);

        void setData(Data d);

    };

    int size;
    int count_view;

    Node *addNode(Node *node, Key key, Data data);

    Node *getNode(Node *node, Key key);

    Node *removeNode(Node *node, Key key, bool &flag);

    void clear(Node *node);

    void out(Node *node, int k);

    void printKeys(Node *node);

    Node *findMaxNode(Node *node);

    Node *findMinNode(Node *node);

    Node *getIndexByKey(Node *node, Key key, int &index);


public:
    Node *root;

    class Iterator {
    private:
        Tree *tree;
        Node *current;
        stack<Node *> stack;


    public:
        explicit Iterator(Tree<Key, Data> *tree);

        void toBegin();

        void toEnd();

        void checkException();

        bool hasTree();

        bool hasNext();

        Data &operator*();

        void operator++();

        void operator++(int);

        void operator--();

        void operator--(int);

        bool operator==(Iterator right);

        bool operator!=(Iterator right);

    };

    class Reverse_Iterator {
    private:
        Tree *tree;
        Node *current;
        stack<Node *> stack;

    public:
        explicit Reverse_Iterator(Tree<Key, Data> *tree);

        void toBegin();

        void toEnd();

        void checkException();

        bool hasTree();

        bool hasNext();

        Data &operator*();

        void operator++();

        void operator++(int);

        void operator--();

        void operator--(int);

        bool operator==(Reverse_Iterator right);

        bool operator!=(Reverse_Iterator right);
    };

    Tree();

    Tree(Tree &Right);

    ~Tree();

    int getSize();

    int getViewNode();

    void clear();

    bool isEmpty();

    Data getData(Key key);

    bool setNode(Key key, Data data);

    bool addNode(Key key, Data data);

    bool removeNode(Key key);

    void printKeys();

    void printTree();

    int getIndexByKey(Key key);

    Tree::Iterator begin();

    Tree::Iterator end();

    Tree::Reverse_Iterator rbegin();

    Tree::Reverse_Iterator rend();

};

template<class Key, class Data>
Tree<Key, Data>::Reverse_Iterator::Reverse_Iterator(Tree<Key, Data> *tree) {
    this->tree = tree;
    this->current = this->tree->root;
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::toBegin() {
    checkException();
    while (current->right != nullptr) {
        stack.push(current);
        current = current->right;
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::Reverse_Iterator::hasTree() {
    return this->tree != nullptr;
}

template<class Key, class Data>
bool Tree<Key, Data>::Reverse_Iterator::hasNext() {
    return this->current != nullptr;
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::checkException() {
    if (!hasTree()) {
        throw runtime_error("EXCEPTION!");
    }
    if (!hasNext()) {
        throw runtime_error("EXCEPTION!");
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::toEnd() {
    checkException();
    while (current != nullptr) {
        stack.push(current);
        current = current->left;
    }
}

template<class Key, class Data>
Data &Tree<Key, Data>::Reverse_Iterator::operator*() {
    checkException();
    return current->getData();
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::operator++() {
    checkException();
    if (current->left != nullptr) {
        current = current->left;
        while (current->right != nullptr) {
            stack.push(current);
            current = current->right;
        }
    } else {
        if (stack.empty()) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::operator++(int) {
    checkException();
    if (current->left != nullptr) {
        current = current->left;
        while (current->right != nullptr) {
            stack.push(current);
            current = current->right;
        }
    } else {
        if (stack.empty()) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::operator--() {
    checkException();
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            stack.push(current);
            current = current->left;
        }
    } else {
//        Node *tmp = stack.top();
        if (stack.empty() || current == stack.top()->right) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Reverse_Iterator::operator--(int) {
    checkException();
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            stack.push(current);
            current = current->left;
        }
    } else {
        if (stack.empty() || current == stack.top()->right) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::Reverse_Iterator::operator==(Tree::Reverse_Iterator right) {
    return this->current == right.current;
}

template<class Key, class Data>
bool Tree<Key, Data>::Reverse_Iterator::operator!=(Tree::Reverse_Iterator right) {
    return this->current != right.current;
}


template<class Key, class Data>
Tree<Key, Data>::Iterator::Iterator(Tree<Key, Data> *tree) {
    this->tree = tree;
    this->current = this->tree->root;
}

template<class Key, class Data>
Data &Tree<Key, Data>::Iterator::operator*() {
    checkException();
    return current->getData();
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::operator++() {
    checkException();
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            stack.push(current);
            current = current->left;
        }
    } else {
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::checkException() {
    if (!hasTree()) {
        throw runtime_error("EXCEPTION!");
    }
    if (!hasNext()) {
        throw runtime_error("EXCEPTION!");
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::hasTree() {
    return this->tree != nullptr;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::hasNext() {
    return this->current != nullptr;
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::toBegin() {
    checkException();
    while (current->left != nullptr) {
        stack.push(current);
        current = current->left;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::toEnd() {
    checkException();
    while (current != nullptr) {
        stack.push(current);
        current = current->right;
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::operator++(int) {
    checkException();
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            stack.push(current);
            current = current->left;
        }
    } else {
        if (stack.empty()) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::operator--() {
    checkException();
    if (current->left != nullptr) {
        current = current->left;
        while (current->right != nullptr) {
            stack.push(current);
            current = current->right;
        }
    } else {
        if (stack.empty() || current == stack.top()->left) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
void Tree<Key, Data>::Iterator::operator--(int) {
    checkException();
    if (current->left != nullptr) {
        current = current->left;
        while (current->right != nullptr) {
            stack.push(current);
            current = current->right;
        }
    } else {
        if (stack.empty() || current == stack.top()->left) {
            throw runtime_error("EXCEPTION");
        }
        current = stack.top();
        stack.pop();
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator==(Tree::Iterator right) {
    return this->current == right.current;
}

template<class Key, class Data>
bool Tree<Key, Data>::Iterator::operator!=(Tree::Iterator right) {
    return this->current != right.current;
}

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
    clear();
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
        count_view++;
    } else if (node->getKey() < key) {
        node = getNode(node->right, key);
        count_view++;
    } else {
        count_view++;
        return node;
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::addNode(Tree::Node *node, Key key, Data data) {
    if (root == nullptr) {
        Node *tmp = new Node(key, data);
        tmp->count++;
        size++;
        root = tmp;
        count_view++;
        return tmp;
    }
    if (node == nullptr) {
        Node *tmp = new Node(key, data);
        tmp->count++;
        size++;
        count_view++;
        return tmp;
    } else {
        if (key < node->getKey()) {
            node->count++;
            node->left = addNode(node->left, key, data);
            count_view++;
            return node;
        } else if (key > node->getKey()) {
            node->count++;
            node->right = addNode(node->right, key, data);
            count_view++;
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
    root = nullptr;
    size = 0;
}

template<class Key, class Data>
void Tree<Key, Data>::out(Tree::Node *node, int k) {
    if (node) {
        out(node->right, k + 1);
        for (int i = 0; i < k; i++) {
            cout << "       ";
        }
        cout << node->getKey() << " (" << node->count << ")" << endl;
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
    count_view = 0;
    return addNode(root, key, data) != nullptr;
}

template<class Key, class Data>
void Tree<Key, Data>::printKeys() {
    if (isEmpty()) return;
    printKeys(root);
}

template<class Key, class Data>
void Tree<Key, Data>::printKeys(Node *node) {
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
    count_view = 0;
    Node *tmp = getNode(root, key);
    if (tmp) {
        return tmp->getData();
    } else
        throw runtime_error("EXCEPTION!");
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::findMaxNode(Node *node) {
    if (node == nullptr) {
        exit(3);
    }
    if (node->right) {
        count_view++;
        return findMaxNode(node->right);
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::findMinNode(Tree::Node *node) {
    if (node == nullptr) {
        exit(4);
    }
    if (node->left) {
        return findMinNode(node->left);
    }
    return node;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::removeNode(Tree::Node *node, Key key, bool &flag) {
    if (node == nullptr) {
        flag = true;
        return nullptr;
    }
    if (node->getKey() > key) {
        node->left = removeNode(node->left, key, flag);
        if (!flag) {
            node->count--;
        }
        count_view++;
        return node;
    } else if (node->getKey() < key) {
        node->right = removeNode(node->right, key, flag);
        if (!flag) {
            node->count--;
        }
        count_view++;
        return node;
    } else if (node->getKey() == key) {
        if (node->left && node->right) {
            Node *locMax = findMaxNode(node->left);
            node->setKey(locMax->getKey());
            node->setData(locMax->getData());
            node->count--;
            node->left = removeNode(node->left, locMax->getKey(), flag);
            return node;
        } else if (node->left) {
            Node *tmp = node->left;
            delete node;
            return tmp;
        } else if (node->right) {
            Node *tmp = node->right;
            delete node;
            return tmp;
        } else {
//            delete node;
            return nullptr;
        }
    }
}

template<class Key, class Data>
bool Tree<Key, Data>::removeNode(Key key) {
    count_view = 0;
    bool error_flag = false;
    removeNode(root, key, error_flag);
    if (!error_flag) {
        size--;
        return true;
    }
    return false;
}

template<class Key, class Data>
int Tree<Key, Data>::getIndexByKey(Key key) {
    count_view = 0;
    int index = 0;
    return getIndexByKey(root, key, index) != nullptr ? index : -1;
}

template<class Key, class Data>
int Tree<Key, Data>::getViewNode() {
    return count_view;
}

template<class Key, class Data>
typename Tree<Key, Data>::Node *Tree<Key, Data>::getIndexByKey(Tree::Node *node, Key key, int &index) {
    if (!node) {
        return nullptr;
    }
    if (node->getKey() == key) {
        if (node->left) {
            node = node->left;
            index += node->count;
        }
        return node;
    } else if (node->getKey() > key) {
        node = getIndexByKey(node->left, key, index);
        return node;
    } else if (node->getKey() < key) {
        if (node->left) {
            Node *tmp;
            tmp = node->left;
            index += tmp->count;
        }
        node = getIndexByKey(node->right, key, index);
        index++;
        return node;
    }
}

template<class Key, class Data>
typename Tree<Key, Data>::Iterator Tree<Key, Data>::begin() {
    Tree<Key, Data>::Iterator iterator(this);
    iterator.toBegin();
    return iterator;
}

template<class Key, class Data>
typename Tree<Key, Data>::Iterator Tree<Key, Data>::end() {
    Tree<Key, Data>::Iterator iterator(this);
    iterator.toEnd();
    return iterator;
}

template<class Key, class Data>
typename Tree<Key, Data>::Reverse_Iterator Tree<Key, Data>::rbegin() {
    Tree<Key, Data>::Reverse_Iterator iterator(this);
    iterator.toEnd();
    return iterator;
}

template<class Key, class Data>
typename Tree<Key, Data>::Reverse_Iterator Tree<Key, Data>::rend() {
    Tree<Key, Data>::Reverse_Iterator iterator(this);
    iterator.toBegin();
    return iterator;
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
Data &Tree<Key, Data>::Node::getData() {
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
