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
        
        int max1 = 0;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (open_braces(c)) {
                start++;
            } else if (close_braces(c)) {
                end++;
            }
            if (start == end) {
                max1 = max(start+end, max1);
            } else if (end > start){
                start = 0;
                end = 0;
            }
        }
        for (int i = s.size()-1; i >= 0; --i) {
            char c = s[i];
            if (open_braces(c)) {
                start++;
            } else if (close_braces(c)) {
                end++;
            }
            if (start == end) {
                max1 = max(start+end, max1);
            } else if (end < start) {
                start = 0;
                end = 0;
            }
        }
        return max1;
    }
};