
        class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        // out of boundary
        if(i < 0 || j < 0 || i >= row || j >= col)
            return 0;

        // water or visited
        if(grid[i][j] == 0)
            return 0;

        // mark visited
        grid[i][j] = 0;

        int up    = dfs(i-1, j, grid);
        int down  = dfs(i+1, j, grid);
        int left  = dfs(i, j-1, grid);
        int right = dfs(i, j+1, grid);

        return 1 + up + down + left + right;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();

        int maxi = 0;

        for(int i = 0; i < row; i++) {

            for(int j = 0; j < col; j++) {

                if(grid[i][j] == 1) {

                    int area = dfs(i, j, grid);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};
    
