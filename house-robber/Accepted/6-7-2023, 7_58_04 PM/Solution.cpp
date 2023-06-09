// https://leetcode.com/problems/house-robber

class Solution {
public:
#if 0
    int dp[101];
    int _rob(vector<int>& nums, int n) {
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = max(_rob(nums, n-2)+nums[n], _rob(nums, n-1));
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return _rob(nums, nums.size()-1);
    }
#else
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
#endif
};