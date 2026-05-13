class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();

        // boundary
        if(i < 0 || j < 0 || i >= row || j >= col)
            return;

        // not O
        if(board[i][j] != 'O')
            return;

        // mark safe
        board[i][j] = '#';

        dfs(i-1, j, board); // up
        dfs(i+1, j, board); // down
        dfs(i, j-1, board); // left
        dfs(i, j+1, board); // right
    }

    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        int col = board[0].size();

        // top & bottom rows
        for(int j = 0; j < col; j++) {

            if(board[0][j] == 'O')
                dfs(0, j, board);

            if(board[row-1][j] == 'O')
                dfs(row-1, j, board);
        }

        // left & right columns
        for(int i = 0; i < row; i++) {

            if(board[i][0] == 'O')
                dfs(i, 0, board);

            if(board[i][col-1] == 'O')
                dfs(i, col-1, board);
        }

        // final conversion
        for(int i = 0; i < row; i++) {

            for(int j = 0; j < col; j++) {

                // surrounded
                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                // safe
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};