#include<bits/stdc++.h>
class Solution {
public:
    int dp[301];

    bool solve(string &s, int i, unordered_set<string> &dict) {

        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        string temp = "";

        for(int j = i; j < s.size(); j++) {

            temp += s[j];

            if(dict.count(temp)) {

                if(solve(s, j + 1, dict))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        memset(dp, -1, sizeof(dp));

        return solve(s, 0, dict);
    }
};