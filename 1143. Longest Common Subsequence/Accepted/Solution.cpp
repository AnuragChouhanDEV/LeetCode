// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();

    vector<int> dp(n2 + 1, 0);

    for (int i = 1; i <= n1; ++i) {
        int prev = 0; // Store the value of dp[j-1] before it's updated
        for (int j = 1; j <= n2; ++j) {
            int temp = dp[j]; // Store the value of dp[j] before it's updated
            if (text1[i - 1] == text2[j - 1]) {
                dp[j] = 1 + prev; // Use the value of dp[j-1] from the previous iteration
            } else {
                dp[j] = max(dp[j], dp[j-1]);
            }
            prev = temp; // Update prev for the next iteration
        }
    }
    return dp[n2];
}
#if 0
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<int> dp(n2+1, 0);
        vector<int> cur(n2+1,0);
        for (int i = 1; i < n1+1; ++i) {
            for (int j = 1; j < n2+1; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    cur[j] = 1+ dp[j-1];
                } else {
                    cur[j] = max(dp[j], cur[j-1]);
                }
            }
            dp=cur;
        }
        return dp[n2];
    }
#endif
#if 0
    int helper(string t1, string t2, int n1, int n2, vector<vector<int>> &dp) {
        if (n1 < 0 || n2 < 0)
            return 0;
        if (dp[n1][n2] != INT_MIN) return dp[n1][n2];
        if (t1[n1] == t2[n2]) {
            return dp[n1][n2] = max(dp[n1][n2], 1 + helper(t1, t2, n1-1, n2-1, dp));
        } else {
            return dp[n1][n2] = max(dp[n1][n2], max(helper(t1, t2, n1, n2-1, dp), helper(t1, t2, n1-1, n2, dp)));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, INT_MIN));
        int res = helper(text1, text2, n1-1, n2-1, dp);
        return res == INT_MIN ? 0: res;
    }
#endif
#if 0
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
        for (int i = 1; i < n1+1; ++i) {
            for (int j = 1; j < n2+1; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1+ dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
#endif
};
/*           a   b   c   d   e
         0   1   2   3   4   5
     0   0   0   0   0   0   0
a    1   0   1   1   1   1   1
c    2   0   1   1   2   2   2
e    3   0   1   1   1   1   3

*/