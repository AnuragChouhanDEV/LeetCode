// https://leetcode.com/problems/knight-dialer/description/?envType=daily-question&envId=2023-11-27

class Solution {
public:
    
    int knightDialer(int n) {
        if (n == 1) return 10;
        //if (n == 2) return 20;
        int M = 1000000007;
        vector<int> dp(10,1);
        for (int i = 2; i <= n; ++i) {
            vector<int> dp_old;
            dp_old = dp;
                       
            dp[0] = (dp_old[4] + dp_old[6])%M;
            dp[1] = (dp_old[8] + dp_old[6])%M;
            dp[2] = (dp_old[7] + dp_old[9])%M;
            dp[3] = (dp_old[4] + dp_old[8])%M;
            dp[4] = ((dp_old[3] + dp_old[9])%M + dp_old[0])%M;
            dp[5] = 0;
            dp[6] = ((dp_old[0] + dp_old[1])%M + dp_old[7])%M;
            dp[7] = (dp_old[2] + dp_old[6])%M;
            dp[8] = (dp_old[1] + dp_old[3])%M;
            dp[9] = (dp_old[4] + dp_old[2])%M;
        }
        int ans = 0;
        for (auto it:dp)
            ans = (ans + it) % M;
        return ans;
    }
};
/*
2 2 2 2 3 2 3 2 2 2
*/