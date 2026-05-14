class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            int count = 0;

            // check all 32 bits (safe for int)
            for (int bit = 0; bit < 32; bit++) {
                if (((i >> bit) & 1) == 1) {
                    count++;
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};