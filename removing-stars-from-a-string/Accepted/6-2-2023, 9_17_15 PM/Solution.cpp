// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {
        string res = "";
        stack<char> st;
        for (int i = 0; i < s.size();++i) {
            if (s[i] == '*' && !st.empty())
                st.pop();
            else
                st.push(s[i]);
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res.size() ? res:"";
    }
};