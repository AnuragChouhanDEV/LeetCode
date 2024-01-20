// https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int length = arr.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;
        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        ll sum = 0;
        for (int i = 0; i < length; ++i) {
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * arr[i] % MOD;
            sum %= MOD;
        }
        return sum;
    }
#if 0
    // memory limit exceeded
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1000000007;
        vector<vector<int>> dp(n,vector<int> (n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = arr[i]%mod;
            sum = (sum + dp[i][i])%mod;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                dp[i][j] = min(dp[i-1][j]%mod, dp[i][j+1]%mod);
                sum = (sum + dp[i][j])%mod;
            }
        }
        return sum;
    }
#endif
};

/*
        3  1  2  4
    3   3  1  1  1
    1      1  1  1
    2         2  2
    4            4


        11  81  94  43  3
    11  11  11  11  11  3
    81      81  81  43  3
    94          94  43  3
    43              43  3
     3                  3
i=1
j=i-1
        00  10  20  30  40
            11  21  31  41
                22  32  42
                    33  43
                        44
        write a efficient loop in c++ to traverse (1,0) (2,1) (3,2) (4,3) (2,0) (3,1) (4,2) (3,0) (4,0)
*/