#include<bits/stdc++.h>
class Solution {
public:

    long long dp[1001][1001];

    long long solve(int i,
                    int j,
                    string &s,
                    string &t) {

        // matched entire t
        if(j == t.size())
            return 1;

        // s finished
        if(i == s.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        // characters match
        if(s[i] == t[j]) {

            // take + skip
            ans =
                solve(i + 1, j + 1, s, t)
                +
                solve(i + 1, j, s, t);
        }

        else {

            // skip current char
            ans =
                solve(i + 1, j, s, t);
        }

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t);
    }
};