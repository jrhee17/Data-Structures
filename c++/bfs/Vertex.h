#include <vector>

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class Vertex {
    public:

        Vertex(int value);
        ~Vertex();

        void add_adjacent(Vertex* vertex);

        int value;
        Vertex* parent;
        int color;
        int distance;
        vector<Vertex*> adj;
};

#endif
