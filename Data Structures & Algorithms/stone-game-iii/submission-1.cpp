#include <bits/stdc++.h>
class Solution {
public:
    int dp[50001];
    int n;

    int solve(int i, vector<int>& a) {

        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int sum = 0;
        int ans = INT_MIN;

        for(int k = 0; k < 3 && i + k < n; k++) {
            sum += a[i + k];
            ans = max(ans, sum - solve(i + k + 1, a));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& a) {

        n = a.size();
        memset(dp, -1, sizeof(dp));

        int res = solve(0, a);

        if(res > 0) return "Alice";
        if(res < 0) return "Bob";
        return "Tie";
    }
};