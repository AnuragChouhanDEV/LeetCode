// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        for (int i = 0; i <= coins.size(); ++i) {
            for (int j = 0; j <= amount; ++j) {
                if (i == 0) dp[i][j] = 1e5;
                else if (j == 0) dp[i][j] = 0;
                else if (coins[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);                
            }
        }
        return dp[coins.size()][amount] > 1e4 ? -1 : dp[coins.size()][amount];
    }
};