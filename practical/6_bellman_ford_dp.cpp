#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, wt;
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, 1e9); // infinity
    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] != 1e9 && dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    // Check for negative cycle
    bool hasCycle = false;
    for (auto e : edges) {
        if (dist[e.u] != 1e9 && dist[e.u] + e.wt < dist[e.v]) {
            hasCycle = true;
            break;
        }
    }

    if (hasCycle) {
        cout << "Graph contains negative weight cycle\n";
    } else {
        cout << "Shortest distances from source:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}


// 0--------1
// -        
// -
// -
// -
// 3--------2

// Enter number of vertices and edges: 4 6
// Enter edges (u v weight):
// 0 1 3
// 1 2 3
// 2 3 4
// 3 0 2
// 0 2 1
// 1 3 2
// Enter source vertex: 0
// Shortest distances from source:
// Vertex 0 : 0
// Vertex 1 : 3
// Vertex 2 : 1
// Vertex 3 : 5