// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        int sum = 0;
        int maxi;
        for (int i = n-1; i >= 0; --i) {
            maxi = arr[i];
            sum = 0;
            for (int j = i; j < min(n, i+k); ++j) {
                maxi = max(maxi, arr[j]);
                sum = max(sum, (j-i+1)*maxi + dp[j+1]);
            }
            dp[i] = sum;
        }
        return dp[0];
    }
#if 0
    int helper(vector<int>& arr, int k, int idx, vector<int> &dp) {
        int n = arr.size();
        if (idx == n) return 0;
        int maxi = INT_MIN;
        int sum = 0;
        if (dp[idx] != -1) return dp[idx];
        for (int i = idx; i < min(n, idx+k); ++i) {
            maxi = max(maxi, arr[i]);
            sum = max(sum, (i-idx+1)*maxi + helper(arr,k,i+1,dp));
        }
        return dp[idx]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return helper(arr, k, 0, dp);
    }
#endif
};
/*
1,4,1,5,7,3,6,1,9,9,3

1 7 7 7 7 9 9 9 9 9 9


6
12
20

28
15
21

12 27 21

*/