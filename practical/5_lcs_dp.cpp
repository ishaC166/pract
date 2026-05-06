#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.length();
    int m = s2.length();

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "Length of LCS = " << dp[n][m] << endl;

    // Backtracking to find LCS string
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];  // add character
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    // reverse because we built it backwards
    reverse(lcs.begin(), lcs.end());

    cout << "LCS = " << lcs << endl;

    return 0;
}