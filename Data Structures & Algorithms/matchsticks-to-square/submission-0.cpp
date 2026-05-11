class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& sides, int idx, int target) {
        if (idx == nums.size()) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }
        for (int i = 0; i < 4; i++) {
            if (sides[i] + nums[idx] > target) continue;
            sides[i] += nums[idx];
            if (solve(nums, sides, idx + 1, target))
                return true;
            sides[i] -= nums[idx];
            if (sides[i] == 0) break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int x : matchsticks) sum += x;
        if (sum % 4 != 0) return false;
        int target = sum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); 
        vector<int> sides(4, 0);
        return solve(matchsticks, sides, 0, target);
    }
};