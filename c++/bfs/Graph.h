#include <vector>
#include "Vertex.h"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    public:
        Graph(bool undirected);
        ~Graph();

        void add_vertex(int value);
        void add_edge(int value1, int value2);

        vector<Vertex*> vertices;
        Vertex* search_vertex(int value);
        int search_vertex_index(int value);
        void print();

    private:
        bool undirected;
};

#endif
