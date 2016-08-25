#include <vector>
#include <set>
#include <ostream>

#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class Vertex {
    public:

        Vertex(char value);
        ~Vertex();

        char value;
        Vertex* parent;
        int distance;

        bool operator==(const Vertex& other) const;
        friend ostream& operator<<(ostream& os, const Vertex& vertex);

    private:
        
};

#endif
