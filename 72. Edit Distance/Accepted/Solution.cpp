// https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
#if 1
    int minDistance(string word1, string word2) { 
    int m = word1.length();
    int n = word2.length();

    vector<int> dp(n + 1, 0);

    for (int j = 1; j <= n; ++j) {
        dp[j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        int prev = dp[0];
        dp[0] = i;

        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1+min(dp[j - 1], min(dp[j], prev));
            }
            prev = temp;
        }
    }

    return dp[n];
}
#endif
#if 0
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for (int i = 0; i <= n1; ++i) dp[i][0] = i;
        for (int j = 0; j <= n2; ++j) dp[0][j] = j;
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {                
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j-1], 
                                    min(dp[i-1][j], 
                                        dp[i-1][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
#endif
#if 0
    int helper(string word1, string word2, int l1, int l2, vector<vector<int>> &dp) {
        if (l1 < 0) return l2+1;
        if (l2 < 0) return l1+1;
        if (dp[l1][l2] != -1) return dp[l1][l2];
        if (word1[l1] == word2[l2]) {
            return dp[l1][l2] = helper(word1, word2, l1-1, l2-1, dp);
        } else {
            return dp[l1][l2] = 1+ min(helper(word1, word2, l1, l2-1, dp), min(helper(word1, word2, l1-1, l2, dp), helper(word1, word2, l1-1, l2-1, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size()-1;
        int n2 = word2.size()-1;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return helper(word1, word2, n1, n2, dp);
    }
#endif
};