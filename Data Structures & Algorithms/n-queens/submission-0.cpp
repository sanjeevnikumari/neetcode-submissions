class Solution {
public:
    vector<vector<string>> result;

    // Check if placing a queen at board[row][col] is safe
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check same column above
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // Try to place queens row by row
    void solve(int row, vector<string>& board, int n) {
        if (row == n) {             // All queens placed
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';  // Place queen
                solve(row + 1, board, n); // Recurse
                board[row][col] = '.';  // Backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return result;
    }
};