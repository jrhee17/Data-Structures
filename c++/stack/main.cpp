#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>

using namespace std;

class Stack{
    public:
        Stack();
        Stack(int size);
        ~Stack();

        void push(int value);
        int pop();
        int size();
        void print();
        bool empty();

    private:
        int stack_size;
        int* array;

        int end_ind;
};

Stack::Stack(void) {
    this->stack_size = 100;
    this->array = new int[this->stack_size];
    this->end_ind = 0;
}

Stack::Stack(int stack_size) {
    this->stack_size = stack_size;
    this->array = new int[stack_size];
    this->end_ind = 0;
}

Stack::~Stack() {
    delete[] this->array;
}

void Stack::push(int value) {
    
    // Check if index array is full
    if(size() == this->stack_size) {

        // Create a new stack of size multiplied by 2
        int *before_address = &(*this->array);
        int before_stack_size = this->stack_size;

        this->stack_size *= 2;
        int* new_array = new int[this->stack_size];
        copy(this->array, this->array + this->end_ind, new_array);
        delete[] this->array;
        this->array = new_array;

        int *after_address = &(*this->array);
        int after_stack_size = this->stack_size;

        cout << "Increasing array length: " << before_stack_size << " (" << before_address << ") to " << after_stack_size << " ("<< after_address << ")" << endl;
    }

    this->array[this->end_ind] = value;
    this->end_ind++;

}

int Stack::pop() {
    if(empty())
        throw runtime_error("Underflow Error"); 

    // Check if size is decreased enough to reduce size
    if(this->stack_size / 2 == size() && this->stack_size > 1) {

        int *before_address = &(*this->array);
        int before_stack_size = this->stack_size;

        // Create a new stack of size divided by 2
        this->stack_size /= 2;
        int* new_array = new int[this->stack_size];
        copy(this->array, this->array + this->end_ind, new_array);
        delete[] this->array;
        this->array = new_array;

        int *after_address = &(*this->array);
        int after_stack_size = this->stack_size;

        cout << "Decreasing array length: " << before_stack_size << " (" << before_address << ") to " << after_stack_size << " ("<< after_address << ")" << endl;
    }

    int value = this->array[this->end_ind];
    this->end_ind--;

    return value;
}

int Stack::size() {
    return this->end_ind;
}

bool Stack::empty() {
    if (size() == 0)
        return true;
    return false;
}

void Stack::print() {
    for(int i = 0; i < this->end_ind; i++)
        cout << *(this->array + i) << " ";
    cout << endl;
}

int main() {

    cout << "Pushing 20 values and popping 30 values..." << endl;

    Stack stack(5);
    for(int i = 0; i < 20; i++) {
        stack.push(i);
        stack.print();
    }

    for(int i = 0; i < 30; i++) {
        stack.pop();
        stack.print();
    }

    return 1;
}
