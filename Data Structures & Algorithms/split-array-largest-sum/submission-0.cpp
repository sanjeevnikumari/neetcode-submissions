class Solution {
public:

    int countParts(vector<int>& nums, int limit) {

        int parts = 1;
        int sum = 0;

        for(int x : nums) {

            if(sum + x <= limit) {
                sum += x;
            }
            else {
                parts++;
                sum = x;
            }
        }

        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int x : nums) high += x;
        while(low < high) {

            int mid = (low + high) / 2;

            if(countParts(nums, mid) <= k) {
                high = mid;   // try smaller answer
            }
            else {
                low = mid + 1; // need bigger limit
            }
        }

        return low;
    }
};