#include <iostream>

using namespace std;

class Node {
    public:
        Node(int value);

        Node* left;
        Node* right;
        Node* parent;
        int value;
};

Node::Node(int value) {
    this->value = value;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

class Tree {
    public:
        Tree();

        Node* root;

        void print();
        void inorder_traverse(Node* node, int level);
        void preorder_traverse(Node* node);
        void postorder_traverse(Node* node);

        Node* recursive_search(Node* node, int value);
        Node* iterative_search(Node* node, int value);

        Node* minimum(Node* node);
        Node* maximum(Node* node);

        Node* successor(Node* node);
        Node* predecessor(Node* node);

        void insert(Node* node);
        void remove(Node* node);

    private:
        void transplant(Node* parent, Node* child);
};

Tree::Tree() {
    this->root = NULL;
}

void Tree::print() {
    inorder_traverse(this->root, 0);
    cout << endl;
}

void Tree::inorder_traverse(Node* node, int level) {
    if(node) {
        inorder_traverse(node->left, level + 1);
        cout << node->value << "(" << level << ") ";
        inorder_traverse(node->right, level + 1);
    }
}

void Tree::preorder_traverse(Node* node) {

}

void Tree::postorder_traverse(Node* node) {

}

Node* Tree::recursive_search(Node* node, int value) {
    if(!node || node->value == value)
        return node;

    if(node->value > value)
        return recursive_search(node->left, value);
    else
        return recursive_search(node->right, value);
}

Node* Tree::iterative_search(Node* node, int value) {
    while(node && node->value != value) {
        if(node->value > value)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

Node* Tree::minimum(Node* node) {
    Node* iter_node = node;
    while(iter_node->left)
        iter_node = iter_node->left;
    return iter_node;
}

Node* Tree::maximum(Node* node) {
    Node* iter_node = node;
    while(iter_node->right)
        iter_node = iter_node->right;
    return iter_node;
}

Node* Tree::successor(Node* node) {
    Node* orig_node = node;
    if(orig_node->right)
        return minimum(orig_node->right);
    Node* iter_node = orig_node->parent;
    while(iter_node && orig_node == iter_node->right) {
        orig_node = iter_node;
        iter_node = iter_node->parent;
    }
    return iter_node;
}

Node* Tree::predecessor(Node* node) {
    Node* orig_node = node;
    if(orig_node->left)
        return maximum(orig_node->left);
    Node* iter_node = orig_node->parent;
    while(iter_node && orig_node == iter_node->left) {
        orig_node = iter_node;
        iter_node = iter_node->parent;
    }
    return iter_node;
}

void Tree::insert(Node* node) {

    Node* iter_node = this->root;
    while(iter_node && iter_node->left && iter_node->right) {
        if(iter_node->value > node->value)
            iter_node = iter_node->left;
        else
            iter_node = iter_node ->right;
    }

    node->parent = iter_node;

    if(!iter_node)
        this->root = node;
    else if (iter_node->value > node->value)
        iter_node->left = node;
    else
        iter_node->right = node;
}

void Tree::transplant(Node* remove_node, Node* insert_node) {
    if(!remove_node->parent)
        this->root = insert_node;
    else if(remove_node == remove_node->parent->left)
        remove_node->parent->left = insert_node;
    else
        remove_node->parent->right = insert_node;
    if(insert_node)
        insert_node->parent = remove_node->parent;
}

void Tree::remove(Node* node) {
    if(!node->left)
        transplant(node, node->right);
    else if (!node->right)
        transplant(node, node->left);
    else {
        Node* min_node = minimum(node->right);
        if(min_node->parent != node) {
            transplant(min_node, min_node->right);
            min_node->right = node->right;
            min_node->right->parent = min_node;
        }
        transplant(node, min_node);
        min_node->left = node->left;
        min_node->left->parent = min_node;
    }
    delete node;
}

int main() {

    Tree tree;
    tree.insert(new Node(12));
    tree.print();
    tree.insert(new Node(5));
    tree.print();
    tree.insert(new Node(18));
    tree.print();
    tree.insert(new Node(2));
    tree.print();
    tree.insert(new Node(9));
    tree.print();
    tree.insert(new Node(15));
    tree.print();
    tree.insert(new Node(19));
    tree.print();
    tree.insert(new Node(17));
    tree.print();
    tree.insert(new Node(13));
    tree.print();

    tree.remove(tree.iterative_search(tree.root, 12));
    tree.print();
    tree.remove(tree.iterative_search(tree.root, 13));
    tree.print();
}
