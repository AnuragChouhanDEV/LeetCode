// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
#if 0
    int dp[38];
    int _t(int n) {
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = _t(n-1)+_t(n-2)+_t(n-3);
    }
    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));
        return _t(n);
    }
#else
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        if (n == 0 || n == 1) return n;
        if (n == 2) return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
#endif
};