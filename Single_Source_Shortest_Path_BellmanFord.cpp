#include <iostream>
#include <climits>

#define MAX 20

using namespace std;

bool Bellman_Ford(int G[MAX][MAX], int V, int E, int edge[MAX][2]) {
    int distance[MAX], parent[MAX];
    int S, u, v;
    bool flag = true;

    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    cout << "Enter source: ";
    cin >> S;
    distance[S - 1] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int k = 0; k < E; k++) {
            u = edge[k][0];
            v = edge[k][1];
            if (distance[u] != INT_MAX && distance[u] + G[u][v] < distance[v]) {
                distance[v] = distance[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    for (int k = 0; k < E; k++) {
        u = edge[k][0];
        v = edge[k][1];
        if (distance[u] != INT_MAX && distance[u] + G[u][v] < distance[v]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i + 1 << " -> cost = " << distance[i] << " parent = " << parent[i] + 1 << endl;
        }
    }

    return flag;
}

int main() {
    int V, E = 0;
    int G[MAX][MAX], edge[MAX][2];

    cout << "BELLMAN FORD\n";
    cout << "Enter no. of vertices: ";
    cin >> V;

    cout << "Enter graph in matrix form:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];
            if (G[i][j] != 0) {
                edge[E][0] = i;
                edge[E][1] = j;
                E++;
            }
        }
    }

    if (Bellman_Ford(G, V, E, edge)) {
        cout << "\nNo negative weight cycle\n";
    } else {
        cout << "\nNegative weight cycle exists\n";
    }

    return 0;
}

