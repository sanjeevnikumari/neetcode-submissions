class Solution {
public:

    int getGCD(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    string gcdOfStrings(string str1, string str2) {

        // Step 1: check if pattern exists
        if (str1 + str2 != str2 + str1)
            return "";

        // Step 2: manual gcd of lengths
        int g = getGCD(str1.size(), str2.size());

        // Step 3: return prefix
        return str1.substr(0, g);
    }
};