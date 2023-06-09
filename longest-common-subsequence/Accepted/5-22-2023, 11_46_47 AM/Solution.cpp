// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int lcs(string text1, string text2, int n, int m, vector<vector<int>> &dp) {
        if (n < 0 || m < 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (text1[n] == text2[m]) return dp[n][m]=1+lcs(text1, text2, n-1,m-1,dp);
        else return dp[n][m]=max(lcs(text1, text2, n-1,m,dp), lcs(text1, text2, n,m-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (n < 0 || m < 0) return 0;
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
        //return lcs(text1, text2, text1.size()-1, text2.size()-1, dp);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i-1] == text2[j-1]) 
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};