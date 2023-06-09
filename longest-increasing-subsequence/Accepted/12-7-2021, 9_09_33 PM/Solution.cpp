// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        vector<int> dp(nums.size(), 1);
        int maxi = INT_MIN;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    //cout << dp[i] << " " << dp[j]+1 << endl;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};