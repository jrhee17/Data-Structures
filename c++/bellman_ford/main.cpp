#include <iostream>
#include <queue>
#include <set>

#include "Graph.h"
#include "Vertex.h"
#include "constants.h"

using namespace std;


void initialize_graph(Graph& graph, char source_value) {
    vector<Vertex*> vertices = graph.vertices;
    for(int i = 0; i < vertices.size(); i++) {
        vertices[i]->distance = INT_MAX;
        vertices[i]->parent = NULL;
    }

    int index = graph.search_vertex_index(source_value);
    Vertex* source = vertices[index];
    source->distance = 0;
}

bool bellman_ford(Graph &graph, char source_value) {
    initialize_graph(graph, source_value);
    
    for(int i = 0; i < graph.vertices.size(); i++) {
        for(int j = 0; j < graph.edges.size(); j++) {
            Edge* edge = graph.edges[j];
            int total = graph.edges.size();

            Vertex* v1 = edge->vertex1;
            Vertex* v2 = edge->vertex2;

            if(v2->distance > v1->distance + edge->weight) {
                v2->parent = v1;
                v2->distance = v1->distance + edge->weight;
            }
        }
    }

    for(int i = 0; i < graph.edges.size(); i++) {
        Edge* edge = graph.edges[i];
        if(edge->vertex2->distance > edge->vertex1->distance + edge->weight)
            return false;
    }
    return true;
}

int main() {

    Graph graph(false);
    graph.add_edge('s', 't', 6);
    graph.add_edge('s', 'y', 7);
    graph.add_edge('t', 'y', 8);
    graph.add_edge('t', 'x', 5);
    graph.add_edge('t', 'z', -4);
    graph.add_edge('y', 'x', -3);
    graph.add_edge('y', 'z', 9);
    graph.add_edge('x', 't', -2);
    graph.add_edge('z', 'x', 7);
    graph.add_edge('z', 's', 2);


    cout << "--------------------" << endl << endl;
    cout << "Graph before Bellman Ford" << endl;
    cout << "--------------------" << endl << endl;
    graph.print();

    bool no_cycles = bellman_ford(graph, 's');
    graph.print();

    for(vector<Vertex*>::iterator it = graph.vertices.begin(); it != graph.vertices.end(); it++) {
        if((*it)->parent)
            cout << (*it)->parent->value << "<-" << (*it)->value << endl;
    }

    cout << "Has Cycles: " << !no_cycles << endl;
}
