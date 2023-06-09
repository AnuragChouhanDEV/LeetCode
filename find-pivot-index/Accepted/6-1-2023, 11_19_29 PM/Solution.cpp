// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_sum(nums.begin(), nums.end());
        int sum = 0;

        for (int i = n-2; i >= 0; --i) right_sum[i] = right_sum[i]+right_sum[i+1];
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == right_sum[i]) return i;
        }
        return -1;
    }
};