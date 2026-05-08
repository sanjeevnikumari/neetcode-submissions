class Solution {
public:

    int getNext(int n) {
        int sum = 0;
        while(n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        
        unordered_set<int> st;
        
        while(n != 1) {
            
            if(st.count(n)) return false; // cycle detected
            
            st.insert(n);
            n = getNext(n);
        }
        
        return true;
    }
};