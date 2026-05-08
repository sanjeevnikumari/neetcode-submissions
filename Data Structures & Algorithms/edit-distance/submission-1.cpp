
#include<bits/stdc++.h>
class Solution {
public:

    int dp[501][501];

    int solve(int i, int j, string &word1, string &word2) {
        // word1 finished
        if(i == word1.size())
            return word2.size() - j;

        // word2 finished
        if(j == word2.size())
            return word1.size() - i;

        if(dp[i][j] != -1)
            return dp[i][j];

        // characters match
        if(word1[i] == word2[j]) {
            return dp[i][j] =  solve(i + 1, j + 1, word1,  word2);
        }

        // insert
        int insertOp = 1 + solve(i, j + 1,  word1,word2);

        // delete
        int deleteOp =
            1 + solve(i + 1,  j,   word1,  word2);

        // replace
        int replaceOp = 1 + solve(i + 1, j + 1,  word1,  word2);
        return dp[i][j] =  min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1,string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};