#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

class Stack{
    public:
        Stack();
        void push(int value);
        int pop();
        int size();
        void print();
        bool empty();
    private:
        vector<int> vec;
};

Stack::Stack(void) {

}

void Stack::push(int value) {
    vec.push_back(value);

    print();
}

int Stack::pop() {
    if(empty())
        throw runtime_error("Underflow Error"); 

    int value = vec.back();
    vec.pop_back();

    print();

    return value;
}

int Stack::size() {
    return vec.size();
}

bool Stack::empty() {
    if (vec.size() == 0)
        return true;
    return false;
}

void Stack::print() {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {

    Stack stack;
    stack.push(1);
    stack.push(3);
    stack.pop();
    stack.push(5);
    stack.push(-1);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    return 1;
}
