class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        // out of boundary
        if(i < 0 || j < 0 || i >= row || j >= col)
            return;

        // water or already visited
        if(grid[i][j] == '0')
            return;

        // mark visited
        grid[i][j] = '0';

        // 4 directions
        dfs(i-1, j, grid); // up
        dfs(i+1, j, grid); // down
        dfs(i, j-1, grid); // left
        dfs(i, j+1, grid); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        int islands = 0;

        for(int i = 0; i < row; i++) {

            for(int j = 0; j < col; j++) {

                // new island mila
                if(grid[i][j] == '1') {

                    islands++;

                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};