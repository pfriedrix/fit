#include <iostream>

using namespace std;
#define v 6

#define INF 99999999

void print(int dist[][v]) {
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

void floyd(int graph[][v]) {
    int dist[v][v];
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    print(dist);
}

int main() {
    int graph[v][v] = {
            {
                    0,   3,   9, INF, INF, INF
            },
            {
                    INF, 0,   6, INF, INF, 5
            },
            {
                    INF, INF, 0, 5,   INF, 2
            },
            {
                    1,   1, INF, 0,   7,   INF
            },
            {
                    INF, INF, 4, INF, 0,   6
            },
            {
                    INF, 4, INF, INF, INF, 0
            }
    };
    floyd(graph);
}