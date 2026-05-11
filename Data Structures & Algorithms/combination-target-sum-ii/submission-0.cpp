class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, int target, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) break;
            temp.push_back(nums[i]);
            solve(i + 1, nums, target - nums[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};