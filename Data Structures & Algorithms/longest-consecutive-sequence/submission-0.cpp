class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int count = 1;
        
        for(int i = 1; i < n; i++) {
            
            // ignore duplicates
            if(nums[i] == nums[i-1]) {
                continue;
            }
            
            // consecutive
            if(nums[i] == nums[i-1] + 1) {
                count++;
            }
            
            // sequence broken
            else {
                count = 1;
            }
            
            longest = max(longest, count);
        }
        
        return longest;
    }
};