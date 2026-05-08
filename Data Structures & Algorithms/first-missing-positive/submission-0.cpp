class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int> st;
        
        // store positive numbers
        for(int x : nums) {
            if(x > 0) {
                st.insert(x);
            }
        }
        
        // find first missing positive
        int ans = 1;
        
        while(true) {
            
            if(st.find(ans) == st.end()) {
                return ans;
            }
            
            ans++;
        }
    }
};