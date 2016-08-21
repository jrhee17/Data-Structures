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
        vertex->distance = INT_MAX;
        vertex->parent = NULL;
    }

}

void bfs(Graph &graph, int node_value) {
    initialize_graph(graph, node_value);

    int index = graph.search_vertex_index(node_value);
    Vertex* root = graph.vertices[index];
    root->distance = 0;
    root->color = GRAY;
    root->parent = NULL;

    queue<Vertex*> q;
    q.push(root);
    while(!q.empty()) {
        int ind = graph.search_vertex_index(q.front()->value);
        q.pop();
        Vertex* u = graph.vertices[ind];
        vector<Vertex*> adj = u->adj;
        for(int i = 0; i < adj.size(); i++) {
            Vertex* v = adj[i];
            if(v->color == WHITE) {
                v->color = GRAY;
                v->distance = u->distance + 1;
                v->parent = u;
                q.push(v);
                graph.print();
            }
        }
        u->color = BLACK;
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

    cout << "Graph before bfs" << endl;
    graph.print();
    cout << "--------------------" << endl << endl;

    bfs(graph, 1);

    cout << "--------------------" << endl;
    cout << "Graph after bfs" << endl;
    graph.print();

}
