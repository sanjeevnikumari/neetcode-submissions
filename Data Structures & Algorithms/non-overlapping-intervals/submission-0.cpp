#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int count = 0; 
        int lastEnd = INT_MIN;

        for (auto &iv : intervals) {
            if (iv[0] >= lastEnd) {
                count++;
                lastEnd = iv[1];
            }
        }
        
        return intervals.size() - count;
    }
};