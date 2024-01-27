// https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27

class Solution {
public:
    int dp[1001][1001];
    int mod=1e9+7;
    long long f(int n, int k){
        if (k==0) return 1;
        if (k<0 || n<=0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        return dp[n][k]=(f(n-1, k)+f(n, k-1)-f(n-1, k-n)+mod)%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return f(n, k);
    }
};
/*
i = 3, j = 0, x = 0
        0   1   2   3   4
    0   1   1   1   1   1
    1   2   2   2   2   2
    2   3   5   7   9   11
    3   4   9   16  25  36
*/