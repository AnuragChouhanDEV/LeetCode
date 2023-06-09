// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    
    int climbStairs(int n) {
        static vector<int> dp(47, -1);
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};