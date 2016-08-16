#include <iostream>

using namespace std;

class Node {
    public:
        Node(int value);
        Node* next;
        Node* prev;

        int value;
        void print();
};

Node::Node(int value) {
    this->value = value;
    this->next = NULL;
    this->prev = NULL;
}

void Node::print() {
    cout << value << endl;
}

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();

        Node* head;

        void insert(Node* node);
        void remove(Node* node);
        Node* search(int value);
        void print();
};

LinkedList::LinkedList() {
    this->head = new Node(0);
}

LinkedList::~LinkedList() {
    Node* iter_node = this->head;

    while(iter_node->prev) {
        iter_node = iter_node->prev;
        delete iter_node->next;
    }

    delete iter_node;
}

void LinkedList::insert(Node* node) {
    Node* head = this->head;

    Node* prev = head->prev;

    node->next = head;
    head->prev = node;

    if(prev) {
        prev->next = node;
        node->prev = prev;
    }
}

void LinkedList::remove(Node* node) {

    if(!node)
        throw runtime_error("Attempting to delete empty node");

    Node* prev = node->prev;
    Node* next = node->next;    

    if(prev)
        prev->next = next;
    if(next)
        next->prev = prev;

    delete node;
}

Node* LinkedList::search(int value) {
    Node* iter_node = this->head;

    while(iter_node->prev) {
        iter_node = iter_node->prev;
        if(iter_node->value == value)
            return iter_node;
    }

    return NULL;
}

void LinkedList::print() {
    Node* iter_node = this->head;
    while(iter_node->prev) {
        iter_node = iter_node->prev;
        cout << iter_node->value << " ";
    }
    cout << endl;
}

int main() {

    LinkedList list;
    for(int i = 0; i < 5; i++) {
        Node* node = new Node(i);
        list.insert(&(*node));
        list.print();
    }

    for(int i = 0; i < 6; i++) {
        Node*node = list.search(i);
        list.remove(node);
        list.print();
    }
}
