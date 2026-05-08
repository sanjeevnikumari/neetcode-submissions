#include<bits/stdc++.h>
class Solution {
public:
    int dp[301][301];
    int solve(int i, int j,vector<int>& nums) {
        // no balloons left
        if(i > j)
            return 0;

        // already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        for(int k = i; k <= j; k++) {
            int coins =
                nums[i - 1] *
                nums[k] *
                nums[j + 1];
            // solve left part
            int left = solve(i, k - 1, nums);
            int right = solve(k + 1, j, nums);
            int total =left + coins + right;
            ans = max(ans, total);
        }

        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        // add virtual balloons
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp, -1, sizeof(dp));

        // solve for original balloons
        return solve(1, n, nums);
    }
};