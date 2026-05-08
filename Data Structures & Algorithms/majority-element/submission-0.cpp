class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int ,int>mp;
       for(int x:nums){
        mp[x]++;
       }
       int maxi=INT_MIN;
       int ans=-1;
       for(auto &it:mp){
        if(it.second>maxi){
            maxi=it.second;
            ans=it.first;
        }
       }
       return ans;
    }
};