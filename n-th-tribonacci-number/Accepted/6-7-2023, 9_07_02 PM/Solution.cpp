// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
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
};