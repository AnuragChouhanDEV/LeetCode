// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int helper(vector<int>& nums, int n, int idx, int prev, vector<vector<int>> &dp) {
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
        //return dp[nums.size()-1][nums.size()]
    }
};