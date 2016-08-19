#include <iostream>

using namespace std;

const int BLACK = 0;
const int RED = 1;

class Node {
    public:

        Node(int value);

        int value;
        int color;

        Node* left;
        Node* right;
        Node* parent;

};

Node::Node(int value) {
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
    this->value = value;
    this->color = RED;
}

class Tree {
    public:
        Tree();

        Node* root;
        Node* nil;

        void insert(Node* node);
        void remove(Node* node);

        Node* search(int value);

        void print();
        void inorder_traversal(Node* node, int level);

    private:
        void left_rotate(Node* node);
        void right_rotate(Node* node);

        void transplant(Node* u, Node* v);

        void insert_fixup(Node* node);
        void remove_fixup(Node* node);

        Node* minimum(Node* node);
        Node* maximum(Node* node);
};

Tree::Tree() {
    this->nil = new Node(0);
    this->nil->parent = NULL;
    this->nil->left = NULL;
    this->nil->right = NULL;
    this->nil->color = BLACK;
    this->root = this->nil;
}

Node* Tree::minimum(Node* node) {
    Node* iter_node = node;
    while(iter_node->left && iter_node->left != this->nil)
        iter_node = iter_node->left;
    return iter_node;
}

Node* Tree::maximum(Node* node) {
    Node* iter_node = node;
    while(iter_node->right && iter_node->right != this->nil)
        iter_node = iter_node->right;
    return iter_node;
}

void Tree::left_rotate(Node* node) {
    Node* child_node = node->right;

    node->right = child_node->left;
    if(child_node->left != this->nil)
        child_node->left->parent = node;

    child_node->parent = node->parent;
    if(node->parent == this->nil)
        this->root = child_node;
    else if (node == node->parent->left)
        node->parent->left = child_node; 
    else
        node->parent->right = child_node;

    child_node->left = node;
    node->parent = child_node;
}

void Tree::right_rotate(Node* node) {
    Node* child_node = node->left;
    
    node->left = child_node->right;
    if(child_node->right != this->nil)
        child_node->right->parent = node;

    child_node->parent = node->parent;
    if(node->parent == this->nil)
        this->root = child_node;
    else if (node == node->parent->left)
        node->parent->left = child_node;
    else
        node->parent->right = child_node;

    child_node->right = node; 
    node->parent = child_node;
}

void Tree::insert(Node* node) {
    Node* iter_node = this->root;
    Node* parent = this->nil;

    while(iter_node != this->nil) {
        parent = iter_node;
        if(iter_node->value > node->value)
            iter_node = iter_node->left;
        else
            iter_node = iter_node->right;
    }

    node->parent = parent;

    if(parent == this->nil)
        this->root = node;
    else if (parent->value > node->value)
        parent->left = node;
    else
        parent->right = node;
    node->left = this->nil;
    node->right = this->nil;
    node->color = RED;
    insert_fixup(node);
}

void Tree::insert_fixup(Node* node) {
    while(node->parent->color == RED) {
        if(node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if(uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    left_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(node->parent->parent);
            } 
        } else {
            Node* uncle = node->parent->parent->left;
            if(uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if(node == node->parent->left) {
                    node = node->parent;
                    right_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(node->parent->parent);
            }
        }
    }
    this->root->color = BLACK;
}

void Tree::print() {
    inorder_traversal(this->root, 0);
    cout << endl;
}

void Tree::inorder_traversal(Node* node, int level) {
    if(node && node != this->nil) {
        inorder_traversal(node->left, level+1);
        cout << node->value << "(" << level << "," << node->color << ")" << " ";
        inorder_traversal(node->right, level+1);
    }
}

void Tree::transplant(Node* out_node, Node* in_node) {
    if(out_node->parent == this->nil)
        this->root = in_node;
    else if (out_node == out_node->parent->left)
        out_node->parent->left = in_node;
    else
        out_node->parent->right = in_node;
    in_node->parent = out_node->parent;
}

void Tree::remove(Node* node) {
    Node* copy_node = node;
    Node* fixup_node;
    int orig_color = copy_node->color;

    if(node->left == this->nil) {
        fixup_node = node->right;
        transplant(node, node->right);
    } else if (node->right == this->nil) {
        fixup_node = node->left;
        transplant(node, node->left);
    } else {
        copy_node = minimum(node->right);
        orig_color = copy_node->color;
        fixup_node = copy_node->right;
        if(copy_node->parent == node)
            fixup_node->parent = copy_node;
        else {
            transplant(copy_node, copy_node->right);
            copy_node->right = node->right;
            copy_node->right->parent = copy_node;
        }
        transplant(node, copy_node);
        copy_node->left = node->left;
        copy_node->left->parent = copy_node;
        copy_node->color = node->color;
    }
    if(orig_color == BLACK)
        remove_fixup(fixup_node);
}

void Tree::remove_fixup(Node* node) {
    cout << "remove_fixup" << endl;
    print();

   while(node != this->root && node->color == BLACK) {
       if(node == node->parent->left) {
           Node* sibling = node->parent->right;
           if(sibling->color == RED) {                  // Case 1: Turn sibling into red node
               sibling->color = BLACK;
               node->parent->color = RED;
               left_rotate(node->parent);
               sibling = node->parent->right;
               cout << "case1" << endl;
               print();
           }
           if(sibling->left->color == BLACK && sibling->right->color == BLACK) {                    // Case 2: Remove black from sibling, run algorithm on parent
               sibling->color = RED;
               node = node->parent;
               cout << "case2" << endl;
               print();
           } else {
               if(sibling->right->color == BLACK) {                 // Case 3: If sibling=BLACK, left child=RED -- Rotate right
                   sibling->left->color = BLACK;
                   sibling->color = RED;
                   right_rotate(sibling);
                   sibling = node->parent->right;
                   cout << "case3" << endl;
                   print();
               }
               sibling->color = node->parent->color;                    // Case 4: right child=RED -- rotate left
               node->parent->color = BLACK;
               sibling->right->color = BLACK;
               left_rotate(node->parent);
               node = this->root;
               cout << "case4" << endl;
               print();
           }
       } else {
           Node* sibling = node->parent->left;
           if(sibling->color == RED) {
               sibling->color = BLACK;
               node->parent->color = RED;
               right_rotate(node->parent);
               sibling = node->parent->left;
               cout << "case5" << endl;
               print();
           }
           if(sibling->left->color == BLACK && sibling->right->color == BLACK) {
               sibling->color = RED;
               node = node->parent;
               cout << "case6" << endl;
               print();
           } else {
               if(sibling->left->color == BLACK) {
                   sibling->right->color = BLACK;
                   sibling->color = RED;
                   left_rotate(sibling);
                   sibling = node->parent->left;
                   cout << "case7" << endl;
                   print();
               }
               sibling->color = node->parent->color;
               node->parent->color = BLACK;
               sibling->left->color = BLACK;
               right_rotate(node->parent);
               node = this->root;
               cout << "case8" << endl;
               print();
           }
       }
   }
   node->color = BLACK;
}

Node* Tree::search(int value) {

    Node* iter_node = this->root;

    while(iter_node && iter_node != this->nil) {
        if(iter_node->value == value)
            return iter_node;
        if(iter_node->value > value)
            iter_node = iter_node->left;
        else
            iter_node = iter_node->right;
    }

    return NULL;
}



int main() {

    Tree tree;

    tree.insert(new Node(10));
    tree.print();

    tree.insert(new Node(5));
    tree.print();

    tree.insert(new Node(13));
    tree.print();

    tree.insert(new Node(1));
    tree.print();

    tree.insert(new Node(2));
    tree.print();

    tree.insert(new Node(21));
    tree.print();

    tree.insert(new Node(20));
    tree.print();

    tree.remove(tree.search(1));
    tree.print();

    tree.remove(tree.search(5));
    tree.print();

    tree.remove(tree.search(2));
    tree.print();
}
