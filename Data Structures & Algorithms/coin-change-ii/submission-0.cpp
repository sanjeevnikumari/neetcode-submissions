class Solution {
public:

    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        // valid combination
        if(amount == 0)
            return 1;
        // no coins left
        if(i == coins.size())
            return 0;
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int take = 0;
        // take same coin again
        if(coins[i] <= amount) {

            take = solve(i, coins, amount - coins[i],dp);
        }
        // skip coin
        int skip = solve(i + 1,  coins, amount, dp);
        return dp[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(
            coins.size(),
            vector<int>(amount + 1, -1)
        );
        return solve(0, coins, amount, dp);
    }
};