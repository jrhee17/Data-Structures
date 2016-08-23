#include <vector>
#include <set>

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class Vertex {
    public:

        Vertex(char value);
        ~Vertex();

        char value;

        bool operator==(const Vertex& other) const;

        set<Vertex*>* set;
    private:
        
};

#endif
