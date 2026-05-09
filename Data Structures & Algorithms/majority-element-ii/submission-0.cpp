class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        // count frequency
        for(int x : nums) {
            mp[x]++;
        }
        
        vector<int> ans;
        int n = nums.size();
        
        // check frequency > n/3
        for(auto &it : mp) {
            
            if(it.second > n/3) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};