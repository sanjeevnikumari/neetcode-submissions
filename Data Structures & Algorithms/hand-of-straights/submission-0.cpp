class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int,int> mp;

        // count frequency
        for(int x : hand) {
            mp[x]++;
        }

        // process smallest first
        for(auto &it : mp) {
            int start = it.first;
            int count = it.second;

            if(count > 0) {
                // try to form group
                for(int i = 0; i < groupSize; i++) {
                    if(mp[start + i] < count) return false;
                    mp[start + i] -= count;
                }
            }
        }

        return true;
    }
};