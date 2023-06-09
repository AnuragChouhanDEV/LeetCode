// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for (int i = n-2; i>=0;--i) {
            int minn = INT_MAX;
            for (int j = i+1; j <= min(n-1, i+nums[i]); ++j) {
                minn = min(minn, dp[j]);
            }
            if (minn != INT_MAX)
                dp[i] = minn + 1;
        }
        return dp[0];
    }
};