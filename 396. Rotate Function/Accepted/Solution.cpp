// https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int maxi = INT_MIN;
        int sum = 0;
        int val = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            val += i*nums[i];
        }
        vector<int> dp(n);
        maxi = dp[0] = val;
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + sum - n*nums[n-i];
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
/*
https://leetcode.com/problems/rotate-function/solutions/1243652/dp-code-explained-in-detail-o-n-time-o-n-space
*/