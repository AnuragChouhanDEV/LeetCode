// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum(nums.begin(), nums.end());
        int sum = 0;

        for (int i = 1; i < n; ++i) left_sum[i] = left_sum[i]+left_sum[i-1];
        for (int i = n-1; i >= 0; --i) {
            sum += nums[i];
            if (sum == left_sum[i]) return i;
        }
        return -1;
    }
};