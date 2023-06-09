// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
#if 0
    int dp[1002];
    int _mcs(vector<int>& cost, int n) {
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = min(_mcs(cost,n-1) + cost[n], _mcs(cost,n-2) + cost[n-1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        memset(dp, -1, sizeof(dp));
        return _mcs(cost, n);
    }
#else
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        if (n == 1) return cost[0];
        if (n == 2) return min(cost[0], cost[1]);
        if (n == 3) return min(cost[0]+cost[2], cost[1]);
        dp[0] = cost[0];
        dp[1] = min(cost[0], cost[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i-1]);
        }
        return dp[n-1];
    }
#endif
};