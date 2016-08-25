#include "Vertex.h"
#include "constants.h"


Vertex::Vertex(char value) {
    this->value = value;
    this->distance = INT_MAX;
    this->parent = NULL;
}

Vertex::~Vertex() {
}

bool Vertex::operator==(const Vertex& other) const {
    if(this->value == other.value)
        return true;
    return false;
}

