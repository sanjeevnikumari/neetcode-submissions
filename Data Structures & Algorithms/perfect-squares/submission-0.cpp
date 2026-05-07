class Solution {
public:
    vector<int> memo;

    int solve(int n) {
        if (n == 0) return 0;

        if (memo[n] != -1) return memo[n];

        int ans = INT_MAX;

        for (int j = 1; j * j <= n; j++) {
            int sq = j * j;
            ans = min(ans, 1 + solve(n - sq));
        }

        return memo[n] = ans;
    }

    int numSquares(int n) {
        memo.assign(n + 1, -1);
        return solve(n);
    }
};