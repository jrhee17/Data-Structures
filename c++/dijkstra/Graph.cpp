#include "Graph.h"
#include "Vertex.h"
#include <iostream>

Graph::Graph(bool undirected) {
    this->undirected = undirected;
}

Graph::~Graph() {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        delete vertex;
    }
}

int Graph::search_vertex_index(char value) {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        int val = vertex->value;
        if(vertex->value == value)
            return i;
    }
    return -1;
}

void Graph::add_vertex(char value) {
    if(search_vertex_index(value) == -1) {
        vertices.push_back(new Vertex(value));
    } 
}

void Graph::add_edge(char value1, char value2, int weight) {

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

    vertex1->adj[vertex2] = weight;


    if(undirected) {
        vertex2->adj[vertex1] = weight;
    }
}

void Graph::print() {
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        cout << "(" << vertex->value << "):";
        for(map<Vertex*, int>::iterator it = vertex->adj.begin(); it != vertex->adj.end(); it++) {
            Vertex* adj_vertex = (*it).first;
            int weight = (*it).second;
            cout << "(" << adj_vertex->value << "," << adj_vertex->distance << "," << weight << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

