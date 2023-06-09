// https://leetcode.com/problems/target-sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto x:nums)
            sum += x;
        sum = (target + sum)/2;
        vector<vector<int>> res(nums.size()+1, vector<int>(sum+1, 0));
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (nums[i-1] <= j) {
                    res[i][j] = 1 + max(res[i-1][j], res[i-1][j-nums[i-1]]);
                } else {
                    res[i][j] = res[i-1][j];
                }
            }
        }
        return res[nums.size()][sum];
    }
};