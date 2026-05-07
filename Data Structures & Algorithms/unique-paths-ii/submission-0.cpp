#include<bits/stdc++.h>
class Solution {
public:
    int t[101][101];

    int solve(int i, int j, vector<vector<int>>& grid) {

        // obstacle
        if(i >= 0 && j >= 0 && grid[i][j] == 1)
            return 0;

        // start cell
        if(i == 0 && j == 0)
            return 1;

        // out of boundary
        if(i < 0 || j < 0)
            return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int up = solve(i-1, j, grid);
        int left = solve(i, j-1, grid);

        return t[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        memset(t, -1, sizeof(t));

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return solve(m-1, n-1, obstacleGrid);
    }
};