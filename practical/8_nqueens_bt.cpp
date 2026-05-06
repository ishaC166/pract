#include <iostream>
#include <vector>
using namespace std;

// Check if it's safe to place queen
bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

// Backtracking function
bool solve(vector<string>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';  // place queen

            if (solve(board, row + 1, n))
                return true;

            board[row][col] = '.';  // backtrack
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));

    if (solve(board, 0, n)) {
        cout << "Solution:\n";
        for (auto row : board)
            cout << row << endl;
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}