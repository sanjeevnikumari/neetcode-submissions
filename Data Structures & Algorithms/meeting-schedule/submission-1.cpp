class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](Interval &a, Interval &b) {
                return a.start < b.start;
            });

        for(int i = 1; i < intervals.size(); i++) {

            int prevEnd = intervals[i-1].end;
            int currStart = intervals[i].start;

            // overlap
            if(currStart < prevEnd) {
                return false;
            }
        }

        return true;
    }
};