// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case ')':
                    if (st.top() == '(')
                        st.pop();
                    continue;
                case '}':
                    if (st.top() == '{')
                        st.pop();
                    continue;
                case ']':
                    if (st.top() == '[')
                        st.pop();
                    continue;
                default:
                    break;
            }
            st.push(s[i]);
        }
        if (st.empty())
            return true;
        return false;
    }
};