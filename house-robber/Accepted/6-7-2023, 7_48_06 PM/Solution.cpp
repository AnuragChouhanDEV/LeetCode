// https://leetcode.com/problems/house-robber

class Solution {
public:
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
};