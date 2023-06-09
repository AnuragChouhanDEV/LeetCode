// https://leetcode.com/problems/word-break

class Solution {
public:
    int helper(int idx, string s, set<string>& st, vector<int> &dp) {
        if (idx == s.size()) return 1;
        if (dp[idx] != -1) return dp[idx];
        string temp = "";
        for (int i = idx; i < s.size(); ++i) {
            temp += s[i];
            //cout << "char is " << temp << endl;
            if (st.find(temp) != st.end()) {
                //cout << "string is " << temp << endl;
                if (helper(i+1,s,st,dp))
                    return dp[idx] = 1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int> dp(301,-1);
        for (auto x:wordDict) st.insert(x);
        return helper(0,s,st,dp);
    }
};