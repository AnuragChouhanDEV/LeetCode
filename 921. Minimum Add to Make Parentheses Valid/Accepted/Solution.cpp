// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int res = 0;
        for (auto c:s) {
            if (!st.empty() && c == ')') {
                st.pop();
                continue;
            }
            if (c == '(')
                st.push('(');
            else 
                res++;
        }
        res += st.size();
        return res;
    }
};
/*
(()))))((
    )))
*/