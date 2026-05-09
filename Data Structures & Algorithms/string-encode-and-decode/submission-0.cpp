class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encoded = "";
        
        for(string str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        
        return encoded;
    }

    
    vector<string> decode(string s) {
        
        vector<string> ans;
        
        int i = 0;
        
        while(i < s.size()) {
            
            int j = i;
            
            // find #
            while(s[j] != '#') {
                j++;
            }
            
            // extract length
            int len = stoi(s.substr(i, j-i));
            
            // move after #
            j++;
            
            // extract word
            string word = s.substr(j, len);
            
            ans.push_back(word);
            
            // move i to next encoded string
            i = j + len;
        }
        
        return ans;
    }
};