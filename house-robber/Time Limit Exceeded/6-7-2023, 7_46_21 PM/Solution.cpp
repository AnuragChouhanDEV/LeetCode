// https://leetcode.com/problems/house-robber

class Solution {
public:
    int _rob(vector<int>& nums, int n) {
        if (n < 0) return 0;
        return max(_rob(nums, n-2)+nums[n], _rob(nums, n-1));
    }
    int rob(vector<int>& nums) {
        return _rob(nums, nums.size()-1);
    }
};