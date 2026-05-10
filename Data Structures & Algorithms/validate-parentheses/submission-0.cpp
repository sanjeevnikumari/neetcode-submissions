class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            else {

                // stack empty means invalid
                if(st.empty())
                    return false;

                // matching check
                if(ch == ')' && st.top() != '(')
                    return false;

                if(ch == '}' && st.top() != '{')
                    return false;

                if(ch == ']' && st.top() != '[')
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};