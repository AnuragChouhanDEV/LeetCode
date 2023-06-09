// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
#if 0
    int climbStairs(int n) {
        static vector<int> dp(47, -1);
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
#else
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i-1]+dp[i-2];
        return dp[n];
    }
#endif
};