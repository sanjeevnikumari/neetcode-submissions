class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) return 0;
    
        int ans = 0;
       for (int i = 0; i < 32; i++) {
            ans = (ans << 1);     // shift answer left
            ans |= (n & 1);       // add last bit of n
            n >>= 1;              // move to next bit
        }

        return ans;
    }
};