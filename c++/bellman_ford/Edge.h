#ifndef EDGE_H
#define EDGE_H

#include "Vertex.h"

using namespace std;

class Edge {

    public:
        Edge(Vertex* vertex1, Vertex* vertex2, int weight);

        Vertex* vertex1;
        Vertex* vertex2;
        int weight;

        void print();
        friend ostream& operator<< (std::ostream& stream, const Edge& edge);
        bool operator== (const Edge& other) const;

};

#endif
