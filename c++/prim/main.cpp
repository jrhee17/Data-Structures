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
        graph.vertices[i]->parent = NULL;
        graph.vertices[i]->distance = INT_MAX;
    }
}


void prim(Graph &graph, char value) {
    initialize_graph(graph);

    vector<Vertex*> vertices = graph.vertices;

    int start_index = graph.search_vertex_index(value);
    Vertex* startNode = vertices[start_index];
    startNode->distance = 0;

    PriorityQueue queue;
    for(vector<Vertex*>::iterator it = vertices.begin(); it != vertices.end(); it++)
        queue.insert(*it);
    queue.build_max_heap();


    set<Vertex*> complete_set;

    while(!queue.empty()) {
        Vertex* vertex = queue.pop();
        complete_set.insert(vertex);


        map<Vertex*, int> adj = vertex->adj;
        for(map<Vertex*, int>::iterator it = adj.begin(); it != adj.end(); it++) {
            Vertex* adj_vertex = (*it).first;
            int weight = (*it).second;

            if(complete_set.find(adj_vertex) == complete_set.end() && weight < adj_vertex->distance) {
                adj_vertex->distance = weight;
                adj_vertex->parent = vertex;
                queue.update(adj_vertex);
            }
        }

    }
}

int main() {

    Graph graph(true);
    graph.add_edge('a', 'b', 4);
    graph.add_edge('a', 'h', 8);
    graph.add_edge('b', 'c', 8);
    graph.add_edge('b', 'h', 11);
    graph.add_edge('c', 'd', 7);
    graph.add_edge('c', 'f', 4);
    graph.add_edge('c', 'i', 2);
    graph.add_edge('d', 'e', 9);
    graph.add_edge('d', 'f', 14);
    graph.add_edge('e', 'f', 10);
    graph.add_edge('f', 'g', 2);
    graph.add_edge('g', 'h', 1);
    graph.add_edge('g', 'i', 6);
    graph.add_edge('h', 'i', 7);
    graph.add_edge('h', 'i', 7);
    initialize_graph(graph);

    cout << "----- Before Prim -----" << endl;
    graph.print();

    prim(graph, 'a');
    cout << "----- After Prim -----" << endl;
    graph.print();

    cout << "----- Parent<-Sibling -----" << endl;
    int mst_distance = 0;
    for(vector<Vertex*>::iterator it = graph.vertices.begin(); it != graph.vertices.end(); it++) {
        mst_distance += (*it)->distance;
        if((*it)->parent)
            cout << (*it)->parent->value << "<-" << (*it)->value << endl;
    }
    cout << endl;

    cout << "----- MST Distance -----" << endl;
    cout << mst_distance << endl;


}
