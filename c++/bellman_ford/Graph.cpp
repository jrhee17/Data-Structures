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
        char val = vertex->value;
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

void Graph::add_edge(Edge* edge){
    for(int i = 0; i < edges.size(); i++) {
        if(*edge == *edges[i])
            return;
    }
    edges.push_back(edge);
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

    Edge* edge1 = new Edge(vertex1, vertex2, weight);
    add_edge(edge1);


    if(undirected) {
        Edge* edge2 = new Edge(vertex2, vertex1, weight);
        add_edge(edge2);
    }
}

void Graph::print() {
    for(int i = 0; i < edges.size(); i++) {
        Edge* edge = edges[i];
        cout << *edge << " " << endl;
    }
    cout << endl;

    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        cout << *vertex << " " << endl;
    }
    cout << endl;
}

