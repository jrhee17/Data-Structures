#include <vector>
#include <map>

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class Vertex {
    public:

        Vertex(char value);
        ~Vertex();

        char value;

        bool operator==(const Vertex& other) const;

        Vertex* parent;
        int distance;
        map<Vertex*, int> adj;
    private:
        
};

#endif
