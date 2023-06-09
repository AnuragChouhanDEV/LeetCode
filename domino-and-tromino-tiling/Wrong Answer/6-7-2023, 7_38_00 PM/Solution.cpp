// https://leetcode.com/problems/domino-and-tromino-tiling

class Solution {
public:
    int M = 100000007;
#if 0
    
    int dp[1001];
    int _numTilings(int n) {
        if (dp[n] != -1) return dp[n];
        if (n == 1 || n == 2) return n;
        if (n == 3) return 5;
        return dp[n] = ((2*_numTilings(n-1))%M + (_numTilings(n-3))%M) % M;
    }
    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));        
        return _numTilings(n);
    }
#else
    int numTilings(int n) {
        vector<int> dp(n+1, -1);
        if (n == 1) return n;
        if (n == 2) return n;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; ++i) {
            dp[i] = ((2*dp[i-1])%M + (dp[i-3])%M) % M;
        }
        return dp[n];
    }
#endif
};
