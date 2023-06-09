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
        vector<int> dp(s.size(),0);
        int max1 = 0;
        for (int i = 1; i < s.size(); ++i) {
            char c = s[i];
            if (close_braces(c)) {
                if (open_braces(s[i-1])) {
                    dp[i] = ((i >= 2) ? dp[i-2] : 0) + 2;
                } else if (i - dp[i-1] && open_braces(i - dp[i-1]-1)) {
                    dp[i] = dp[i-1] + ((i-dp[i-1] >= 2) ? dp[i-dp[i-1]-2] : 0) + 2;
                }
                max1 = max(max1, dp[i]);
            }
        }
        return max1;
    }
};