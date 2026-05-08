class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        // count frequency
        for(int x : nums) {
            mp[x]++;
        }
        
        // max heap {frequency, number}
        priority_queue<pair<int,int>> pq;
        
        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }
        
        vector<int> ans;
        
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};