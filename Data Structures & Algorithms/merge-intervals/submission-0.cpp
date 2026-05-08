class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while(i < n) {
            vector<int> curr = intervals[i];
            // merge all overlapping intervals
            while(i < n && curr[1] >= intervals[i][0]) {
                curr[0] = min(curr[0], intervals[i][0]);
                curr[1] = max(curr[1], intervals[i][1]);
                i++;
            }
            
            ans.push_back(curr);
        }

        return ans;
    }
};