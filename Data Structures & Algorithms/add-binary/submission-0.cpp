class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // add last bit of a
            if (i >= 0) {
                sum += (a[i] - '0');
                i--;
            }

            // add last bit of b
            if (j >= 0) {
                sum += (b[j] - '0');
                j--;
            }

            // current bit
            ans.push_back((sum % 2) + '0');

            // update carry
            carry = sum / 2;
        }
    
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};