// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
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
};