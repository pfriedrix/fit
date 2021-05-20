#include <iostream>
#include <vector>

using namespace std;



struct Graph {
    int vertex;
    int destination;
    int weight;
};

int find_set(int i, int parent[]) {
    if (i == parent[i]) { return i; }
    else {
        return find_set(parent[i], parent);
    }
}

void buildGraph(Graph graph[]) {
    int weights[] = {1, 5, 5, 4, 4, 7, 4, 1, 6, 8, 9, 5};
    int destinations[] = {2, 3, 6, 7, 8, 8, 10, 6, 8, 9, 9, 7};
    int vertexes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (int i = 0; i < 12; i++) {
        graph[i].vertex = vertexes[i];
        graph[i].weight = weights[i];
        graph[i].destination = destinations[i];
    }
}

void union_set(int u, int v, int parent[]) {
    parent[u] = parent[v];
}

void sort(Graph graph[], int right, int left, bool reversed, int length) {
    if (right == left) return;
    if (reversed) {
        for (int i = left - 1; i >= right; i--) {
            if (graph[i].weight > graph[i + 1].weight) {
                swap(graph[i], graph[i + 1]);
            }
        }
        sort(graph, right + 1, left, !reversed, length);
    } else {
        for (int i = right; i < left; i++) {
            if (graph[i].weight > graph[i + 1].weight) {
                swap(graph[i], graph[i + 1]);
            }
        }
        sort(graph, right, left - 1, !reversed, length);
    }
}

int Kruskal(Graph graph[], int length) {
    int parent[length];
    vector<Graph> T;
    for (int i = 0; i < length; i++) {
        parent[i] = i;
    }
    int uRep, vRep;
    int dist = 0;
    sort(graph, 0, length, false, length);
    for (int i = 0; i < length; i++) {
        uRep = find_set(graph[i].destination, parent);
        vRep = find_set(graph[i].vertex, parent);
        if (uRep != vRep) {
            T.push_back(graph[i]);
            cout << "vertex: " << graph[i].vertex << "\ndestination: " << graph[i].destination
                 << "\nweight: " << graph[i].weight << endl;
            dist += graph[i].weight;
            union_set(uRep, vRep, parent);
        }
    }
    cout << "Overall distance: " << dist;
    return dist;
}

int main() {
    Graph graph[12];
    buildGraph(graph);
    Kruskal(graph, 12);
}