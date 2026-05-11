class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, int target, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (idx == nums.size() || target < 0) return;

        // TAKE (we can reuse same element)
        if (nums[idx] <= target) {
            temp.push_back(nums[idx]);
            solve(idx, nums, target - nums[idx], temp);
            temp.pop_back();
        }

        // SKIP
        solve(idx + 1, nums, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};