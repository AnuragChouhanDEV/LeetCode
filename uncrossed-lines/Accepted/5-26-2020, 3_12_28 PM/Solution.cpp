// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int a_len = A.size();
        int b_len = B.size();
        if (a_len == 0 || b_len == 0)
            return 0;
        vector<vector<int>> dp(a_len+1,vector<int> (b_len+1));
        
        for (int i = 0;i <= a_len; ++i) {
            for(int j = 0; j <= b_len; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (A[i-1] == B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[a_len][b_len];
    }
};