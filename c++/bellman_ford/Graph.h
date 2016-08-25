#include <vector>
#include "Edge.h"
#include "Vertex.h"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    public:
        Graph(bool undirected);
        ~Graph();

        void add_vertex(char value);
        void add_edge(char value1, char value2, int weight);
        void add_edge(Edge* edge);

        vector<Vertex*> vertices;
        vector<Edge*> edges;
        int search_vertex_index(char value);
        void print();

    private:
        bool undirected;
};

#endif
