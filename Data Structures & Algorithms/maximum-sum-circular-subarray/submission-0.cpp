class Solution {
public:
    int minni(vector<int>& nums){
        int mintotal=nums[0];
        int minmm=nums[0];
        for(int i=1;i<nums.size();i++){
            mintotal=min(nums[i],mintotal+nums[i]);
            minmm=min(minmm,mintotal);
        }
        return minmm;
    }

    int maxi(vector<int>& nums){
        int maxtotal=nums[0];
        int manmm=nums[0];
        for(int i=1;i<nums.size();i++){
            maxtotal=max(nums[i],maxtotal+nums[i]);
            manmm=max(manmm,maxtotal);
        }
        return manmm;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int minsum=minni(nums);
        int maxsum=maxi(nums);
        int mincircularsum=sum-minsum;
        if(maxsum>0){
            return max(mincircularsum,maxsum);
        }
        return maxsum;
    }
};