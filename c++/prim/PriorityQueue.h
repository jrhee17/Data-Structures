#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <iostream>

#include "Vertex.h"

using namespace std;

class PriorityQueue {
    public:
        PriorityQueue();

        void insert(Vertex* vertex);
        Vertex* pop();
        bool empty();

        void print();
        void heapify(int index);
        void heapify(Vertex* vertex);
        void build_max_heap();
        void update(Vertex* vertex);
    private:
        vector<Vertex*> vec;


};

#endif
