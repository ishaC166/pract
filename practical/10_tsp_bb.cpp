#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
vector<vector<int>> cost;
vector<bool> visited;
vector<int> bestPath;
int minCost = INT_MAX;

// Simple bound: sum of minimum edge from each unvisited node
int calculateBound() {
    int bound = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int minEdge = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (i != j)
                    minEdge = min(minEdge, cost[i][j]);
            }
            bound += minEdge;
        }
    }
    return bound;
}

// Branch and Bound function
void tsp(vector<int>& path, int currCost, int level) {

    // All cities visited
    if (level == n) {
        int totalCost = currCost + cost[path[level - 1]][path[0]];
        if (totalCost < minCost) {
            minCost = totalCost;
            bestPath = path;
            bestPath.push_back(path[0]); // return to start
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path[level] = i;

            int newCost = currCost + cost[path[level - 1]][i];
            int bound = calculateBound();

            // Branch & Bound condition
            if (newCost + bound < minCost) {
                tsp(path, newCost, level + 1);
            }

            visited[i] = false; // backtrack
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cost.resize(n, vector<int>(n));
    visited.resize(n, false);

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    vector<int> path(n);
    path[0] = 0;
    visited[0] = true;

    tsp(path, 0, 1);

    cout << "Minimum Cost = " << minCost << endl;
    cout << "Path: ";
    for (int v : bestPath)
        cout << v << " ";
    cout << endl;

    return 0;
}

// Enter number of cities: 3
// Enter cost matrix:
// 0 10 15
// 5 0 20
// 8 25 0
// Minimum Cost = 38
// Path: 0 1 2 0 