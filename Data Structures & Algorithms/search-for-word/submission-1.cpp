  class Solution {
public:
    int m, n;

    bool solve(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // base case: whole word matched
        if (k == word.size()) return true;

        // boundary & mismatch check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k])
            return false;

        char ch = board[i][j];
        board[i][j] = '*'; // mark visited

        bool found =
            solve(board, word, i+1, j, k+1) ||
            solve(board, word, i-1, j, k+1) ||
            solve(board, word, i, j+1, k+1) ||
            solve(board, word, i, j-1, k+1);

        board[i][j] = ch; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

   
