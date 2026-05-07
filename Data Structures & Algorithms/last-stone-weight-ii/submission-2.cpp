#include<bits/stdc++.h>
class Solution {
public:

    int dp[31][3001];

    int solve(int i,int currSum,vector<int>& stones,int target) {
        if(i == stones.size()) {
            return currSum;
        }
        if(dp[i][currSum] != -1)
            return dp[i][currSum];
        int take = 0;
        // take only if <= target
        if(currSum + stones[i] <= target) {
            take = solve(i + 1,  currSum + stones[i], stones, target);
        }
        int skip = solve(i + 1,currSum, stones, target);
        return dp[i][currSum] = max(take, skip);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int x : stones)
            sum += x;
        int target = sum / 2;
        memset(dp, -1, sizeof(dp));
        int s1 = solve(0, 0, stones, target);
        return sum - 2 * s1;
    }
};