#include <iostream>
#include <queue>
#include <set>

#include "Graph.h"
#include "Vertex.h"
#include "constants.h"

using namespace std;

void combine_merge(vector<Edge*> &vec, int p, int m, int q) {

    vector<Edge*> left;
    for(int i = p; i < m; i++)
        left.insert(left.begin(), vec[i]);

    vector<Edge*> right;
    for(int i = m; i < q; i++)
        right.insert(right.begin(), vec[i]);

    for(int i = p; i < q; i++) {
        Edge* edge;
        if(left.empty()) {
            vec[i] = right.back();
            right.pop_back();
        } else if (right.empty()) {
            vec[i] = left.back();
            left.pop_back();
        } else {
            if(left.back()->weight < right.back()->weight) {
                vec[i] = left.back();
                left.pop_back();
            } else {
                vec[i] = right.back();
                right.pop_back();
            }
        }
    }

}

void merge_sort(vector<Edge*> &vec, int p, int q) {
    if(q - p > 1) {
        int m = (p + q) / 2; 
        merge_sort(vec, p, m);
        merge_sort(vec, m, q);
        combine_merge(vec, p, m, q);
    }
}

void initialize_graph(Graph& graph) {
    graph.make_set();
    merge_sort(graph.edges, 0, graph.edges.size());
}

vector<Edge*> kruskal(Graph &graph) {

    vector<Edge*> edges = graph.edges;
    vector<Edge*> result;

    int ind = graph.vertices.size();
    set<int> sets;

    for(int i = 0; i < edges.size(); i++) {
        set<Vertex*>* set1 = edges[i]->vertex1->set;
        set<Vertex*>* set2 = edges[i]->vertex2->set;

        if(set1 != set2) {
            result.push_back(edges[i]);

            set<Vertex*>* new_set = new set<Vertex*>();

            edges[i]->vertex1->set = new_set;
            new_set->insert(edges[i]->vertex1);
            edges[i]->vertex2->set = new_set;
            new_set->insert(edges[i]->vertex2);

            for(set<Vertex*>::iterator it = set2->begin(); it != set2->end(); it++) {
                (*it)->set = new_set;
                new_set->insert(*it);
            }
            for(set<Vertex*>::iterator it = set1->begin(); it != set1->end(); it++) {
                (*it)->set = new_set;
                new_set->insert(*it);
            }

            delete set1;
            delete set2;
        }
    }

    return result;
}

int main() {

    Graph graph(false);
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

    cout << "--------------------" << endl << endl;
    cout << "Graph before kruskal" << endl;
    cout << "--------------------" << endl << endl;
    graph.print();

    cout << "--------------------" << endl << endl;
    cout << "Kruskal MST" << endl;
    cout << "--------------------" << endl << endl;
    vector<Edge*> edges = kruskal(graph);
    for(vector<Edge*>::iterator it = edges.begin(); it < edges.end(); it++ )
        cout << **it << endl;

}
