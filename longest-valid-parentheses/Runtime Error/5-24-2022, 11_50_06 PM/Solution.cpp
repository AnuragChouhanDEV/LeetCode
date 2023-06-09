// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    bool open_braces(char c) {
        return c == '(';
    }
    bool close_braces(char c) {
        return c == ')';
    }
    void update(int &count, stack<char> &st) {
        if (st.top() == '(') {
            count += 2;
            st.pop();
        }
    }
    int longestValidParentheses(string s) {
        stack<char> st;
        int count = 0;
        for (char c:s) {
            if (open_braces(c)) {
                st.push(c);
            } else if (close_braces(c)){
                update(count, st);
            }
        }
        return count;
    }
};