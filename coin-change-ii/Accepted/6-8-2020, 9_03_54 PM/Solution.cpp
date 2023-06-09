// https://leetcode.com/problems/coin-change-ii

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        int sum = 1;
        if (len == 0 && amount == 0)
            return 1;
        if (len == 0)
            return 0;
        sort(coins.begin(),coins.end());
        vector<vector<int>> dp(len+1,vector<int>(amount+1));
        for (int i = 0; i <= len;++i) {
            for (int j = 0; j <= amount;++j ) {
                if (i == 0) {
                    dp[i][j] = 0;
                }
                if (j == 0) {
                    dp[i][j] = 1;
                }
                if (i > 0 && j > 0) {
                    if (j >= coins[i-1])
                        dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[len][amount];
        
    }
};