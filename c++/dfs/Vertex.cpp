#include "Vertex.h"
#include "constants.h"


Vertex::Vertex(int value) {
    this->value = value;
    this->parent = 0;
    this->color = WHITE;
    this->timestamp1 = 0;
    this->timestamp2 = 0;
}

Vertex::~Vertex() {
}

void Vertex::add_adjacent(Vertex* vertex) {
    for(int i = 0; i < adj.size(); i++) {
        if(adj[i]->value == vertex->value)
            return;
    }

    adj.push_back(vertex);
}


