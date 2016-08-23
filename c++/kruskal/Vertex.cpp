#include "Vertex.h"
#include "constants.h"


Vertex::Vertex(char value) {
    this->value = value;
}

Vertex::~Vertex() {
}

bool Vertex::operator==(const Vertex& other) const {
    if(this->value == other.value)
        return true;
    return false;
}

