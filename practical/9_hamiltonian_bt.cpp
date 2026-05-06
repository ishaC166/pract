#include <iostream>
#include <vector>
using namespace std;

// Backtracking function
void solve(int v, vector<vector<int>>& graph, vector<bool>& visited,
           vector<int>& path, int count, int n) {

    // If all vertices are visited → print path
    if (count == n) {
        for (int x : path)
            cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            visited[i] = true;
            path.push_back(i);

            solve(i, graph, visited, path, count + 1, n);

            // backtrack
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Hamiltonian Paths:\n";

    bool found = false;

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        vector<int> path;

        visited[i] = true;
        path.push_back(i);

        solve(i, graph, visited, path, 1, n);
    }

    return 0;
}

// 0-------1------2
//   -         -
//    ---------

// Enter number of vertices: 3
// Enter adjacency matrix:
// 0 1 1
// 1 0 1
// 1 1 0
// Hamiltonian Paths:
// 0 1 2 
// 0 2 1 
// 1 0 2 
// 1 2 0 
// 2 0 1 
// 2 1 0 