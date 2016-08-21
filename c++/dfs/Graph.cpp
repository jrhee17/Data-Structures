#include "Graph.h"
#include "Vertex.h"
#include <iostream>

Graph::Graph(bool undirected) {
    this->undirected = undirected;
    this->time = 0;
}

Graph::~Graph() {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        delete vertex;
    }
}

Vertex* Graph::search_vertex(int value) {
    Vertex *iter_vertex = NULL;
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->value == value)
            iter_vertex = vertices[i];
    }
    return iter_vertex;
}

int Graph::search_vertex_index(int value) {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        int val = vertex->value;
        if(vertex->value == value)
            return i;
    }
    return -1;
}

void Graph::add_vertex(int value) {
    if(search_vertex_index(value) == -1) {
        vertices.push_back(new Vertex(value));
    } 
}

void Graph::add_edge(int value1, int value2) {

    int index1 = search_vertex_index(value1);
    int index2 = search_vertex_index(value2);

    if(index1 == -1) {
        add_vertex(value1);
        index1 = vertices.size() - 1;
    }

    if(index2 == -1) {
        add_vertex(value2);
        index2 = vertices.size() - 1;
    }

    Vertex* vertex1 = vertices[index1];
    Vertex* vertex2 = vertices[index2];

    vertex1->add_adjacent(vertex2);

    if(undirected) {
        vertex2->add_adjacent(vertex1);
    }
}

void Graph::print() {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        cout << vertex->value << ": ";

        vector<Vertex*> adj = vertex->adj;
        for(int j = 0; j < adj.size(); j++) {
            Vertex* adj_vertex = adj[j];
            cout << adj_vertex->value << "(" << adj_vertex->color << "," << adj_vertex->timestamp1 << "," << adj_vertex->timestamp2 << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

