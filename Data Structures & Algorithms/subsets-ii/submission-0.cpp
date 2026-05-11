class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int>& nums, vector<int>& temp) {

        // every state is a valid subset
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {

            // 🔴 HIGHLIGHT: skip duplicates at same level
            if (i > start && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);

            solve(i + 1, nums, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // 🔴 HIGHLIGHT: sort is MUST for duplicate handling
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(0, nums, temp);

        return ans;
    }
};