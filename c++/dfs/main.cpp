#include <iostream>
#include <queue>

#include "Graph.h"
#include "Vertex.h"
#include "constants.h"

using namespace std;

void initialize_graph(Graph& graph, int node_value) {
    vector<Vertex*> vertices = graph.vertices;
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        vertex->color = WHITE;
        vertex->parent = NULL;
    }

    graph.time = 0;
}

void dfs_visit(Graph& graph, Vertex* vertex) {
    graph.time += 1;
    vertex->timestamp1 = graph.time;
    vertex->color = GRAY;

    vector<Vertex*> adj = vertex->adj;
    for(int i = 0; i < adj.size(); i++) {
        Vertex* adj_vertex = adj[i];
        if(adj_vertex->color == WHITE) {
            adj_vertex->parent = vertex;
            dfs_visit(graph, adj_vertex);
        }
    }

    vertex->color = BLACK;
    graph.time += 1;
    vertex->timestamp2 = graph.time;
    graph.print();
}

void dfs(Graph &graph, int node_value) {
    initialize_graph(graph, node_value);

    vector<Vertex*> vertices = graph.vertices;
    for(int i = 0; i < vertices.size(); i++) {
        Vertex* vertex = vertices[i];
        if(vertex->color == WHITE)
            dfs_visit(graph, vertex);
    }
}

int main() {

    Graph graph(true);
    graph.add_edge(1, 2);
    graph.add_edge(1, 5);
    graph.add_edge(2, 3);
    graph.add_edge(2, 4);
    graph.add_edge(2, 5);
    graph.add_edge(3, 4);
    graph.add_edge(4, 5);

    cout << "Graph before dfs" << endl;
    graph.print();
    cout << "--------------------" << endl << endl;

    dfs(graph, 1);

    cout << "--------------------" << endl;
    cout << "Graph after dfs" << endl;
    graph.print();

}
