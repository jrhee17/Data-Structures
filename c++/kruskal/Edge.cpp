#include "Edge.h"
#include <iostream>

Edge::Edge(Vertex* vertex1, Vertex* vertex2, int weight) {
    this->vertex1 = vertex1;
    this->vertex2 = vertex2;
    this->weight = weight;
}

void Edge::print() {
    cout << "(" << vertex1->value << "," << vertex2->value << "," << weight << ")";
}

ostream& operator<<(ostream &os, const Edge& edge) {
    return os << "((" << (char) edge.vertex1->value << "," << edge.vertex1->set << "),(" << (char) edge.vertex2->value << "," << edge.vertex2->set << ")" << edge.weight << ")";
}

bool Edge::operator==(const Edge& other) const {
    if((vertex1 == other.vertex1 && vertex2 == other.vertex2) ||
            (vertex1 == other.vertex2 && vertex2 == other.vertex1))
        return true;
    return false;
}
