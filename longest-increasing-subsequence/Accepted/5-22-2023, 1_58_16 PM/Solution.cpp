// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
#if 1
    int helper(vector<int>& nums, int n, int idx, int prev, vector<vector<int>>  &dp) {
        if (idx == n) return 0;
        if (dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int len = helper(nums, n, idx+1, prev, dp);
        if (prev == -1 || nums[idx] > nums[prev]) {
            len = max(len, 1+helper(nums, n, idx+1, idx, dp));
        }
        return dp[idx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        return helper(nums, nums.size(), 0, -1, dp);
    }
#else
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        
        for (int i = 1; i < nums.size();++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
#endif
};