class Solution {
public:

    bool solve(vector<int>& nums, vector<int>& bucket, int idx, int target) {

        if (idx == nums.size()) {
            for (int i = 0; i < bucket.size(); i++) {
                if (bucket[i] != target) return false;
            }
            return true;
        }

        for (int i = 0; i < bucket.size(); i++) {

            if (bucket[i] + nums[idx] > target) continue;

            bucket[i] += nums[idx];

            if (solve(nums, bucket, idx + 1, target))
                return true;

            bucket[i] -= nums[idx];

            if (bucket[i] == 0) break; // optimization
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % k != 0) return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend()); // optimization

        vector<int> bucket(k, 0);

        return solve(nums, bucket, 0, target);
    }
};