// https://leetcode.com/problems/word-break/description/

class Solution {
public:
#if 1
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1; // Empty string is always valid

    for (int i = n - 1; i >= 0; --i) {
        string temp = "";
        for (int j = i; j < n; ++j) {
            temp += s[j];
            if (wordSet.find(temp) != wordSet.end() && dp[j + 1]) {
                dp[i] = 1;
                break;
            }
        }
    }

    return dp[0];
}
#endif
#if 0
    bool helper(string s, unordered_set<string> st, int idx, vector<int> &dp) {
        if (idx >= s.size()) return 1;
        if (dp[idx] != -1) return dp[idx];
        string temp = "";
        for (int i = idx; i < s.size(); ++i) {
            temp += s[i];
            if (st.find(temp) != st.end()) {
                if (helper(s,st,i+1,dp))
                    return dp[idx] = 1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> st;
        for(auto it:wordDict)
            st.insert(it);
        return helper(s, st, 0, dp);
    }
#endif
};