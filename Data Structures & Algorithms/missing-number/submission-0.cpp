class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;

        // XOR all array elements
        for (int num : nums) {
            x ^= num;
        }

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            x ^= i;
        }

        return x;
    }
};