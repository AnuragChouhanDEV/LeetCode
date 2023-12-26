// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/?envType=daily-question&envId=2023-12-26

class Solution {
public:
#define MOD 1e9+7
    int helper(int n, int &k, int target, vector<vector<int>> &dp) {
        if (n == 0 && target == 0) 
            return dp[n][target]=1;
        if (n <= 0)
            return dp[n][target]=0;
        if (dp[n][target] != -1)
            return dp[n][target];
        int res = 0;
        for (int i = 1; i <= min(target,k); ++i) {
            res = (res+helper(n-1,k,target-i,dp))%1000000007;
        }
        return dp[n][target] = res;
    }
    int numRollsToTarget(int n, int k, int target) {
#if 0
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return helper(n,k,target,dp);
#endif
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0]=1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= min(i*k, target); j++) {
                for (int temp = 1; temp <= min(k, j); temp++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - temp]) % 1000000007;
                }
            }
        }
        return dp[n][target];
    }
};

/*
    0   0   0   0

*/