#include <iostream>

using namespace std;

class Queue {
    public:
        Queue();
        Queue(int array_size);
        ~Queue();

        void enqueue(int value);
        int dequeue();
        void print();
        int size();

    private:
        int* array;
        int array_size;

        int start_ind;
        int end_ind;
        int count;
};

Queue::Queue() {
    this->array_size = 100;
    this->array = new int[100];

    this->start_ind = 0;
    this->end_ind = 0;
    this->count = 0;
}

Queue::Queue(int array_size) {
    this->array = new int[array_size];
    this->array_size = array_size;

    this->start_ind = 0;
    this->end_ind = 0;
    this->count = 0;
}

Queue::~Queue() {
    delete[] this->array;
}

void Queue::enqueue(int value) {

    // Check if size is greater than array size
    if(size() == this->array_size) {
        // Create new array with double of current array size
        int *new_array = new int[2 * this->array_size];
        
        // Copy all values to new array
        if(this->start_ind < this->end_ind) {
            copy(this->array + this->start_ind, this->array + this->end_ind, new_array);
        } else {
            copy(this->array + this->start_ind, this->array + this->array_size, new_array);
            copy(this->array, this->array + this->end_ind, new_array + this->array_size - this->start_ind);
        }


        this->start_ind = 0;
        this->end_ind = size();
        this->array_size *= 2;
        delete[] this->array;
        this->array = new_array;
    }

    if(this->end_ind > size())
        this->end_ind = 0;

    this->array[this->end_ind] = value;
    this->end_ind++;
    this->count++;

}

int Queue::dequeue() {
    if(size() == 0)
        throw runtime_error("Underflow Error");

    if(size() > 1 && this->array_size / 2 == size()) {
        // Create new array with half of current array size
        int *new_array = new int[this->array_size / 2];
        
        // Copy all values to new array
        if(this->start_ind < this->end_ind) {
            copy(this->array + this->start_ind, this->array + this->end_ind, new_array);
        } else {
            copy(this->array + this->start_ind, this->array + this->array_size, new_array);
            copy(this->array, this->array + this->end_ind, new_array + this->array_size - this->start_ind);
        }

        this->start_ind = 0;
        this->end_ind = size();
        this->array_size /= 2;
        delete[] this->array;
        this->array = new_array;
    }

    if(this->start_ind > size())
        this->start_ind = 0;

    int value = this->start_ind;
    this->start_ind++;
    this->count--;
    return value;
}

void Queue::print() {

    if (this->count == 0)
        return;

    if(this->start_ind < this->end_ind) {
        for(int i = this->start_ind; i < this->end_ind; i++) {
            cout << *(this->array + i) << " ";
        }
    } else {
        for(int i = this->start_ind; i < this->array_size; i++)
            cout << *(this->array + i) << " ";
        for(int i = 0; i < this->end_ind; i++)
            cout << *(this->array + i) << " ";
    }
    cout << endl;
}

int Queue::size() {
    return this->count;
}

int main() {

    Queue queue(5);

    for(int i = 0; i < 10; i++) {
        queue.enqueue(i);
        queue.print();
    }

    for(int i = 0; i < 15; i++) {
        queue.dequeue();
        queue.print();
    }

    return -1;
}
