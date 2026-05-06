#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity: ";
    cin >> W;

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w)
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value = " << dp[n][W] << endl;

    // 🔥 Backtracking to find selected items
    int w = W;
    vector<int> selected;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(i - 1); // item index
            w -= weight[i - 1];
        }
    }

    cout << "Items included (0-based index): ";
    for (int i = selected.size() - 1; i >= 0; i--)
        cout << selected[i] << " ";

    cout << endl;

    return 0;
}

// Enter number of items: 3
// Enter weights:
// 3 2 5 
// Enter values:
// 7 2 1
// Enter capacity: 7
// Maximum value = 9
// Items included (0-based index): 0 1 