#include<bits/stdc++.h>
class Solution {
public:

    int dp[21][2001];

    int solve(int i, int sum,  vector<int>& nums, int target) {
        // all elements used
        if(i == nums.size()) {
            return sum == target;
        }

        if(dp[i][sum + 1000] != -1)
            return dp[i][sum + 1000];

        // add current number
        int plus = solve(i + 1,  sum + nums[i],nums,target);

        // subtract current number
        int minus =solve(i + 1,sum - nums[i],nums, target);

        return dp[i][sum + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums, target);
    }
};