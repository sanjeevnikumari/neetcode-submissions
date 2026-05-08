#include<bits/stdc++.h>
class Solution {
public:

    int m, n;

    int dp[201][201];

    vector<pair<int,int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    int solve(int i,
              int j,
              vector<vector<int>>& matrix) {

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 1;

        for(auto &d : dir) {

            int ni = i + d.first;
            int nj = j + d.second;

            if(ni >= 0 && nj >= 0 &&
               ni < m && nj < n &&
               matrix[ni][nj] > matrix[i][j]) {

                ans = max(ans,
                          1 + solve(ni, nj, matrix));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        memset(dp, -1, sizeof(dp));

        int res = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                res = max(res,
                          solve(i, j, matrix));
            }
        }

        return res;
    }
};