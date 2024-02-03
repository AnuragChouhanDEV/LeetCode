// https://leetcode.com/problems/coin-change/description/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,0); 
        vector<int> cur(amount+1, 0);
        for (int amt = 0; amt <= amount; ++amt) {
            if (amt % coins[0] == 0)
                dp[amt]=amt/coins[0];
            else 
                dp[amt]=1e9;
        }
        for (int idx = 1; idx < n; ++idx) {
            for (int amt = 0; amt <= amount; ++amt) {
                int not_to_pick = 0 + dp[amt];
                int pick = INT_MAX;
                if (coins[idx] <= amt) { 
                    pick = 1 + cur[amt-coins[idx]];
                }
                cur[amt]=min(pick, not_to_pick);
            }
            dp=cur;
        }
        return dp[amount] >= 1e9 ? -1:dp[amount];
    }
#if 0
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for (int amt = 0; amt <= amount; ++amt) {
            if (amt % coins[0] == 0)
                dp[0][amt]=amt/coins[0];
            else 
                dp[0][amt]=1e9;
        }
        for (int idx = 1; idx < n; ++idx) {
            for (int amt = 0; amt <= amount; ++amt) {
                int not_to_pick = 0 + dp[idx-1][amt];
                int pick = INT_MAX;
                if (coins[idx] <= amt) { 
                    pick = 1 + dp[idx][amt-coins[idx]];
                }
                dp[idx][amt]=min(pick, not_to_pick);
            }
        }
        return dp[n-1][amount] >= 1e9 ? -1:dp[n-1][amount];
    }
#endif
#if 0
    int helper(vector<int>& coins, int idx, int amount, vector<vector<int>> &dp) {
        if (idx == 0) {
            if (amount % coins[idx] == 0)
                return dp[idx][amount]=amount/coins[idx];
            return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int not_to_pick = 0 + helper(coins, idx-1, amount, dp);
        int pick = INT_MAX;
        if (coins[idx] <= amount) { 
            pick = 1 + helper(coins, idx, amount-coins[idx], dp);
        }
        return dp[idx][amount]=min(pick, not_to_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int res = helper(coins, coins.size()-1, amount, dp);
        return res >= 1e9 ? -1:res;
    }
#endif
};