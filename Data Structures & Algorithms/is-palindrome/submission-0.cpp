class Solution {
public:
    bool isPalindrome(string s) {
        
        string word = "";
        
        // keep only alphanumeric chars
        for(char ch : s) {
            
            if(isalnum(ch)) {
                word += tolower(ch);
            }
        }
        
        int i = 0;
        int j = word.size() - 1;
        
        while(i < j) {
            
            if(word[i] != word[j]) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};