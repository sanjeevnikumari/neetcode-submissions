class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });

        int count = 0;

        int prevEnd = intervals[0][1];

        for(int i = 1; i < n; i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // overlap
            if(start < prevEnd) {
                count++;
            }

            // no overlap
            else {
                prevEnd = end;
            }
        }

        return count;
    }
};