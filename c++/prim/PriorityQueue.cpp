#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    vec.push_back(NULL);
}

void PriorityQueue::insert(Vertex* vertex) {
    vec.push_back(vertex);
    int index = vec.size()-1;
    while((index>>1) >= 1 && vec[index >> 1]->distance > vec[index]->distance) {
        Vertex* temp = vec[index];
        vec[index] = vec[index >> 1];
        vec[index >> 1] = temp;

        index = index >> 1;
    }
}

Vertex* PriorityQueue::pop() {
    if(vec.size() < 2)
        return NULL;

    Vertex* max = vec[1];

    vec[1] = vec[vec.size() - 1];
    vec.pop_back();
    heapify(1);

    return max;
}

void PriorityQueue::update(Vertex* vertex) {
    int index = find(vec.begin(), vec.end(), vertex) - vec.begin();

    while((index>>1) >= 1 && vec[index >> 1]->distance > vec[index]->distance) {
        Vertex* temp = vec[index];
        vec[index] = vec[index >> 1];
        vec[index >> 1] = temp;

        index = index >> 1;
    }
}

void PriorityQueue::heapify(int index) {

    int left = index << 1;
    int right = (index << 1) + 1;

    int smallest;
    if(left < vec.size() && vec[left]->distance < vec[index]->distance)
        smallest = left;
    else
        smallest = index;

    if(right < vec.size() && vec[right]->distance < vec[smallest]->distance)
        smallest = right;

    if(smallest != index) {
        Vertex* temp = vec[smallest];
        vec[smallest] = vec[index];
        vec[index] = temp;
        heapify(smallest);
    }
}

void PriorityQueue::heapify(Vertex* vertex) {
    int index = find(vec.begin(), vec.end(), vertex) - vec.begin();
    heapify(index);
}

bool PriorityQueue::empty() {
    if(vec.size() <= 1)
        return true;
    return false;
}

void PriorityQueue::build_max_heap() {
    for(int i = vec.size() - 1; i >= 1; i--)
        heapify(i);
}

void PriorityQueue::print() {
    for(int i = 1; i < vec.size(); i++)
        cout << vec[i]->value << "," << vec[i]->distance << " ";
    cout << endl;
}
