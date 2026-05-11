class Solution {
public:
    int solve(int i, vector<int>& nums, int xr) {
        if (i == nums.size()) {
            return xr;  // one subset completed
        }

        // include nums[i]
        int take = solve(i + 1, nums, xr ^ nums[i]);

        // exclude nums[i]
        int skip = solve(i + 1, nums, xr);

        return take + skip;
    }

    int subsetXORSum(vector<int>& nums) {
        return solve(0, nums, 0);
    }
};