#include <iostream>
#include <vector>

using namespace std;



struct Graph {
    int vertex;
    int destination;
    int weight;
};


void buildGraph(Graph graph[]) {
    int weights[] = {1, 6, 3, 2, 4, 2, 7, 1, 6, 8, 9, 5};
    int destinations[] = {2, 3, 4, 5, 5, 4, 5, 6, 8, 9, 9, 7};
    int vertexes[] = {1, 2, 1, 4, 2, 2, 3, 5, 4, 5, 6, 3};
    for (int i = 1; i <= 12; i++) {
        graph[i].vertex = vertexes[i - 1];
        graph[i].weight = weights[i - 1];
        graph[i].destination = destinations[i - 1];
    }
    graph[0].vertex = 0;
    graph[0].destination = 0;
    graph[0].weight = -1;
}

int minVertex(vector<Graph> graph, int length, Graph graphFull[]) {
    int min = graph[0].weight, minI = 0;
    cout << "choose next: ";
    for (int i = 0; i < length; i++) {
        if (graph[i].weight < min) {
            minI = i;
            min = graph[i].weight;
        }
        cout << "(" << graph[i].vertex << ", " << graph[i].destination << ", " << graph[i].weight << ") ";
    }
    cout << endl;
    Graph curr = graph[minI];
    for (int i = 1; i <= 12; i++) {
        if (graphFull[i].vertex == curr.vertex && graphFull[i].destination == curr.destination) {
            minI = i;
            break;
        }
    }
    return minI;
}


void Prima(Graph graph[], int length) {
    bool used[length];
    memset(used, 0, length);
    vector<Graph> T;
    int counter = 0;
    used[1] = true;
    int dist = 0;
    while (counter < length) {
        vector<Graph> filtered;
        for (int i = 1; i <= length; i++) {
            if ((!used[graph[i].vertex] || !used[graph[i].destination]) &&
                (used[graph[i].vertex] || used[graph[i].destination])) {
                filtered.push_back(graph[i]);
            }
        }
        if (filtered.empty()) break;
        int minGraphI = minVertex(filtered, filtered.size(), graph);
        T.push_back(graph[minGraphI]);
        used[graph[minGraphI].vertex] = true;
        used[graph[minGraphI].destination] = true;
        counter++;
        cout << "vertex: " << graph[minGraphI].vertex << "\ndestination: " << graph[minGraphI].destination
             << "\nweight: " << graph[minGraphI].weight << endl;
        dist += graph[minGraphI].weight;
    }
    cout << "Overall distance: " << dist << endl;
}


int main() {
    Graph graph[13];
    buildGraph(graph);
    Prima(graph, 12);

}