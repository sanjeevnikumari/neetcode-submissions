class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums) {

        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        // 🔴 HIGHLIGHT: to avoid duplicates at this level
        unordered_set<int> used;

        for (int i = idx; i < nums.size(); i++) {

            // 🔴 HIGHLIGHT: skip duplicate swaps
            if (used.count(nums[i])) continue;
            used.insert(nums[i]);

            swap(nums[i], nums[idx]);

            solve(idx + 1, nums);

            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
};