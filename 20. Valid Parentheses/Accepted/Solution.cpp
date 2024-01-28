// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '}') {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
                continue;
            }
            if (ch == ']') {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
                continue;
            }
            if (ch == ')') {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
                continue;
            }
            st.push(ch);
        }
        return st.empty();
    }
};