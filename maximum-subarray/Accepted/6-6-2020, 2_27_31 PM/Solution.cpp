// https://leetcode.com/problems/maximum-subarray

class Solution {
    int max_(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> max_sum;
        int max = nums[0];
        max_sum.push_back(nums[0]);
        for (int i = 1; i < nums.size();++i) {
            max_sum.push_back(max_(nums[i],nums[i]+max_sum.back()));
            max = max_(max_sum[i], max);
            cout << max <<" " << max_sum[i] << endl;
        }
        return max;
    }
};