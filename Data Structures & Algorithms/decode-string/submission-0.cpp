class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> strStack;

        string curr = "";
        int num = 0;

        for(char ch : s) {
            // build number
            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            // opening bracket
            else if(ch == '[') {

                numStack.push(num);
                strStack.push(curr);

                num = 0;
                curr = "";
            }

            // closing bracket
            else if(ch == ']') {

                int times = numStack.top();
                numStack.pop();

                string prev = strStack.top();
                strStack.pop();

                string temp = "";

                for(int i = 0; i < times; i++) {
                    temp += curr;
                }

                curr = prev + temp;
            }

            // normal character
            else {

                curr += ch;
            }
        }

        return curr;
    }
};