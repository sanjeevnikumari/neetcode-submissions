class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        map<int, int> events;
        // build event timeline
        for(auto &it : intervals) {
            events[it.start]++;   // meeting starts
            events[it.end]--;     // meeting ends
        }
        int rooms = 0;
        int ans = 0;
        // sweep through time
        for(auto &p : events) {
            rooms += p.second;
            ans = max(ans, rooms);
        }
        return ans;
    }
};