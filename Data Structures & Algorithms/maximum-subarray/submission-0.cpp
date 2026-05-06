class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++){
            total=max(nums[i],total+nums[i]);
            maxsum=max(maxsum,total);
        }
        return maxsum;
    }
};
