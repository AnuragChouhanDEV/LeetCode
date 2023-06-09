// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    bool open_braces(char c) {
        return c == '(';
    }
    bool close_braces(char c) {
        return c == ')';
    }
    int longestValidParentheses(string s) {
        stack<int> st;
        int max1 = 0;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (open_braces(s[i])) {
                st.push(i);
            } else if (close_braces(s[i])){
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    max1 = max(i - st.top(), max1);
                }
            }
        }
        return max1;
    }
};