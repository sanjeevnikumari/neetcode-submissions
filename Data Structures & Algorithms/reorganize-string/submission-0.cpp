class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char ch : s) {
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }
        string result = "";


        pair<int,char> prev = {0, '#'};

        while(!pq.empty()) {
            auto [freq, ch] = pq.top();
            pq.pop();
            result += ch;
            freq--;
            
            // push previous character back
            if(prev.first > 0) {
                pq.push(prev);
            }

            prev = {freq, ch};
        }

        if(result.length() != s.length()) {
            return "";
        }

        return result;
    }
};