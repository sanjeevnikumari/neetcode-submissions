class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string ans = "";
        int n = min(first.size(), last.size());
        for(int i = 0; i < n; i++) {
            
            if(first[i] != last[i]) {
                break;
            }
            ans.push_back(first[i]);
        }
        
        return ans;
    }
};