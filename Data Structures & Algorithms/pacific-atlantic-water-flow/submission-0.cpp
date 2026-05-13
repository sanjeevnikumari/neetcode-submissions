class Solution {
public:

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis,
             int prevHeight) {

        int row = heights.size();
        int col = heights[0].size();

        // boundary check
        if(r < 0 || c < 0 || r >= row || c >= col)
            return;

        // already visited
        if(vis[r][c])
            return;

        // reverse flow check
        if(heights[r][c] < prevHeight)
            return;

        vis[r][c] = 1;

        dfs(r-1, c, heights, vis, heights[r][c]); // up
        dfs(r+1, c, heights, vis, heights[r][c]); // down
        dfs(r, c-1, heights, vis, heights[r][c]); // left
        dfs(r, c+1, heights, vis, heights[r][c]); // right
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> pacific(row, vector<int>(col, 0));
        vector<vector<int>> atlantic(row, vector<int>(col, 0));

        // Pacific DFS
        // top row
        for(int j = 0; j < col; j++) {
            dfs(0, j, heights, pacific, heights[0][j]);
        }

        // left column
        for(int i = 0; i < row; i++) {
            dfs(i, 0, heights, pacific, heights[i][0]);
        }

        // Atlantic DFS
        // bottom row
        for(int j = 0; j < col; j++) {
            dfs(row-1, j, heights, atlantic, heights[row-1][j]);
        }

        // right column
        for(int i = 0; i < row; i++) {
            dfs(i, col-1, heights, atlantic, heights[i][col-1]);
        }

        vector<vector<int>> ans;

        // common cells
        for(int i = 0; i < row; i++) {

            for(int j = 0; j < col; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};