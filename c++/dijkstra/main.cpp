#include <iostream>
#include <queue>
#include <set>

#include "Graph.h"
#include "Vertex.h"
#include "constants.h"
#include "PriorityQueue.h"

using namespace std;

void initialize_graph(Graph& graph) {
    for(int i = 0; i < graph.vertices.size(); i++) {
        Vertex* vertex = graph.vertices[i];
        vertex->parent = NULL;
        vertex->distance = INT_MAX;
    }
}


void dijkstra(Graph &graph, char value) {
    initialize_graph(graph);

    int index = graph.search_vertex_index(value);
    Vertex* source = graph.vertices[index];
    source->distance = 0;

    PriorityQueue queue = PriorityQueue();
    for(int i = 0; i < graph.vertices.size(); i++)
        queue.insert(graph.vertices[i]);

    while(!queue.empty()) {
        Vertex* vertex = queue.pop();
        map<Vertex*,int> adj = vertex->adj;
        for(map<Vertex*,int>::iterator it = adj.begin(); it != adj.end(); it++) {
            Vertex* adj_vertex = (*it).first;
            int weight = (*it).second;
            if(adj_vertex->distance > vertex->distance + weight) {
                adj_vertex->distance = vertex->distance + weight;
                adj_vertex->parent = vertex;
                queue.update(adj_vertex);
            }
        }
    }
}

int main() {

    Graph graph(false);
    graph.add_edge('s', 'y', 5);
    graph.add_edge('s', 't', 10);
    graph.add_edge('t', 'x', 1);
    graph.add_edge('t', 'y', 2);
    graph.add_edge('y', 't', 3);
    graph.add_edge('y', 'x', 9);
    graph.add_edge('y', 'z', 2);
    graph.add_edge('x', 'z', 4);
    graph.add_edge('z', 'x', 6);
    graph.add_edge('z', 's', 7);
    
    cout << "----- Before Dijkstra -----" << endl;
    graph.print();

    cout << "----- After Dijkstra -----" << endl;
    dijkstra(graph, 's');
    graph.print();

    cout << "----- Parent <- Child -----" << endl;
    for(vector<Vertex*>::iterator it = graph.vertices.begin(); it != graph.vertices.end(); it++) {
        if((*it)->parent)
            cout << (*it)->parent->value << "<-" << (*it)->value << endl;
    }

}
