#include<bits/stdc++.h>
class Solution {
public:

    int dp[21][31];

    bool solve(int i, int j, string &s, string &p) {
        // pattern finished
        if(j == p.size()) {
            return i == s.size();
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        bool match = false;
      
        if(i < s.size() &&
           (s[i] == p[j] || p[j] == '.')) {

            match = true;
        }
        bool ans;
        // check for *
        if(j + 1 < p.size() && p[j + 1] == '*') {

            // skip OR take
            ans =solve(i, j + 2, s, p)   || (match && solve(i + 1, j, s, p));
        }

        else {
            ans = match &&solve(i + 1, j + 1, s, p);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};